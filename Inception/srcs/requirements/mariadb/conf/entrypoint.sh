#!/bin/bash
set -e

# Initialize the database directory if it does not exist
if [ ! -d /var/lib/mysql/mysql ]; then
  echo "Initializing database..."
  mysql_install_db --user=mysql --basedir=/usr --datadir=/var/lib/mysql > /dev/null

  # Start MariaDB in safe mode without networking
  mysqld_safe --skip-networking &

  echo "Setting root password and creating database/user..."
  mysql -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '${MARIADB_ROOT_PASSWORD}';"
  mysql -uroot -p${MARIADB_ROOT_PASSWORD} -e "FLUSH PRIVILEGES;"
  mysql -uroot -p${MARIADB_ROOT_PASSWORD} -e "CREATE DATABASE IF NOT EXISTS \`${MARIADB_DATABASE}\`;"
  mysql -uroot -p${MARIADB_ROOT_PASSWORD} -e "CREATE USER IF NOT EXISTS '${MARIADB_USER}'@'%' IDENTIFIED BY '${MARIADB_PASSWORD}';"
  mysql -uroot -p${MARIADB_ROOT_PASSWORD} -e "GRANT ALL PRIVILEGES ON \`${MARIADB_DATABASE}\`.* TO '${MARIADB_USER}'@'%';"
  mysql -uroot -p${MARIADB_ROOT_PASSWORD} -e "FLUSH PRIVILEGES;"

  # Stop the background MariaDB process
  killall mysqld
fi

# Execute default command (mysqld)
exec "$@"
