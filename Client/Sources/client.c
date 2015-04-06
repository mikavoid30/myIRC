
/*
** server.c for ftp server in /home/boulat_m/rendu/Projets_sem2/myftp/Server
** 
** Made by Mickael BOULAT
** Login   <boulat_m@epitech.net>
** 
** Started on  Mon Mar  9 17:49:13 2015 Mickael BOULAT
** Last update Mon Mar 16 11:06:38 2015 Mickael BOULAT
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

void	printf_color(char *data, char *color, int bold)
{
  if (!bold)
    printf("%s %s %s\n", color, data, INIT);
  else
    printf("%s %s %s %s\n", color, BOLD, data, INIT);
}

void    print_prompt(char *color)
{
  printf_color("My FTP", color, 1);
  printf_color(" $>", CYAN, 1);
}

void	usage()
{
  printf("Usage : ./client machine port data\n");
}

int		main(int ac, char **av)
{
  t_config	config;
  int		status;
  char		*command;

  status = EXIT_SUCCESS;
  if (ac != 4)
    {
      usage();
      return (EXIT_FAILURE);
    }
  if ((init_config(&config, av[1], av[2])) == -1)
    return (EXIT_FAILURE);
  send_to_server(av[3], &config);
  while (1)
    {
      print_prompt(GREEN);
    
      if ((command = get_next_line(1)) == NULL)
	{
	  printf("\n");
	}
      if (strlen(command) > 1)
	{
	  printf_color(command, MAGENTA, 1);
	  
	}
    }
  if ((close_socket(&config)) == -1)
    status = EXIT_FAILURE;
  return (status);
}
