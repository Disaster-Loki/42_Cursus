FROM debian:bullseye

# Install required dependencies and MariaDB server
RUN apt-get update && \
    apt-get install -y mariadb-server && \
    apt-get clean && \
    rm -rf /var/lib/apt/lists/*

# Create the mysql user only if it does not already exist
RUN id mysql || useradd -r -u 999 -g mysql -s /bin/false mysql

# Create necessary directories and set proper ownership
RUN mkdir -p /run/mysqld && \
    mkdir -p /var/lib/mysql && \
    chown -R mysql:mysql /run/mysqld /var/lib/mysql

# Copy custom MariaDB configuration and entrypoint script
COPY conf/mariadb.cnf /etc/mysql/mariadb.conf.d/99-custom.cnf
COPY conf/entrypoint.sh /usr/local/bin/
RUN chmod +x /usr/local/bin/entrypoint.sh

# Expose the default MariaDB port
EXPOSE 3306

# Set the entrypoint script (initializes the DB if needed)
ENTRYPOINT ["entrypoint.sh"]

# Default command to run the MariaDB server
CMD ["mysqld"]
