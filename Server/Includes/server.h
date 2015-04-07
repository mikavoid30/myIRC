/*
** server.h for ftp serveur lib in /home/boulat_m/rendu/Projets_sem2/myftp/Server
** 
** Made by Mickael BOULAT
** Login   <boulat_m@epitech.net>
** 
** Started on  Mon Mar  9 17:49:22 2015 Mickael BOULAT
** Last update Tue Apr  7 21:20:20 2015 Mickael BOULAT
*/

# ifndef SERVER_H_
#  define SERVER_H_
 
#  define MAX_CLT 5

#  include <unistd.h>
#  include <stdlib.h>
#  include <stdio.h>
#  include <strings.h>
#  include <string.h>
#  include <sys/types.h>
#  include <sys/socket.h>
#  include <netinet/in.h>
#  include <arpa/inet.h>


typedef struct	s_config
{
  int			port;
  int			maxClients;
  int			socketFd;
  int			cSocketFd;
  struct in_addr	*ipAddress;
  struct sockaddr_in	srv;
  struct sockaddr_in	clt;
}		t_config;

# endif /* SERVER_H_ */ 
