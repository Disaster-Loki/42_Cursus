FROM debian:bullseye

# Atualiza a lista de pacotes e instala o nginx e o pacote ssl-cert
RUN apt-get update && apt-get install -y nginx ssl-cert

# Gerar ou garantir que o certificado SSL esteja presente
RUN update-rc.d nginx enable
RUN service nginx start

# Criar a configuração SSL
RUN echo "server {" > /etc/nginx/sites-available/default && \
    echo "    listen 443 ssl;" >> /etc/nginx/sites-available/default && \
    echo "    server_name localhost;" >> /etc/nginx/sites-available/default && \
    echo "    ssl_certificate /etc/ssl/certs/ssl-cert-snakeoil.pem;" >> /etc/nginx/sites-available/default && \
    echo "    ssl_certificate_key /etc/ssl/private/ssl-cert-snakeoil.key;" >> /etc/nginx/sites-available/default && \
    echo "    ssl_protocols TLSv1.2 TLSv1.3;" >> /etc/nginx/sites-available/default && \
    echo "    ssl_ciphers 'TLS_AES_128_GCM_SHA256:TLS_AES_256_GCM_SHA384:ECDHE-RSA-AES128-GCM-SHA256:ECDHE-RSA-AES256-GCM-SHA384';" >> /etc/nginx/sites-available/default && \
    echo "    ssl_prefer_server_ciphers on;" >> /etc/nginx/sites-available/default && \
    echo "    location / {" >> /etc/nginx/sites-available/default && \
    echo "        root /var/www/html;" >> /etc/nginx/sites-available/default && \
    echo "        index index.html;" >> /etc/nginx/sites-available/default && \
    echo "    }" >> /etc/nginx/sites-available/default && \
    echo "}" >> /etc/nginx/sites-available/default

# Expor a porta 443 (HTTPS)
EXPOSE 443

# Definir o comando para rodar o Nginx no primeiro plano
CMD ["nginx", "-g", "daemon off;"]

