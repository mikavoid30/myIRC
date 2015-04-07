/*
** server.c for ftp server in /home/boulat_m/rendu/Projets_sem2/myftp/Server
** 
** Made by Mickael BOULAT
** Login   <boulat_m@epitech.net>
** 
** Started on  Mon Mar  9 17:49:13 2015 Mickael BOULAT
** Last update Tue Apr  7 16:45:31 2015 Mickael BOULAT
*/

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <strings.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include "server.h"

int	get_socket()
{
  int	fd;

  fd = socket(AF_INET, SOCK_STREAM, 0);
  if (fd == -1)
    perror("get_socket");
  else
    printf("Socket %d created\n", fd);
  return (fd);
}

int	close_sockets(t_config *config)
{
  int	error;
  int	error1;
  int	ret;

  ret = 0;
  error = close(config->socketFd);
  error1 = close(config->cSocketFd);
  if ((error == -1) || (error1 == -1))
    {
      perror("close_socket");
      ret = -1;
    }
  else
    {
      printf("Socket %d & %d closed\n", config->socketFd, config->cSocketFd);
    }  
  return (ret);
}

int	bind_socket(int socketFd, struct sockaddr *srv)
{
  int	error;

  error = bind(socketFd, srv, sizeof(struct sockaddr));
  if (error == -1)
    perror("bind_socket");
  else
    printf("Bind socket success\n");
  return (error);
}

int	listen_clients(t_config *config)
{
  int	error;

  error = 0;
  error = listen(config->socketFd, config->maxClients);
  if (error == -1)
    perror("listen_socket");
  else
    printf("Listening on %d port\n", config->port);
  return (error);
}

int	accept_clients(t_config *config)
{
  int	error;
  socklen_t	cltSize;

  error = 0;
  cltSize = sizeof (config->clt);
  config->cSocketFd = accept(config->socketFd, (struct sockaddr *) &config->clt, &cltSize);
  if (config->cSocketFd < 0)
    perror("accept_socket");
  else
    printf("Accept success\n");
  return (error);
}

int	init_config(t_config *config, char *port)
{
  int	status;

  status = EXIT_SUCCESS;
  config->port = atoi(port);
  config->maxClients = MAX_CLT;
  bzero((char *) &(config->srv), sizeof (config->srv));
  config->srv.sin_family = AF_INET;
  config->srv.sin_port = htons(config->port);
  config->srv.sin_addr.s_addr = htonl(INADDR_ANY);
  if ((config->socketFd = get_socket()) == -1)
    status = EXIT_FAILURE;
  status = bind_socket(config->socketFd, (struct sockaddr *) &(config->srv));
  return (status);
}

int	recieve_from_client(t_config *config)
{
  int	ret;
  int	size;
  char	buff[256];

  ret = 0;
  bzero(buff, 256);
  size = read(config->cSocketFd, buff, sizeof (buff));
  if (ret < 0)
    perror("recieve_from_client");
  else
    buff[size] = '\0';
  printf("Client send -> %s\n", buff);
  return (ret);
}

void	usage()
{
  printf("Usage : ./serveur port\n");
}

int		main(int ac, char **av)
{
  t_config	config;
  int		status;

  status = EXIT_SUCCESS;
  if (ac != 2)
    {
      usage();
      return (EXIT_FAILURE);
    }
  if ((init_config(&config, av[1])) == -1)
    return (EXIT_FAILURE);
 
  listen_clients(&config);
  while (1)
    { 
      accept_clients(&config);
      while (1)
	{
	  recieve_from_client(&config);
	}
    }
  if ((close_sockets(&config)) == -1)
    status = EXIT_FAILURE;
  return (status);
}
