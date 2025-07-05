#!/bin/sh
set -eux

echo ">>> Debug runtime: /usr/local/bin/portainer"
ls -l /usr/local/bin/portainer
file /usr/local/bin/portainer || true

echo ">>> Verificando conteúdo de /usr/local/bin:"
ls -1 /usr/local/bin | sed 's/^/    /'

echo ">>> Tentando executar portainer:"
exec /usr/local/bin/portainer --data /data
