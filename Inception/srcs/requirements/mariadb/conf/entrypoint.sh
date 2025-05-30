#!/bin/sh
set -e

DATADIR="/var/lib/mysql"

# 1. Initialize database if it doesn't exist
if [ ! -d "$DATADIR/mysql" ]; then
  echo "[MariaDB] Initializing database..."
  mariadb-install-db --user=mysql --datadir="$DATADIR" > /dev/null
fi

# 2. Start mysqld in the background
mysqld --user=mysql &

# 3. Wait for mysqld to be ready to accept connections
echo "[MariaDB] Waiting for server to be ready..."
timeout=30
until mysqladmin ping --silent; do
  timeout=$((timeout - 1))
  if [ $timeout -le 0 ]; then
    echo "[MariaDB] Server did not respond in time."
    exit 1
  fi
done

# 4. Run initial SQL setup if first time
if [ ! -f "$DATADIR/.initialized" ]; then
  echo "[MariaDB] Running initial SQL setup..."

  mysql -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '${MARIADB_ROOT_PASSWORD}';"
  mysql -e "CREATE DATABASE IF NOT EXISTS \`${MARIADB_DATABASE}\` CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci;"
  mysql -e "CREATE USER IF NOT EXISTS '${MARIADB_USER}'@'%' IDENTIFIED BY '${MARIADB_PASSWORD}';"
  mysql -e "GRANT ALL PRIVILEGES ON \`${MARIADB_DATABASE}\`.* TO '${MARIADB_USER}'@'%';"
  mysql -e "FLUSH PRIVILEGES;"

  touch "$DATADIR/.initialized"
fi

# 5. Stop background mysqld and run it in foreground
kill %1
wait %1 2>/dev/null || true

exec mysqld --user=mysql
