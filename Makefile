NAME = libftprintf.a
LIB = libft.a

PATH_INCLUDE = ./includes/
PATH_LIB = ./libft/
PATH_SRC = ./SRC/

HEADERS = ${PATH_INCLUDE}ft_printf.h ${PATH_INCLUDE}libft.h
HDR_INC = -I./includes/

C_FLAGS = -Wall -Wextra -Werror -c

SRC = 
SOURCES = $(addprefix $(PATH_SRC), ${SRC}) ft_printf.c
OBJS = ${SOURCES:.c=.o} $(addprefix $(PATH_LIB), $(LIB))

RM = rm -rf

%.o : %.c $(HEADERS)
	gcc $(C_FLAGS) $(HDR_INC) $< -o $@

all: run_libft ${OBJS} ${NAME}

run_libft:
	@make -C $(PATH_LIB)

$(NAME): $(OBJS) $(HEADERS)
	ar rcs $(NAME) $(OBJS) $(HEADERS)

clean:
	$(RM) $(OBJS)
	@make -C $(PATH_LIB) clean

fclean: clean
	$(RM) $(NAME)
	@make -C $(PATH_LIB) fclean

re: fclean all

test: re 
		make re && make clean && gcc libftprintf.a  -I./includes/ main.c && ./a.out