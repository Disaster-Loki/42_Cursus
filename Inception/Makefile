# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/20 16:32:50 by sde-carv          #+#    #+#              #
#    Updated: 2025/05/20 16:32:51 by sde-carv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

D-COMPOSE = srcs/docker-compose.yml

all: up

up:
	docker compose -f $(D-COMPOSE) up -d

stop:
	docker compose -f $(D-COMPOSE) stop

build:
	docker compose -f $(D-COMPOSE) --build -d

logs:
	docker compose -f $(D-COMPOSE) logs

ps:
	docker compose -f $(D-COMPOSE) ps

down:
	docker compose -f $(D-COMPOSE) down --rmi all -v

re: down build up
