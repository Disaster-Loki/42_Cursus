#!/bin/bash

cd /srv/www/wordpress || exit

if ! wp core is-installed --allow-root; then
    wp core install \
      --url="${DOMAIN_NAME}" \
      --title="${TITLE}" \
      --admin_user="${WP_USER}" \
      --admin_password="$(cat "$WP_USER_PASSWORD")" \
      --admin_email="${WP_USER_EMAIL}" \
      --skip-email \
      --allow-root

    wp user create "${WP_USER2}" "${WP_USER2_EMAIL}" \
      --user_pass="$(cat "$WP_USER2_PASSWORD")" \
      --role=subscriber \
      --allow-root
fi

exec apachectl -D FOREGROUND
