FROM debian:bookworm

RUN apt update -y && apt install mariadb-server -y 

COPY conf/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf

COPY ./tools/init_db.sh /tmp/
COPY ./conf/init_sql.sql /tmp/init_sql.sql

RUN chmod +x /tmp/init_db.sh && \
    chown -R mysql:mysql /etc/mysql && \
    mkdir -p /run/mysqld && chown mysql:mysql /run/mysqld

ENTRYPOINT ["sh", "/tmp/init_db.sh"]