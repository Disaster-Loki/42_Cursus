FROM debian:bullseye

# Install Nginx and OpenSSL
RUN apt-get update && apt-get install -y nginx openssl

# Create the certificate SSL using OpenSSL
RUN mkdir -p /etc/ssl/private /etc/ssl/certs && \
    openssl req -new -newkey rsa:2048 -days 365 -nodes -x509 \
    -keyout /etc/ssl/private/ssl-cert-snakeoil.key \
    -out /etc/ssl/certs/ssl-cert-snakeoil.pem \
    -subj "/C=US/ST=State/L=City/O=Organization/OU=Unit/CN=localhost"

# Copy the Nginx configuration to the appropriate directory
COPY conf/nginx.conf /etc/nginx/sites-available/default

# Enable Nginx to start automatically
RUN update-rc.d nginx enable
RUN service nginx start

EXPOSE 443

CMD ["nginx", "-g", "daemon off;"]
