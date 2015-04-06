##
## Makefile for nibblr in /home/boulat_m/rendu/Projets_sem2/nibbler
## 
## Made by Mickael BOULAT
## Login   <boulat_m@epitech.net>
## 
## Started on  Mon Mar 23 09:37:06 2015 Mickael BOULAT
## Last update Mon Apr  6 11:35:49 2015 Mickael BOULAT
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
			$(CLIENT_PATH)Sources/tcp_utils.c

SRCS_S		=	$(SERVER_PATH)Sources/server.c

###################################################################
#                              Objects
###################################################################

OBJS_C		=	$(SRCS_C:.c=.o)
OBJS_S		=	$(SRCS_S:.c=.o)

###################################################################
#                            Compilation
###################################################################

CC		=	clang

CFLAGS		=	-W -Wall -Werror
CFLAGS		+=	-I$(CLIENT_PATH)Includes -I$(SERVER_PATH)Includes

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
