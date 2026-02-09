#!/bin/sh

echo "Waiting for MariaDB to be ready..."
until mysqladmin ping -h mariadb --silent; do
    echo "Waiting for MariaDB..."
    sleep 3
done

mkdir -p /run/php

echo "Checking if WordPress is already installed..."
if [ -f "$WP_PATH/wp-config.php" ]; then
    echo "WordPress already installed. Skipping installation."
else
    echo "WordPress not found. Installing..."

    wp core download --path="$WP_PATH" --allow-root

    wp config create \
        --dbname="$MYSQL_DATABASE" \
        --dbuser="$MYSQL_USER" \
        --dbpass="$MYSQL_PASSWORD" \
        --dbhost="mariadb" \
        --path="$WP_PATH" \
        --skip-check \
        --allow-root

    wp core install \
        --path="$WP_PATH" \
        --url="https://$DOMAIN_NAME" \
        --title="$WP_TITLE" \
        --skip-email \
        --allow-root

    wp user create testo testo@tes.to \
        --role=author \
        --user_pass=testo \
        --path="$WP_PATH" \
        --allow-root
fi

if wp user get admin --path="$WP_PATH" --allow-root > /dev/null 2>&1; then
    echo "Deleting user 'admin'..."
    wp user delete admin --path="$WP_PATH" --allow-root --yes
fi

if ! wp user get "$WP_USER" --path="$WP_PATH" --allow-root > /dev/null 2>&1; then
    echo "Creating admin user '$WP_USER'..."
    wp user create "$WP_USER" "$WP_EMAIL" \
        --role=administrator \
        --user_pass="$WP_PASSWORD" \
        --path="$WP_PATH" \
        --allow-root
else
    echo "Admin user '$WP_USER' already exists."
fi

if ! wp theme is-installed twentytwentythree --path="$WP_PATH" --allow-root; then
    echo "Installing twentytwentythree theme..."
    wp theme install twentytwentythree --path="$WP_PATH" --allow-root
fi

echo "Starting PHP-FPM..."
exec /usr/sbin/php-fpm8.2 -F
