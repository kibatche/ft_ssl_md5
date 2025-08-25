# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chbadad <chbadad@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/16 16:19:00 by chbadad           #+#    #+#              #
#    Updated: 2022/01/28 15:21:05 by chbadad          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCC = clang
CCFLAGS = -c -Wall -Wextra -Werror -g
RM = rm -f

SRCS = ft_bzero.c ft_memcpy.c ft_memset.c ft_memccpy.c ft_memmove.c \
		ft_memchr.c ft_memcmp.c ft_strlen.c ft_isalpha.c ft_isdigit.c \
		ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c \
		ft_strchr.c ft_strrchr.c ft_strncmp.c ft_strlcpy.c ft_strlcat.c \
		ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
		ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

#bonus listes
SRCS += ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
		ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

#bonus arbres binaires
SRCS += ft_btree_create_bonus.c ft_btree_apply_infix_bonus.c \
		ft_btree_apply_prefix_bonus.c ft_btree_apply_suffix_bonus.c \
		ft_btree_insert_data_bonus.c ft_btree_search_item_bonus.c \
		ft_btree_level_count_bonus.c ft_btree_apply_by_level_bonus.c

#bonus non evoques mais utiles pour les fonctions de base afin d'éviter les répétitions, et/ou utiles en tout temps et pouvant être utilisées dans les futurs projets
SRCS += ft_ischarset_bonus.c ft_strrev_bonus.c ft_abs_bonus.c \
		ft_iscntrl_bonus.c ft_isgraph_bonus.c ft_isblank_bonus.c\
		ft_islower_bonus.c ft_isupper_bonus.c ft_isxdigit_bonus.c \
		ft_isspace_bonus.c ft_itoa_base_bonus.c ft_memalloc_bonus.c \
		ft_memdel_bonus.c ft_putwchar_fd_bonus.c ft_putchar_bonus.c \
		ft_atoi_base_bonus.c ft_putendl_bonus.c ft_putnbr_bonus.c ft_putstr_bonus.c \
		ft_strcapitalize_bonus.c ft_strcmp_bonus.c ft_strcasecmp_bonus.c \
		ft_strstr_bonus.c ft_strcasestr_bonus.c ft_strncasecmp_bonus.c \
		ft_strcat_bonus.c ft_strncat_bonus.c ft_strdel_bonus.c ft_strins_bonus.c \
		ft_strndup_bonus.c ft_ispunct_bonus.c ft_strtol.c ft_strdupcat.c \
		ft_str_split_bonus.c ft_free_strs.c ft_strcpy_bonus.c ft_tabs_len_bonus.c \
		ft_tablen_bonus.c ft_cleartab_bonus.c ft_strtoul.c

OBJS = ${SRCS:.c=.o}
NAME = libft.a

all: ${NAME}

$(NAME): ${OBJS}
	ar -rcs ${NAME} ${OBJS}

%.o: %.c
	${GCC} ${CCFLAGS} $< -o $@ -I .

bonus:	${NAME}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
