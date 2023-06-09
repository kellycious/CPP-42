
#1 --- FILE

NAME = account
FILE = Account.cpp tests.cpp

OBJS :=  	${addprefix ./OBJ/,${FILE:%.cpp=%.o}}
DEP   = 	${addprefix ./OBJ/,${OBJS:%.o=%.d}}

#2 --- COMPILING VAR

FLAGS = -Wall -Wextra -Werror -std=c++98

#3 --- COLORS

RS=        \033[0m
DARK=        \033[1;32m
RED=        \033[31m
GREEN=        \033[32m
YELLOW=        \033[33m
BLUE=        \033[34m
MAGENTA=    \033[35m
CYAN=        \033[36m
WHITE=        \033[37m
BOLDBLACK=    \033[1m\033[30m
BOLDRED=    \033[1m\033[31m
BOLDWHITE=    \033[1m\033[37m
BOLDGREEN=    \033[1m\033[32m

#4 --- RULES

all: $(NAME)
-include ${DEP}

./OBJ/%.o: ./%.cpp
	@mkdir -p ${@D}
	@c++ ${FLAGS} -o $@ -c $<

$(NAME): ${OBJS}
	@echo "${CYAN}Compiling ${NAME}...${RS}"
	@c++ ${FLAGS} ${OBJS} -o ${NAME}
	@echo "${MAGENTA}(✿◠‿◠) Your ${NAME} is ready!${RS}"

clean:
	@echo "${RED}Cleaning ${NAME}...${RS}"
	@rm -rf OBJ/
	@rm -f ${OBJS}
	@echo "${GREEN}(っ◔◡◔)っ Everything is gone !${RS}"

fclean:
	@echo "${RED}Cleaning ${NAME}...${RS}"
	@rm -rf OBJ/
	@rm -f ${NAME}
	@echo "${GREEN}(っ◔◡◔)っ Everything is gone !${RS}"

re: fclean all

.PHONY : all clean fclean re

#5 --- FYI
#
#	$@ = rule name | $< = dependency, ex "./pushswap/%.c"
#	addprefix: do not need to write path for each files
#	-L while compiling: looking for certain files or directories
#	.PHONY: used to mute if a file named like a target rule exist, eg.if we had a file named "clean"
#	Make -C: flag to change directory  before executing the rule
#	% wildcard (files matching a pattern)
