<?php
// Initialize the variables
$REDIS = 'redis';
$WP_DB_PW = null;
$CREDENTIALS = [];
$REDIS_PORT = 6379;
$DOMAIN = getenv('DOMAIN_NAME');
$WP_DB = getenv('WORDPRESS_DB_NAME');
$WP_DB_USER = getenv('WORDPRESS_DB_USER');
$WP_DB_HOST = getenv('WORDPRESS_DB_HOST');
$CREDENTIALS_FILE = getenv('CREDENTIALS_FILE');
$WP_DB_PW_FILE = getenv('WORDPRESS_DB_PASSWORD_FILE');

// WordPress database settings
define('DB_NAME', $WP_DB);
define('DB_USER', $WP_DB_USER);

// Search for the password from the
// file pointed to by WORDPRESS_DB_PASSWORD_FILE
if ($WP_DB_PW_FILE && file_exists($WP_DB_PW_FILE))
    $WP_DB_PW = trim(file_get_contents($WP_DB_PW_FILE));

define('DB_PASSWORD', $WP_DB_PW);
define('DB_HOST', $WP_DB_HOST);

// Charset and collation settings
define('DB_CHARSET', 'utf8');
define('DB_COLLATE', '');

// Main domain used by WordPress
if ($DOMAIN && !preg_match('#^https?://#', $DOMAIN)) {
    $DOMAIN = 'https://' . $DOMAIN;
}

define('WP_HOME', $DOMAIN ?: 'https://localhost');
define('WP_SITEURL', $DOMAIN ?: 'https://localhost');

// Enable HTTPS when behind a reverse proxy
if (!empty($_SERVER['HTTP_X_FORWARDED_PROTO']) && $_SERVER['HTTP_X_FORWARDED_PROTO'] === 'https') {
    $_SERVER['HTTPS'] = 'on';
}

// Load keys and salts from the credentials file
if ($CREDENTIALS_FILE && file_exists($CREDENTIALS_FILE))
    $CREDENTIALS = parse_ini_file($CREDENTIALS_FILE);

define('AUTH_KEY',         $CREDENTIALS['AUTH_KEY']);
define('SECURE_AUTH_KEY',  $CREDENTIALS['SECURE_AUTH_KEY']);
define('LOGGED_IN_KEY',    $CREDENTIALS['LOGGED_IN_KEY']);
define('NONCE_KEY',        $CREDENTIALS['NONCE_KEY']);
define('AUTH_SALT',        $CREDENTIALS['AUTH_SALT']);
define('SECURE_AUTH_SALT', $CREDENTIALS['SECURE_AUTH_SALT']);
define('LOGGED_IN_SALT',   $CREDENTIALS['LOGGED_IN_SALT']);
define('NONCE_SALT',       $CREDENTIALS['NONCE_SALT']);

// Database table prefix
$table_prefix = 'wp_';

// Enable debugging mode (set to false by default)
define('WP_DEBUG', false);

// Enable WordPress object caching
define('WP_CACHE', true);

// Redis cache configuration
define('WP_REDIS_HOST', $REDIS);
define('WP_REDIS_PORT', $REDIS_PORT);

// Absolute path to the WordPress directory
if (!defined('ABSPATH')) define('ABSPATH', __DIR__ . '/');

// Load WordPress settings
require_once ABSPATH . 'wp-settings.php';
