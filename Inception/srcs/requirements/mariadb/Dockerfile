FROM debian:bullseye

# Install required packages and MariaDB server
RUN apt-get update && \
    apt-get install -y mariadb-server && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

# Create required directory for the MariaDB socket
RUN mkdir -p /run/mysqld && chown -R mysql:mysql /run/mysqld

# Copy custom MariaDB config (optional)
COPY conf/mariadb.cnf /etc/mysql/mariadb.conf.d/99-custom.cnf

# Copy entrypoint script
COPY conf/entrypoint.sh /usr/local/bin/
RUN chmod +x /usr/local/bin/entrypoint.sh

EXPOSE 3306
# entrypoint creating root
ENTRYPOINT ["entrypoint.sh"]
CMD ["mysqld"]
