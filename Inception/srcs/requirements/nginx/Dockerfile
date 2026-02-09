FROM debian:bookworm

RUN apt update && apt install -y nginx && apt install openssl -y

RUN mkdir -p /etc/nginx/ssl && \
    openssl req -x509 -nodes -newkey rsa:2048 \
        -keyout /etc/nginx/ssl/inception.key \
        -out /etc/nginx/ssl/inception.crt \
        -days 365 \
        -subj "/C=FR/ST=IDF/L=PARIS/O=42/OU=42/CN=rbouquet.42.fr/UID=rbouquet" && \
    mkdir -p /var/run/nginx && \
    chmod 755 /var/www/html && \
    chown -R www-data:www-data /var/www/html

COPY conf/nginx.conf /etc/nginx/nginx.conf

CMD ["nginx", "-g", "daemon off;"]