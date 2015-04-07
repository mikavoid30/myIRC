/*
** server.c for ftp server in /home/boulat_m/rendu/Projets_sem2/myftp/Server
** 
** Made by Mickael BOULAT
** Login   <boulat_m@epitech.net>
** 
** Started on  Mon Mar  9 17:49:13 2015 Mickael BOULAT
** Last update Tue Apr  7 21:19:57 2015 Mickael BOULAT
*/

# include "client.h"

int	recievee_from_server(t_config *config)
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

void    print_prompt()
{
  printf("MyFuckingIRC ---$>");
}

void	usage()
{
  printf("Usage : ./client machine port\n");
}

int		main(int ac, char **av)
{
  t_config	config;
  int		status;
  int		i;

  i = 0;
  status = EXIT_SUCCESS;
  if (ac != 3)
    {
      usage();
      return (EXIT_FAILURE);
    }
  if ((init_config(&config, av[1], av[2])) == -1)
    return (EXIT_FAILURE);
  while (i < 10)
    {
      send_to_server(get_next_line(0), &config);
      recieve_from_server(&config);
      i++;
    }
  //  display(&ac, &av);
  if ((close_socket(&config)) == -1)
    status = EXIT_FAILURE;
  return (status);
}
