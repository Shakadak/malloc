# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: npineau <npineau@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/20 12:15:41 by npineau           #+#    #+#              #
#    Updated: 2014/04/16 14:02:58 by npineau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	libft_malloc_$$HOSTTYPE.so

### DIRECTORIES ###

DIRSRC		:=	sources
DIROBJ		:=	objects
DIRMALLOC	:=	$(DIRSRC)/malloc
DIRFREE		:=	$(DIRSRC)/free
DIRREALLOC	:=	$(DIRSRC)/realloc
DIRINC		:=	includes

### FILES ###

### FILES: SOURCES ###

MALLOC		:=	ft_atoi.c \
				ft_isalnum.c \
				ft_isalpha.c \
				ft_isascii.c \
				ft_isdigit.c \
				ft_isprint.c \
				ft_isspace.c \
				ft_itoa.c \
				ft_tolower.c \
				ft_toupper.c

FREE		:=	ft_lstadd.c \
				ft_lstdel.c \
				ft_lstdelone.c \
				ft_lstiter.c \
				ft_lstmap.c \
				ft_lstnew.c

REALLOC		:=	ft_bzero.c \
				ft_memalloc.c \
				ft_memccpy.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_memcpy.c \
				ft_memdel.c \
				ft_memmove.c \
				ft_memset.c

### FILES: OBJECTS ###

OBJ			:=	$(CHAR:.c=.o) \
				$(LST:.c=.o) \
				$(MEM:.c=.o) \
				$(PUT:.c=.o) \
				$(STR:.c=.o)

### FILES: PATHS ###

POBJ		:=	$(addprefix $(DIROBJ)/, $(OBJ))
INC			:=	$(DIRINC)/libft.h

### ARCHIVE ###

AR			:=	ar
AR_FLAG		:=	-crus
AR_EXEC		=	$(AR) $(AR_FLAG) $@ $^

### COMPILATION ###

CC			:=	llvm-gcc
C_FLAG		:=	-Wall -Wextra -Werror
O_FLAG		:=	-O3
C_INC		:=	-I $(DIRINC) -I $(DIRLIB)/$(DIRINC)
COMPIL		=	$(CC) -o $@ -c $< $(C_INC) $(C_FLAG) $(O_FLAG)
#C_OPT		=	-o $@ -c $< -I $(DIRINC)
#COMPIL		=	$(CC) $(C_FLAG) $(O_FLAG) $(C_OPT)

### RULES ###

all: $(NAME)

### RULES: COMPILATION ###

$(DIROBJ)/%.o: $(DIRMALLOC)/%.c $(INC)
	$(COMPIL)

$(DIROBJ)/%.o: $(DIRFREE)/%.c $(INC)
	$(COMPIL)

$(DIROBJ)/%.o: $(DIRREALLOC)/%.c $(INC)
	$(COMPIL)

### RULES: ARCHIVE ###

$(NAME): $(POBJ)
	$(AR_EXEC)

### RULES: MISC ###

$(POBJ): |$(DIROBJ)

$(DIROBJ):
	mkdir $(DIROBJ)

clean:
	@(rm -f $(POBJ))

fclean: clean
	@(rm -f $(NAME))

re: fclean $(NAME)

.PHONY: all clean re fclean
