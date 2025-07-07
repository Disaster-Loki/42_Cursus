#!/bin/sh
set -eux

echo ">>> Running as user: $(whoami)"

# Read environment variables
ADMIN_USER="${P_USER}"
ADMIN_PASSWORD_FILE="${P_PASSWORD}"

# Read the secret password from the file and generate bcrypt hash
if [ -f "$ADMIN_PASSWORD_FILE" ]; then
  PLAINTEXT_PASSWORD=$(cat "$ADMIN_PASSWORD_FILE")
else
  echo "Password file not found: $ADMIN_PASSWORD_FILE"
  exit 1
fi

# Generate bcrypt hash using Python
ADMIN_PASSWORD_HASH=$(python3 -c "import bcrypt; print(bcrypt.hashpw(b'$PLAINTEXT_PASSWORD', bcrypt.gensalt()).decode())")

echo ">>> Starting Portainer with admin user: $ADMIN_USER"

# Run Portainer with Docker socket support
exec /usr/local/bin/portainer \
  --bind "0.0.0.0:9443" \
  --data /data \
  --admin-password "$ADMIN_PASSWORD_HASH" \
  -H unix:///var/run/docker.sock
