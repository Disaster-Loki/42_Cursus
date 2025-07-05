#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-carv <sde-carv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/20 16:32:50 by sde-carv          #+#    #+#              #
#    Updated: 2025/07/05 16:42:10 by sde-carv         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

DIR = srcs
DCOMPOSE = $(DIR)/docker-compose.yml
COMMAND = docker compose -p $(DIR)
IS_UP := $(shell docker ps -q -f name=nginx)

.SILENT:

all: up

dirs:
	@sudo mkdir -p $(HOME)/data/wordpress
	@sudo mkdir -p $(HOME)/data/mariadb
	@echo "Ensured ~/data/wordpress and ~/data/mariadb exist."

up: dirs
	@if [ -z "$(IS_UP)" ]; then \
		echo "Starting the containers..."; \
		$(COMMAND) -f $(DCOMPOSE) up -d; \
	else \
		echo "Containers are already running 👍"; \
	fi

start:
	$(COMMAND) -f $(DCOMPOSE) start

stop:
	$(COMMAND) -f $(DCOMPOSE) stop

build:
	$(COMMAND) -f $(DCOMPOSE) up -d --build

logs:
	$(COMMAND) -f $(DCOMPOSE) logs

ps:
	$(COMMAND) -f $(DCOMPOSE) ps

imgs:
	docker images

vols:
	docker volume ls

nets:
	docker network ls

clean:
	$(COMMAND) -f $(DCOMPOSE) down

fclean:
	clear
	$(COMMAND) -f $(DCOMPOSE) down --rmi all -v --remove-orphans
	docker image prune -af
	docker rmi $(shell docker images -q | grep -v "<none>" || true) 2>/dev/null || true

ffclean: fclean
	sudo rm -rf $(HOME)/data/*
	sudo rm -rf $(HOME)/data/.[!.]* $(HOME)/data/..?*
	@echo "Force-cleaned ~/data contents with sudo."

re: fclean build
