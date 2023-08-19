# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yzaytoun <yzaytoun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/12 17:16:01 by yzaytoun          #+#    #+#              #
#    Updated: 2023/08/19 17:54:01 by yzaytoun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus

vpath %.c src:../philo/src
vpath %.h include
vpath %.o obj

# ************************* BANNER ***********************************
                                                                                                                          
BANNER=	$(info $(YELLOW) ███████████  █████       ███  ████                                      █████                                )\
$(info░░███░░░░░███░░███       ░░░  ░░███                                     ░░███                                 )\
$(info ░███    ░███ ░███████   ████  ░███   ██████   █████   ██████  ████████  ░███████    ██████  ████████   █████ )\
$(info ░██████████  ░███░░███ ░░███  ░███  ███░░███ ███░░   ███░░███░░███░░███ ░███░░███  ███░░███░░███░░███ ███░░  )\
$(info ░███░░░░░░   ░███ ░███  ░███  ░███ ░███ ░███░░█████ ░███ ░███ ░███ ░███ ░███ ░███ ░███████  ░███ ░░░ ░░█████ )\
$(info ░███         ░███ ░███  ░███  ░███ ░███ ░███ ░░░░███░███ ░███ ░███ ░███ ░███ ░███ ░███░░░   ░███      ░░░░███)\
$(info █████        ████ █████ █████ █████░░██████  ██████ ░░██████  ░███████  ████ █████░░██████  █████     ██████ )\
$(info░░░░░        ░░░░ ░░░░░ ░░░░░ ░░░░░  ░░░░░░  ░░░░░░   ░░░░░░   ░███░░░  ░░░░ ░░░░░  ░░░░░░  ░░░░░     ░░░░░░  )\
$(info                                                               ░███                                           )\
$(info                                                               █████                                          )\
$(info                                                              ░░░░░                                           )\
$(info ███████████                                                                                                  )\
$(info░░███░░░░░███                                                                                                 )\
$(info ░███    ░███  ██████  ████████   █████ ████  █████                                                           )\
$(info ░██████████  ███░░███░░███░░███ ░░███ ░███  ███░░                                                            )\
$(info ░███░░░░░███░███ ░███ ░███ ░███  ░███ ░███ ░░█████                                                           )\
$(info ░███    ░███░███ ░███ ░███ ░███  ░███ ░███  ░░░░███                                                          )\
$(info ███████████ ░░██████  ████ █████ ░░████████ ██████                                                           )\
$(info░░░░░░░░░░░   ░░░░░░  ░░░░ ░░░░░   ░░░░░░░░ ░░░░░░                                                            )                                                  
# ************************ Colors ***********************************
ifneq (,$(findstring xterm,${TERM}))
	BLACK        := $(shell tput -Txterm setaf 0)
	RED          := $(shell tput -Txterm setaf 1)
	GREEN        := $(shell tput -Txterm setaf 2)
	YELLOW       := $(shell tput -Txterm setaf 3)
	LIGHTPURPLE  := $(shell tput -Txterm setaf 4)
	PURPLE       := $(shell tput -Txterm setaf 5)
	BLUE         := $(shell tput -Txterm setaf 6)
	WHITE        := $(shell tput -Txterm setaf 7)
	RESET := $(shell tput -Txterm sgr0)
else
	BLACK        := ""
	RED          := ""
	GREEN        := ""
	YELLOW       := ""
	LIGHTPURPLE  := ""
	PURPLE       := ""
	BLUE         := ""
	WHITE        := ""
	RESET        := ""
endif

# --------------------- Definitions ------------------------------------
CC = gcc
INC = include
INC_philo = ../philo/include
CFLAGS = -Wall -Wextra -Werror -I$(INC) -I$(INC_philo) 
SANITIAZE_ADD = -fsanitize=address -g3
SANITIAZE = -fsanitize=thread -g3
PTHREAD = -lpthread -lrt
RM = rm -fr
# ------------------------ philo ------------------------------
SRC = main.c apply.c basicfunc.c auxfunc.c philo.c printer.c timer.c threads.c\
	run_bonus.c child_process.c sem_execute.c

OBJDIR = obj

PHILO_OBJ := $(SRC:%.c=$(OBJDIR)/%.o)

$(OBJDIR)/%.o:%.c
	@mkdir -p $(@D)
	$(COMPILE.c) -o $@ $<

all: $(NAME)

$(NAME): $(BANNER) $(PHILO_OBJ)
	@echo "$(LIGHTPURPLE)Creating Object Files"
	@$(CC) $(PHILO_OBJ) -o $@ $(PTHREAD) $(SANITIAZE)
	@echo "$(WHITE)Compiling" $@
	@chmod +x $@
	@echo "$(PURPLE)************ 	DONE	 ****************\n"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(BLUE)\n***************** DONE Cleaning ********************\n\n"

clean:
	@echo "\n\n"
	@echo "$(YELLOW)Cleaning Object files"
	@$(RM) $(PHILO_OBJ) $(OBJDIR)
	@echo "Cleaning PHILO"

re: fclean all

.PHONY: all re fclean clean