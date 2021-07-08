NAME = libftprintf.a
LIB = libft.a

PATH_INCLUDE = ./includes/
PATH_LIB = ./libft/
PATH_SRC = ./sources/

HEADERS = ${PATH_INCLUDE}ft_printf.h ${PATH_INCLUDE}libft.h
HDR_INC = -I./includes/

C_FLAGS = -Wall -Wextra -Werror -c

SRC = ft_utils.c ft_parse.c ft_parse_flag.c ft_parse_width.c ft_problem.c 
LIB_OBG	=	ft_memset.o			ft_isalnum.o		ft_strrchr.o		ft_isalnum.o		\
			ft_bzero.o			ft_isascii.o		ft_strnstr.o		ft_strmapi.o		\
			ft_memcpy.o			ft_isprint.o		ft_strncmp.o		ft_putstr_fd.o		\
			ft_memccpy.o		ft_toupper.o		ft_atoi.o			ft_putendl_fd.o		\
			ft_memmove.o		ft_tolower.o		ft_isalpha.o		ft_putnbr_fd.o		\
			ft_memchr.o			ft_calloc.o			ft_isdigit.o		ft_strtrim.o		\
			ft_memcmp.o			ft_strdup.o			ft_substr.o			ft_split.o			\
			ft_strlen.o			ft_strjoin.o		ft_putchar_fd.o		ft_itoa.o			\
			ft_strlcpy.o		ft_strlcat.o		ft_strchr.o								
SOURCES = $(addprefix $(PATH_SRC), ${SRC}) ft_printf.c 
OBJS = ${SOURCES:.c=.o} $(addprefix $(PATH_LIB), $(LIB_OBG))

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
		make clean && gcc libftprintf.a  -I./includes/ main.c && ./a.out