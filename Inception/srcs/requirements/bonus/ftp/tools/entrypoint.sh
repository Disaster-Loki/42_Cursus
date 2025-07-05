#!/bin/bash

# Read FTP credentials
FTP_USER=${FTP_USER:-ftpuser}
FTP_PASSWORD=$(cat /run/secrets/ftp_password.txt)

# Create user and set password
useradd -m "$FTP_USER"
echo "$FTP_USER:$FTP_PASSWORD" | chpasswd

# Create upload directory and assign permissions
mkdir -p /var/www/html/uploads
chown -R "$FTP_USER:$FTP_USER" /var/www/html/uploads

# Launch vsftpd in foreground (required by 42 project)
exec vsftpd /etc/vsftpd.conf
