#!/bin/bash
set -e

# Carrega variáveis sensíveis dos arquivos de secrets, se existirem
if [ -f "$MARIADB_ROOT_PASSWORD_FILE" ]; then
  export MARIADB_ROOT_PASSWORD=$(cat "$MARIADB_ROOT_PASSWORD_FILE")
fi
if [ -f "$MARIADB_PASSWORD_FILE" ]; then
  export WORDPRESS_DB_PASSWORD=$(cat "$MARIADB_PASSWORD_FILE")
fi

echo ">> Entering entrypoint.sh"

# Adjust permissions for MySQL directories
chown -R mysql:mysql /run/mysqld /var/lib/mysql

DB_INITIALIZED_FLAG="/var/lib/mysql/.db_initialized"
INIT_SQL_FILE="/tmp/init_mariadb.sql" # Keeping /tmp for now, as it worked directly.

# Check if database has already been initialized
if [ ! -f "$DB_INITIALIZED_FLAG" ]; then
    echo "Initializing database..."
    mysql_install_db --user=mysql --basedir=/usr --datadir=/var/lib/mysql > /dev/null

    echo ">> Generating temporary initialization script..."
    # IMPORTANT: No leading whitespace on the SQL lines below this point!
    cat <<EOF > "$INIT_SQL_FILE"
USE mysql;
ALTER USER 'root'@'localhost' IDENTIFIED BY '${MARIADB_ROOT_PASSWORD}';
CREATE DATABASE IF NOT EXISTS ${MARIADB_DATABASE};
CREATE USER IF NOT EXISTS '${WORDPRESS_DB_USER}'@'%' IDENTIFIED BY '${WORDPRESS_DB_PASSWORD}';
GRANT ALL PRIVILEGES ON ${WORDPRESS_DB_NAME}.* TO '${WORDPRESS_DB_USER}'@'%';
FLUSH PRIVILEGES;
EOF

    # Ensure the temporary file is readable by the 'mysql' user
    chown mysql:mysql "$INIT_SQL_FILE"
    chmod 600 "$INIT_SQL_FILE"

    # Create the initialization flag before starting mysqld with --init-file
    touch "$DB_INITIALIZED_FLAG"

    echo ">> Starting mysqld with --init-file for initial configuration..."
    exec mysqld --user=mysql --init-file="$INIT_SQL_FILE"

else
    echo ">> Database already initialized and configured."
    # Remove the temporary SQL file if the database is already initialized
    rm -f "$INIT_SQL_FILE"
fi

echo ">> Initialization complete. Starting mysqld..."
exec mysqld --user=mysql