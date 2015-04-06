
/*
** server.c for ftp server in /home/boulat_m/rendu/Projets_sem2/myftp/Server
** 
** Made by Mickael BOULAT
** Login   <boulat_m@epitech.net>
** 
** Started on  Mon Mar  9 17:49:13 2015 Mickael BOULAT
** Last update Tue Mar 10 16:22:58 2015 Mickael BOULAT
*/

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <strings.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include "client.h"

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

int	close_socket(t_config *config)
{
  int	error;

  error = close(config->socketFd);
  if (error == -1)
      perror("close_socket");
  else
      printf("Socket %d closed\n", config->socketFd); 
  return (error);
}

int	init_config(t_config *config, char *ip, char *port)
{
  int	status;

  status = EXIT_SUCCESS;
  config->srv.sin_family = AF_INET;
  config->srv.sin_port = htons(atoi(port));
  config->srv.sin_addr.s_addr = inet_addr(ip);
  bzero(&(config->srv.sin_zero), 8);
  if ((config->socketFd = get_socket()) == -1)
    status = EXIT_FAILURE;
  if (connect(config->socketFd, (struct sockaddr *) &(config->srv), sizeof (struct sockaddr)) < 0)
    {
      perror("connect");
      status = EXIT_FAILURE;
    }
  else
    {
      printf("Client connected\n");
    }  
  return (status);
}

int	send_to_server(char *data, t_config *config)
{
  int	ret;
  int	size;

  ret = 0;
  size = strlen(data);
  ret = write(config->socketFd, data, size);
  if (ret < 0)
    perror("send_to_server");
  else
    printf("Data sent\n");
  return (ret);
}

int	recieve_from_server(t_config *config)
{
  int	ret;
  int	size;
  char	buff[BUFF_SIZE];

  ret = 0;
  size = recv(config->socketFd, buff, sizeof (buff) - 1, 0);
  if (ret < 0)
    perror("recieve_from_server");
  else
    buff[size] = '\0';
  printf("Server replies -> %s\n", buff);
  return (ret);
}
