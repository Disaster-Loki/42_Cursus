<?php
// WordPress database settings (not the same as the MariaDB root user)
define('DB_NAME', getenv('WORDPRESS_DB_NAME') ?: 'wordpress');
define('DB_USER', getenv('WORDPRESS_DB_USER') ?: 'wp_user');
define('DB_PASSWORD', getenv('WORDPRESS_DB_PASSWORD') ?: 'wp_pass');
define('DB_HOST', getenv('WORDPRESS_DB_HOST') ?: 'mariadb:3306');

// Charset and collation settings
define('DB_CHARSET', 'utf8');
define('DB_COLLATE', '');

// Main domain used by WordPress
define('WP_HOME', getenv('DOMAIN_NAME') ? 'https://' . getenv('DOMAIN_NAME') : 'https://localhost');
define('WP_SITEURL', getenv('DOMAIN_NAME') ? 'https://' . getenv('DOMAIN_NAME') : 'https://localhost');

// Enable HTTPS when behind a reverse proxy
if (!empty($_SERVER['HTTP_X_FORWARDED_PROTO']) && $_SERVER['HTTP_X_FORWARDED_PROTO'] === 'https') {
    $_SERVER['HTTPS'] = 'on';
}

// Unique authentication keys and salts
define('AUTH_KEY',         'NFk%H <@s,O$sB^uzqV D0(WH/o_/^0|8V+|8U14OetS|t8Fsd` yOG$Ix4K&>v=');
define('SECURE_AUTH_KEY',  'Xcv~o%@?RK1?}r8CJ+@:O!~mAX&~;fC|4z|eb=B|Q]sgY<*1azLZU|/yZ[]Ijg=a');
define('LOGGED_IN_KEY',    'E/ r-m{{~%]-|<#7v(n|Wz8cIu5wxfW9-o?mO++u#^GB-B` LjW5|P-@,-vA40tU');
define('NONCE_KEY',        'B,?qqrbdOq_CjuPe9L>xcnnLY_+xH)e*1&xy{AkHO2sD6mIG_%J?-SJs<MeA2b9(');
define('AUTH_SALT',        '8p58F0x}UC=},OMNU&3,{5s^6P9|LedAg|oh!iMWZpomsEw;?|/k`#u7@JRW%qYj');
define('SECURE_AUTH_SALT', 'fX*_uLe@_;g*q7J-cKK2yJ8/FYR33:dp+LKP?a^/Tk!H(+*q:%N$;cy6fthymu?W');
define('LOGGED_IN_SALT',   'bK-ie6Q;I-#i={*HzK^7[D,3!q`KPk+6Q- sP@4Uh,k%%gXt0<5poT;<o4d?ES;d');
define('NONCE_SALT',       'hR9~~2/R%&I6SnR[Dv6J@7R:jaTgkiP}:d9fqxvb4pKepu`d@$8>j.)+BIPg!5n&');

// Database table prefix
$table_prefix = 'wp_';

// Enable debugging mode (set to false by default)
define('WP_DEBUG', false);

// Absolute path to the WordPress directory
if (!defined('ABSPATH'))
    define('ABSPATH', __DIR__ . '/');

// Load WordPress settings
require_once ABSPATH . 'wp-settings.php';
