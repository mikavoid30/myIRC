/*
** client.h for Client_H_ in /home/boulat_m/rendu/Projets_sem2/myIRC
** 
** Made by Mickael BOULAT
** Login   <boulat_m@epitech.net>
** 
** Started on  Mon Apr  6 11:27:05 2015 Mickael BOULAT
** Last update Mon Apr  6 20:17:38 2015 Mickael BOULAT
*/

# ifndef CLIENT_H_
#  define CLIENT_H_
 
#  include <unistd.h>
#  include <stdlib.h>
#  include <stdio.h>
#  include <strings.h>
#  include <string.h>
#  include <sys/types.h>
#  include <sys/socket.h>
#  include <netinet/in.h>
#  include <arpa/inet.h>
#  include <gtk/gtk.h>
#  include <gdk/gdk.h>

#  define BUFF_SIZE	256
#  define LINE_SIZE	256
#  define BLACK		"\033[30m"
#  define RED		"\033[31m"
#  define GREEN		"\033[32m"
#  define YELLOW	"\033[33m"
#  define BLUE		"\033[34m"
#  define MAGENTA	"\033[35m"
#  define CYAN		"\033[36m"
#  define WHITE		"\033[37m"
#  define INIT		"\033[0m"
#  define BOLD		"\033[1m"

typedef struct		s_config
{
  int			port;
  int			socketFd;
  struct in_addr	*ipAddress;
  struct sockaddr_in	srv;
  struct sockaddr_in	clt;
}			t_config;

void			my_memset(char *buff, int nb);
char			*get_next_line(int fd);
int			init_config(t_config *config, char *ip, char *port);
int			get_socket();
int			close_socket(t_config *config);
int			send_to_server(char *data, t_config *config);
int			recieve_from_server(t_config *config);
int			display(int *argc, char ***argv);
# endif /* CLIENT_H_ */ 
