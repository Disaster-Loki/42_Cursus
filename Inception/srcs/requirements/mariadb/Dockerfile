FROM debian:bullseye

# Variáveis de ambiente
ENV DEBIAN_FRONTEND=noninteractive \
    MARIADB_ROOT_PASSWORD=rootpass \
    MARIADB_DATABASE=mydb \
    MARIADB_USER=user \
    MARIADB_PASSWORD=userpass

# Instala dependências e o servidor MariaDB
RUN apt-get update && \
    apt-get install -y mariadb-server && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

# Copia arquivo de configuração personalizado (opcional)
COPY conf/mariadb.cnf /etc/mysql/mariadb.conf.d/99-custom.cnf

# Inicializa o banco de dados e cria usuários no primeiro run
COPY docker-entrypoint.sh /usr/local/bin/
RUN chmod +x /usr/local/bin/docker-entrypoint.sh

EXPOSE 3306

ENTRYPOINT ["docker-entrypoint.sh"]
CMD ["mysqld"]
