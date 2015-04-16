##
## Makefile for Makefile in /home/besnai_m/rendu/C-Prog ELEM/CPE_2014_bsq
## 
## Made by michael besnainou
## Login   <besnai_m@epitech.net>
## 
## Started on  Mon Jan 12 14:01:57 2015 michael besnainou
## Last update Sun Mar 22 21:03:02 2015 michael besnainou
##

SRC	= client/src/client.c

SRC2	= server/src/server.c

SRCS	= lib/my/my_putchar.c \
	lib/my/my_strlen.c \
	lib/my/my_putstr.c \
	lib/my/my_getnbr.c \
	lib/my/my_put_nbr.c 

OBJ	= $(SRC:.c=.o)

OBJ2	= $(SRC2:.c=.o)

OBJS	= $(SRCS:.c=.o)

CC	= gcc

RM	= rm -rf

LIB	= libmy.a

FILE	= client/client

FILE2	= server/server

CFLAGS	= -W -Wall -Wextra -pedantic -Iinclude/

all: $(LIB) $(FILE) $(FILE2)

$(LIB): $(OBJS)
	ar rc $(LIB) $(OBJS)
	ranlib $(LIB)

$(FILE): $(LIB) $(OBJ)
	$(CC) -o $(FILE) $(OBJ) $(LIB)

$(FILE2): $(LIB) $(OBJ2)
	$(CC) -o $(FILE2) $(OBJ2) $(LIB)

clean: 
	$(RM) $(OBJ)
	$(RM) $(OBJ2)
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(LIB)
	$(RM) $(FILE)
	$(RM) $(FILE2)

re: fclean all

.PHONY: all clean fclean re
