##
## Makefile for nibblr in /home/boulat_m/rendu/Projets_sem2/nibbler
## 
## Made by Mickael BOULAT
## Login   <boulat_m@epitech.net>
## 
## Started on  Mon Mar 23 09:37:06 2015 Mickael BOULAT
## Last update Tue Apr  7 10:59:08 2015 Mickael BOULAT
##

###################################################################
#                            Title & infos
###################################################################

NAME		=	myIRC

NAME_C		=	client
NAME_S		=	server

###################################################################
#                               Paths
###################################################################

CLIENT_PATH	=	./Client/
SERVER_PATH	=	./Server/

###################################################################
#		              Main Sources
###################################################################

SRCS_C		=	$(CLIENT_PATH)Sources/client.c		\
			$(CLIENT_PATH)Sources/get_next_line.c	\
			$(CLIENT_PATH)Sources/gtk_main.c	\
			$(CLIENT_PATH)Sources/tcp_utils.c

SRCS_S		=	$(SERVER_PATH)Sources/server.c

###################################################################
#                              Objects
###################################################################

OBJS_C		=	$(SRCS_C:.c=.o)
OBJS_S		=	$(SRCS_S:.c=.o)

###################################################################
#                            Flags / Compilation
###################################################################

CC		=	gcc

CFLAGS		=	-W -Wall -Werror
CFLAGS		+=	-I/usr/include -I$(CLIENT_PATH)Includes -I$(SERVER_PATH)Includes
CFLAGS		+=	`pkg-config --cflags gtk+-3.0 --libs gtk+-3.0`

RM		=	rm -rf

###################################################################

all		:	$(NAME)

$(NAME)		:	$(OBJS_C) $(OBJS_S)
			$(CC) $(OBJS_C) -o $(CLIENT_PATH)$(NAME_C) $(CFLAGS)
			$(CC) $(OBJS_S) -o $(SERVER_PATH)$(NAME_S) $(CFLAGS)

clean		:	
			$(RM) $(OBJS_C)
			$(RM) $(OBJS_S)

fclean		:	clean
			$(RM) $(CLIENT_PATH)$(NAME_C)
			$(RM) $(SERVER_PATH)$(NAME_S)

re		:	fclean all

###################################################################
###################################################################
###################################################################
