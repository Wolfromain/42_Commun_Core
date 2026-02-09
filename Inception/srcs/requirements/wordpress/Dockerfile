FROM debian:bookworm

RUN apt update -y && apt install wget -y

RUN apt-get install -y php8.2  \
    php-fpm \
    php-mysql \
    mariadb-client

COPY ./conf/www.conf /etc/php/8.2/fpm/pool.d/www.conf

RUN wget https://fr.wordpress.org/wordpress-6.8.2-fr_FR.tar.gz -P /var/www && \
    cd /var/www && tar -xzf wordpress-6.8.2-fr_FR.tar.gz && rm wordpress-6.8.2-fr_FR.tar.gz && \
	mkdir -p /run/php

COPY conf/config.sh /tmp/config.sh
RUN chmod +x /tmp/config.sh

RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
    chmod +x wp-cli.phar && \
    mv wp-cli.phar /usr/local/bin/wp

ENTRYPOINT [ "/tmp/config.sh" ]