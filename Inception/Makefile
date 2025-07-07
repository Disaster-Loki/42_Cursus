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

# Defining color codes for terminal output
RESET   := \033[0m
RED     := \033[31m
GREEN   := \033[32m
YELLOW  := \033[33m
BLUE    := \033[34m
CYAN    := \033[36m
MAGENTA := \033[35m

DIR = srcs
DCOMPOSE = $(DIR)/docker-compose.yml
COMMAND = docker compose -p $(DIR)
IS_UP := $(shell docker ps -q -f name=nginx)

.SILENT:

all: up

# Create necessary directories
dirs:
	@sudo mkdir -p $(HOME)/data
	@sudo mkdir -p $(HOME)/data/wordpress
	@sudo mkdir -p $(HOME)/data/mariadb
	@echo "$(CYAN)Ensured ~/data/wordpress and ~/data/mariadb exist.$(RESET)"

# Start containers if not already running
up: dirs
	@if [ -z "$(IS_UP)" ]; then \
		echo "$(YELLOW)Starting the containers...$(RESET)"; \
		$(COMMAND) -f $(DCOMPOSE) up -d; \
	else \
		echo "$(GREEN)Containers are already running 👍$(RESET)"; \
	fi

# Start the containers if they're stopped
start:
	$(COMMAND) -f $(DCOMPOSE) start
	@echo "$(CYAN)Started containers$(RESET)"

# Stop the containers
stop:
	$(COMMAND) -f $(DCOMPOSE) stop
	@echo "$(YELLOW)Stopped containers$(RESET)"

# Build the containers from scratch
build:
	$(COMMAND) -f $(DCOMPOSE) up -d --build
	@echo "$(BLUE)Containers are being built...$(RESET)"

# Show logs of the containers
logs:
	$(COMMAND) -f $(DCOMPOSE) logs

# List the running containers
ps:
	$(COMMAND) -f $(DCOMPOSE) ps

# List docker images
imgs:
	docker images

# List docker volumes
vols:
	docker volume ls

# List docker networks
nets:
	docker network ls

# Stop and remove containers
clean:
	$(COMMAND) -f $(DCOMPOSE) down
	@echo "$(MAGENTA)Stopped and removed containers$(RESET)"

# Remove containers, images, volumes, and orphans
fclean:
	clear
	$(COMMAND) -f $(DCOMPOSE) down --rmi all -v --remove-orphans
	docker image prune -af
	docker rmi $(shell docker images -q | grep -v "<none>" || true) 2>/dev/null || true
	@echo "$(RED)Cleaned up containers, images, and volumes$(RESET)"

# Force remove data directories
ffclean: fclean
	sudo rm -rf $(HOME)/data/*
	sudo rm -rf $(HOME)/data/.[!.]* $(HOME)/data/..?*
	@echo "$(RED)Force-cleaned ~/data contents with sudo.$(RESET)"

# Rebuild everything from scratch
re: fclean build
