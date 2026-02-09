NAME = Inception

DOCKER_COMPOSE = ./srcs/docker_compose.yml

all: build

build :
	sudo docker compose -f ${DOCKER_COMPOSE} up -d --build

stop:
	sudo docker compose -f ${DOCKER_COMPOSE} stop

clean:
	sudo docker compose -f ${DOCKER_COMPOSE} down -v --rmi all --remove-orphans

crash: 
	sudo docker system prune -a

re:
	clean build

.PHONY: all build stop re clean