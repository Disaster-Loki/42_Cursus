# Base image
FROM debian:bullseye

# Update packages
RUN apt-get update

# Install MariaDB server and client
RUN apt-get install -y mariadb-server mariadb-client && \
    apt-get clean && rm -rf /var/lib/apt/lists/*

# Create a non-root user and group for MariaDB
RUN getent group mysql || groupadd -g 999 mysql && \
    id mysql || useradd -r -u 999 -g mysql -s /bin/false mysql

# Create necessary directories and set permissions
RUN mkdir -p /run/mysqld /var/lib/mysql && \
    chown -R mysql:mysql /run/mysqld /var/lib/mysql

# Copy custom configuration file
COPY conf/mariadb.cnf /etc/mysql/mariadb.conf.d/99-custom.cnf

# Copy entrypoint script
COPY conf/entrypoint.sh /usr/local/bin/
RUN chmod +x /usr/local/bin/entrypoint.sh

EXPOSE 3306

# Start MariaDB server with custom entrypoint script
ENTRYPOINT ["/usr/local/bin/entrypoint.sh"]
