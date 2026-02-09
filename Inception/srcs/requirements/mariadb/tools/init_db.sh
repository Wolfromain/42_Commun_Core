#!/bin/sh
set -e

mkdir -p /run/mysqld
chown mysql:mysql /run/mysqld

echo "Creating DB $MYSQL_DATABASE and user $MYSQL_USER"

if [ ! -d "/var/lib/mysql/mysql" ]; then
  mariadb-install-db --user=mysql --datadir=/var/lib/mysql

  mysqld --skip-networking --socket=/var/run/mysqld/mysqld.sock &
  pid="$!"

  until mysqladmin ping --socket=/var/run/mysqld/mysqld.sock --silent; do
    echo "Waiting for MariaDB to be ready..."
    sleep 1
  done

  # Remplacement des placeholders par les vraies variables
  sed -i "s|MYSQL_DATABASE|$MYSQL_DATABASE|g" /tmp/init.sql
  sed -i "s|MYSQL_USER|$MYSQL_USER|g" /tmp/init.sql
  sed -i "s|MYSQL_PASSWORD|$MYSQL_PASSWORD|g" /tmp/init.sql

  mysql --socket=/var/run/mysqld/mysqld.sock < /tmp/init.sql

  mysql --socket=/var/run/mysqld/mysqld.sock <<-EOSQL
    ALTER USER 'root'@'localhost' IDENTIFIED BY '$MYSQL_ROOT_PASSWORD';
    FLUSH PRIVILEGES;
EOSQL

  mysqladmin shutdown --socket=/var/run/mysqld/mysqld.sock
  wait $pid
  echo "Database initialized."
else
  echo "Database already exists."
fi

exec mariadbd --user=mysql --console
