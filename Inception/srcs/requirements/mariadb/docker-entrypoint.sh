#!/bin/bash
set -e

# Inicializa o diretório do banco, se necessário
if [ ! -d /var/lib/mysql/mysql ]; then
  echo "Inicializando banco de dados..."
  mysql_install_db --user=mysql --basedir=/usr --datadir=/var/lib/mysql > /dev/null

  mysqld_safe --skip-networking &
  sleep 5

  echo "Configurando root e criando database/usuário..."
  mysql -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '${MARIADB_ROOT_PASSWORD}';"
  mysql -uroot -p${MARIADB_ROOT_PASSWORD} -e "FLUSH PRIVILEGES;"
  mysql -uroot -p${MARIADB_ROOT_PASSWORD} -e "CREATE DATABASE IF NOT EXISTS \`${MARIADB_DATABASE}\`;"
  mysql -uroot -p${MARIADB_ROOT_PASSWORD} -e "CREATE USER IF NOT EXISTS '${MARIADB_USER}'@'%' IDENTIFIED BY '${MARIADB_PASSWORD}';"
  mysql -uroot -p${MARIADB_ROOT_PASSWORD} -e "GRANT ALL PRIVILEGES ON \`${MARIADB_DATABASE}\`.* TO '${MARIADB_USER}'@'%';"
  mysql -uroot -p${MARIADB_ROOT_PASSWORD} -e "FLUSH PRIVILEGES;"

  killall mysqld
  sleep 2
fi

# Executa o comando padrão
exec "$@"
