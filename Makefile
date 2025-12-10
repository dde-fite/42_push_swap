# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dde-fite <dde-fite@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/25 17:35:03 by dde-fite          #+#    #+#              #
#    Updated: 2025/12/10 21:25:33 by dde-fite         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
# *                          push_swap by dde-fite                           * #
# **************************************************************************** #

# ******************************** VARIABLES  ******************************** #
SHELL := /bin/bash

# FILES
NAME			= push_swap
SRC_FILES		= main.c utils/lstnew.c utils/lstadd_back.c utils/lstsize.c \
					utils/lstadd_front.c utils/lstclear.c utils/lstdelone.c \
					utils/lstlast.c utils/print_stacks.c \
					helpers/error_handling.c operations/swap.c \
					operations/push.c operations/rotate.c \
					operations/revrotate.c sorting/methods.c
SRCB_FILES		:=
SRC_FOLDER		= src
SRCB_FOLDER		= srcb
INCLUDE_FOLDER	= include
BUILD_FOLDER	= build
LIBFT_FOLDER	= lib/Libft_printf
LIBFT_LIBRARY	= libftprintf.a
SRC				:= $(addprefix $(SRC_FOLDER)/, $(SRC_FILES))
OBJ				:= $(patsubst $(SRC_FOLDER)/%.c,$(BUILD_FOLDER)/%.o,$(SRC))
SRCB			:= $(addprefix $(SRCB_FOLDER)/, $(SRCB_FILES))
OBJB			:= $(patsubst $(SRCB_FOLDER)/%.c,$(BUILD_FOLDER)/%.o,$(SRCB))
TOTAL			:= $(words $(SRC))
TOTALB			:= $(words $(SRCB))

# GCC COMPILER
CC				= cc
CFLAGS			= -Wall -Werror -Wextra -I$(INCLUDE_FOLDER) -I${LIBFT_FOLDER}/include -I${LIBFT_FOLDER}/libft -O3 -march=native -fno-semantic-interposition -fno-plt
CFLAGS_OBJ		= $(CFLAGS) -c
CFLAGS_LINK		= $(CFLAGS) -o $(NAME)
DEBUGFLAGS		= -fdiagnostics-color=always -g

# COMMANDS
RM				= rm
MKDIR			= mkdir

# COLORS
GREEN			:= \033[1;32m
BLUE			:= \033[1;34m
YELLOW			:= \033[1;33m
PURPLE			:= \033[1;35m
CYAN			:= \033[1;36m
RED				:= \033[1;31m
RESET			:= \033[0m

# BAR
BAR_LEN			:= 100

# ********************************** RULES  ********************************** #

all: ${NAME}

${NAME}: ${LIBFT_FOLDER}/libft.a
	@echo -e "\n${PURPLE}"
	@echo "                         __                                                        "
	@echo "                        /\ \                                                       "
	@echo "  _____   __  __    ____\ \ \___              ____  __  __  __     __     _____    "
	@echo " /\ ·__·\/\ \/\ \  /·,__\\ \  _ ·\           /·,__\/\ \/\ \/\ \  /·__·\  /\ ·__·\  "
	@echo " \ \ \L\ \ \ \_\ \/\__, ·\\ \ \ \ \         /\__, ·\ \ \_/ \_/ \/\ \L\.\_\ \ \L\ \ "
	@echo "  \ \ ,__/\ \____/\/\____/ \ \_\ \_\        \/\____/\ \___x___/'\ \__/.\_\\ \ ,__/ "
	@echo "   \ \ \/  \/___/  \/___/   \/_/\/_/  _______\/___/  \/__/__/    \/__/\/_/ \ \ \/  "
	@echo "    \ \_\                            /\______\                              \ \_\  "
	@echo "     \/_/                            \/______/                               \/_/  "
	@echo -e "${RED}"
	@echo "                                    by dde-fite                                    "
	@echo -e "${RESET}Creating build folder if does not exist ...\n"
	@${MKDIR} -p ${BUILD_FOLDER}
	@${MKDIR} -p ${dir $(OBJ)}
	@echo -e "Compiling push_swap files ...\n${YELLOW}"
	@count=0; \
	for file in ${SRC_FILES}; do \
		${CC} ${CFLAGS_OBJ} -o ${BUILD_FOLDER}/$${file%.c}.o ${SRC_FOLDER}/$$file; \
		count=$$((count + 1)); \
		progress=$$((count * 100 / ${TOTAL})); \
		hashes_len=$$((progress * ${BAR_LEN} / 100)); \
		hashes=$$(printf '%0.s#' $$(seq 1 $$hashes_len)); \
		spaces_len=$$((BAR_LEN - hashes_len)); \
		spaces=$$(printf '%0.s ' $$(seq 1 $$spaces_len)); \
		printf "\r[%s%s] %d%%" "$$hashes" "$$spaces" "$$progress"; \
	done; \
	echo
	@echo "Linking objects in ${NAME} ..."
	@echo ""
	@${CC} ${CFLAGS_LINK} ${OBJ} ${LIBFT_FOLDER}/${LIBFT_LIBRARY}
	@echo -e "${GREEN}Process completed :)${RESET}\n"


debug: ${LIBFT_FOLDER}/libft.a ${SRC}
	@echo -e "\n${PURPLE}"
	@echo "                         __                                                        "
	@echo "                        /\ \                                                       "
	@echo "  _____   __  __    ____\ \ \___              ____  __  __  __     __     _____    "
	@echo " /\ ·__·\/\ \/\ \  /·,__\\ \  _ ·\           /·,__\/\ \/\ \/\ \  /·__·\  /\ ·__·\  "
	@echo " \ \ \L\ \ \ \_\ \/\__, ·\\ \ \ \ \         /\__, ·\ \ \_/ \_/ \/\ \L\.\_\ \ \L\ \ "
	@echo "  \ \ ,__/\ \____/\/\____/ \ \_\ \_\        \/\____/\ \___x___/'\ \__/.\_\\ \ ,__/ "
	@echo "   \ \ \/  \/___/  \/___/   \/_/\/_/  _______\/___/  \/__/__/    \/__/\/_/ \ \ \/  "
	@echo "    \ \_\                            /\______\                              \ \_\  "
	@echo "     \/_/                            \/______/                               \/_/  "
	@echo -e "${RED}"
	@echo "                                    by dde-fite                                    "
	@echo -e "${RESET}Creating build folder if does not exist ...\n"
	@${MKDIR} -p ${BUILD_FOLDER}
	@${MKDIR} -p ${dir $(OBJ)}
	@echo -e "Compiling push_swap files ...\n${YELLOW}"
	@count=0; \
	for file in ${SRC_FILES}; do \
		${CC} ${CFLAGS_OBJ} ${DEBUGFLAGS} -o ${BUILD_FOLDER}/$${file%.c}.o ${SRC_FOLDER}/$$file; \
		count=$$((count + 1)); \
		progress=$$((count * 100 / ${TOTAL})); \
		hashes_len=$$((progress * ${BAR_LEN} / 100)); \
		hashes=$$(printf '%0.s#' $$(seq 1 $$hashes_len)); \
		spaces_len=$$((BAR_LEN - hashes_len)); \
		spaces=$$(printf '%0.s ' $$(seq 1 $$spaces_len)); \
		printf "\r[%s%s] %d%%" "$$hashes" "$$spaces" "$$progress"; \
	done; \
	echo
	@echo "Linking objects in ${NAME} ..."
	@echo ""
	@${CC} ${CFLAGS_LINK} ${DEBUGFLAGS} ${OBJ} ${LIBFT_FOLDER}/${LIBFT_LIBRARY}
	@echo -e "${GREEN}Process completed :)${RESET}\n"

bonus: .bonus
	@echo "Bonus done."

# .bonus: ${LIBFT_FOLDER}/libft.a ${SRCB}
# 	@echo -e "\n${PURPLE}"
# 	@echo " ░▒▓████████▓▒░▒▓████████▓▒           ░▒▓███████▓▒░░▒▓███████▓▒░░▒▓█▓▒░▒▓███████▓▒░▒▓████████▓▒░▒▓████████▓▒░ "
# 	@echo " ░▒▓█▓▒░         ░▒▓█▓▒░              ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░   ░▒▓█▓▒░        "
# 	@echo " ░▒▓█▓▒░         ░▒▓█▓▒░              ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░   ░▒▓█▓▒░        "
# 	@echo " ░▒▓██████▓▒░    ░▒▓█▓▒░              ░▒▓███████▓▒░░▒▓███████▓▒░░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░   ░▒▓██████▓▒░   "
# 	@echo " ░▒▓█▓▒░         ░▒▓█▓▒░              ░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░   ░▒▓█▓▒░        "
# 	@echo " ░▒▓█▓▒░         ░▒▓█▓▒░              ░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░   ░▒▓█▓▒░        "
# 	@echo " ░▒▓█▓▒░         ░▒▓█▓▒░  ░▒▓████▓▒░  ░▒▓█▓▒░      ░▒▓█▓▒░░▒▓█▓▒░▒▓█▓▒░▒▓█▓▒░░▒▓█▓▒░ ░▒▓█▓▒░   ░▒▓█▓▒░        "
# 	@echo -e "${CYAN}                                                                                  _ __                        "
# 	@echo "                                                                           \ /   ( /  )                   \ / "
# 	@echo "                                                                          --X--   /--< __ _ _   , , (    --X--"
# 	@echo "                                                                           / \   /___/(_)/ / /_(_/_/_)_   / \ "
# 	@echo -e "${RED}"
# 	@echo "                                                 by dde-fite                                                  "
# 	@echo -e "${RESET}Creating build folder if does not exist ...\n"
# 	@${MKDIR} -p ${BUILD_FOLDER}
# 	@${MKDIR} -p ${dir $(OBJB)}
# 	@echo -e "Compiling ft_printf files ...\n${YELLOW}"
# 	@count=0; \
# 	for file in ${SRCB_FILES}; do \
# 		${CC} ${CFLAGS} -o ${BUILD_FOLDER}/$${file%.c}.o ${SRCB_FOLDER}/$$file; \
# 		count=$$((count + 1)); \
# 		progress=$$((count * 100 / ${TOTALB})); \
# 		hashes_len=$$((progress * ${BAR_LEN} / 100)); \
# 		hashes=$$(printf '%0.s#' $$(seq 1 $$hashes_len)); \
# 		spaces_len=$$((BAR_LEN - hashes_len)); \
# 		spaces=$$(printf '%0.s ' $$(seq 1 $$spaces_len)); \
# 		printf "\r[%s%s] %d%%" "$$hashes" "$$spaces" "$$progress"; \
# 	done; \
# 	echo
# 	@echo -e "${RESET}\nCloning libft binary ...\n"
# 	@${CP} ${LIBFT_FOLDER}/libft.a ${NAME}
# 	@echo "Archiving objects in ${NAME} ..."
# 	@echo ""
# 	@${AR} ${AFLAGS} ${NAME} ${OBJB}
# 	@echo -e "${GREEN}Process completed :)${RESET}\n"
# 	@touch .bonus

# Libft

${LIBFT_FOLDER}/libft.a:
	@echo -e "${GREEN}--------------LIBFT-COMPILATION---------------"
	@${MAKE} -C ${LIBFT_FOLDER} all
	@echo -e "${GREEN}-----------END-OF-LIBFT-COMPILATION-----------${RESET}\n"

update_modules:
	@echo "Updating submodules ..."
	@git submodule init
	@git submodule update --init --recursive --remote
	@echo "Submodules successfully updated"

get_libft: update_modules

# Cleaning

clean:
	@echo "Deleting ${BUILD_FOLDER} and cleaning libft ..."
	@echo ""
	@${RM} -rf ${BUILD_FOLDER}
	@${MAKE} -C ${LIBFT_FOLDER} clean

fclean: clean
	@echo "Deleting binary file (${NAME}) and libft.a ..."
	@echo ""
	@${RM} -f ${NAME}
	@${MAKE} -C ${LIBFT_FOLDER} fclean
	@${RM} -f ${NAME} .bonus

re: fclean all

.PHONY: all clean fclean re update_modules get_libft bonus
