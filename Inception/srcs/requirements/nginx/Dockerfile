FROM debian:bullseye

# Instalar Nginx e OpenSSL
RUN apt-get update && apt-get install -y nginx openssl

# Criar os certificados SSL usando OpenSSL
RUN mkdir -p /etc/ssl/private /etc/ssl/certs && \
    openssl req -new -newkey rsa:2048 -days 365 -nodes -x509 \
    -keyout /etc/ssl/private/ssl-cert-snakeoil.key \
    -out /etc/ssl/certs/ssl-cert-snakeoil.pem \
    -subj "/C=US/ST=State/L=City/O=Organization/OU=Unit/CN=localhost"

# Copiar a configuração do Nginx para o diretório adequado
COPY conf/nginx.conf /etc/nginx/sites-available/default

# Ativar o Nginx para iniciar automaticamente
RUN update-rc.d nginx enable
RUN service nginx start

EXPOSE 443

CMD ["nginx", "-g", "daemon off;"]
