# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjamis <tjamis@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/22 19:19:03 by tjamis            #+#    #+#              #
#    Updated: 2021/05/10 17:34:53 by tjamis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
HEADER	=	libft.h
OBJS	=	${SRC:.c=.o}
SRC		=	ft_memset.c			ft_isalnum.c		ft_strrchr.c		ft_isalnum.c		\
			ft_bzero.c			ft_isascii.c		ft_strnstr.c		ft_strmapi.c		\
			ft_memcpy.c			ft_isprint.c		ft_strncmp.c		ft_putstr_fd.c		\
			ft_memccpy.c		ft_toupper.c		ft_atoi.c			ft_putendl_fd.c		\
			ft_memmove.c		ft_tolower.c		ft_isalpha.c		ft_putnbr_fd.c		\
			ft_memchr.c			ft_calloc.c			ft_isdigit.c		ft_strtrim.c		\
			ft_memcmp.c			ft_strdup.c			ft_substr.c			ft_split.c			\
			ft_strlen.c			ft_strjoin.c		ft_putchar_fd.c		ft_itoa.c			\
			ft_strlcpy.c		ft_strlcat.c		ft_strchr.c								\

BONUS_SRC =	ft_lstadd_back.c	ft_lstnew.c			\
			ft_lstdelone.c		ft_lstadd_front.c	\
			ft_lstclear.c		ft_lstsize.c		\
			ft_lstiter.c		ft_lstlast.c		\
			ft_lstmap.c

BONUS_OBJ = ${BONUS_SRC:.c=.o}
FLAGS	= -Wall -Wextra -Werror
RM = rm -rf

.PHONY: all clean fclean re bonus ${NAME}

.c.o:		${HEADER}
			gcc ${FLAGS} -I../includes/ -c $< -o ${<:.c=.o}

all:		${OBJS} 
			ar rc ${NAME} ${OBJS}
			ranlib ${NAME}
clean:
			rm -rf ${OBJS} ${BONUS_OBJ}
fclean: 	clean
			rm -rf ${NAME}

re:			fclean all

bonus:		${NAME} ${BONUS_OBJ}
			ar rc ${NAME} ${BONUS_OBJ}
			ranlib ${NAME}

$(NAME):	all