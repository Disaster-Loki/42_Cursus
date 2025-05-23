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

# Download and install WordPress
RUN mkdir -p /srv/www && \
    curl -o /tmp/wordpress.tar.gz https://wordpress.org/latest.tar.gz && \
    tar -xzf /tmp/wordpress.tar.gz -C /srv/www && \
    chown -R www-data:www-data /srv/www/wordpress && \
    rm /tmp/wordpress.tar.gz

# Copy Apache configuration file
COPY conf/wordpress.conf /etc/apache2/sites-available/wordpress.conf

# Enable site and configurations
RUN a2ensite wordpress && \
    a2enmod rewrite && \
    a2dissite 000-default

# Expose Apache's default port
EXPOSE 80

# Start Apache in the foreground
CMD ["apachectl", "-D", "FOREGROUND"]
