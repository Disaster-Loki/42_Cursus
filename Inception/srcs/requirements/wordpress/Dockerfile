# Base Image
FROM debian:bullseye

# Update packages and install dependencies
RUN apt-get update && apt-get install -y \
    curl \
    apache2 \
    ghostscript \
    libapache2-mod-php \
    php \
    php-bcmath \
    php-curl \
    php-imagick \
    php-intl \
    php-json \
    php-mbstring \
    php-mysql \
    php-xml \
    php-zip \
    && apt-get clean

# Create folder for WordPress
RUN mkdir -p /srv/www

# Download and install WordPress
RUN curl -o /tmp/wordpress.tar.gz https://wordpress.org/latest.tar.gz && \
    tar -xzf /tmp/wordpress.tar.gz -C /srv/www && \
    rm /tmp/wordpress.tar.gz

# Copy custom wp-config.php
COPY conf/wp-config.php /srv/www/wordpress/wp-config.php

# Install WP-CLI
RUN curl -o /usr/local/bin/wp https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
    chmod +x /usr/local/bin/wp

# Set permissions for WordPress directory
RUN chown -R www-data:www-data /srv/www/wordpress

# Copy Apache configuration file
COPY conf/wordpress.conf /etc/apache2/sites-available/wordpress.conf

# Enable site and Apache modules
RUN a2ensite wordpress && \
    a2enmod rewrite && \
    a2dissite 000-default

# Set global ServerName to suppress Apache warning
RUN echo 'ServerName localhost' > /etc/apache2/conf-available/servername.conf && a2enconf servername

# Copy entrypoint script and make it executable
COPY tools/entrypoint.sh /usr/local/bin/entrypoint.sh
RUN chmod +x /usr/local/bin/entrypoint.sh

# Expose Apache's port
EXPOSE 9000

# Use custom entrypoint script to start container
ENTRYPOINT ["/usr/local/bin/entrypoint.sh"]