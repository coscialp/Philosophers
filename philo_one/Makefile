.PHONY: all clean fclean re bonus

BLUE =\033[0;38;5;123m
LIGHT_PINK = \033[0;38;5;200m
PINK = \033[0;38;5;198m
DARK_BLUE = \033[1;38;5;110m
GREEN = \033[1;32;111m
LIGHT_GREEN = \033[0;38;5;121m
LIGHT_RED = \033[0;38;5;110m
FLASH_GREEN = \033[33;32m
WHITE_BOLD = \033[37m
GREY = \033[3;90m
ORANGE = \033[3;91m

SRC =		main.c init.c error.c display.c action.c global.c

USRC = 		$(addprefix utils/, ft_atoi.c ft_write.c ft_strlen.c get_time.c ft_putnbr.c ft_isdigit.c ft_stris.c ft_get_timestamp.c ft_calloc.c)

FLAG =		-Wall -Werror -Wextra -O3 -g3

SRCS_NAME	=	$(SRC) $(USRC)

HEADER		=	includes/

PTHREAD		= #-lpthread

SRC_PATH	=	srcs/

SRCS		=	$(addprefix $(SRC_PATH), $(SRCS_NAME))

OBJ_NAME	=	${SRCS_NAME:.c=.o}

OBJ_PATH	=	bin/

OBJ			=	$(addprefix $(OBJ_PATH), $(OBJ_NAME))

NAME		=	philo_one

CC			=	gcc

RM			=	rm -rf

all: $(OBJ_PATH) $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@gcc $(FLAG) $(OBJ) -o $(NAME) $(PTHREAD)
	@printf "	\033[2K\r\033[1;38;5;110mphilo_one\t\t: \033[0;38;5;121mUpdated\n\033[0m"

$(OBJ_PATH):
	@mkdir -p bin/ 2> /dev/null
	@mkdir -p bin/utils/ 2> /dev/null

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(HEADER) Makefile
	@printf "\033[2K\r\033[0;31;5;110mCompiling...	\033[37m$<\033[36m \033[0m"
	@gcc $(FLAG) -I ${HEADER} -c $< -o $@ $(PTHREAD)

clean:
	@printf "\33[2K\r\033[0;31;5;110mDeleting philo_one srcs/	\033[37m"
	@sleep 0.1
	@printf "\33[2K\r\033[0;31;5;110mDeleting philo_one srcs/.	\033[37m"
	@sleep 0.1
	@printf "\33[2K\r\033[0;31;5;110mDeleting philo_one srcs/..	\033[37m"
	@sleep 0.1
	@printf "\33[2K\r\033[0;31;5;110mDeleting philo_one srcs/...	\033[37m"
	@sleep 0.1
	@printf "\33[2K\r\033[0;31;5;110mDeleting philo_one srcs/	\033[37m"
	@sleep 0.1
	@printf "\33[2K\r\033[0;31;5;110mDeleting philo_one srcs/.	\033[37m"
	@sleep 0.1
	@printf "\33[2K\r\033[0;31;5;110mDeleting philo_one srcs/..	\033[37m"
	@sleep 0.1
	@printf "\33[2K\r\033[0;31;5;110mDeleting philo_one srcs/...	\033[37m"
	@sleep 0.1
	@${RM} ${OBJ_PATH}
	@printf "\33[2K\r\033[0;31;5;110mDeleted successfully!\n\033[0m"

fclean: clean
	@${RM} ${NAME}

re: fclean all
