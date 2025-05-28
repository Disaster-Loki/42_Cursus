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

COMMAND = docker compose
DCOMPOSE = srcs/docker-compose.yml

all: up

up:
	$(COMMAND) -f $(DCOMPOSE) up -d

stop:
	$(COMMAND) -f $(DCOMPOSE) stop

build:
	$(COMMAND) -f $(DCOMPOSE) --build -d

logs:
	$(COMMAND) -f $(DCOMPOSE) logs

ps:
	$(COMMAND) -f $(DCOMPOSE) ps

down:
	$(COMMAND) -f $(DCOMPOSE) down

fdown:
	$(COMMAND) -f $(DCOMPOSE) down --rmi all -v

re: down build up
