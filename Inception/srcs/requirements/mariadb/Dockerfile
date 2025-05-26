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

# Copy init script
COPY conf/init.sh /usr/local/bin/
RUN chmod +x /usr/local/bin/init.sh

EXPOSE 3306
# Init creating root
ENTRYPOINT ["init.sh"]
CMD ["mysqld"]
