/*
** server.c for ftp server in /home/boulat_m/rendu/Projets_sem2/myftp/Server
** 
** Made by Mickael BOULAT
** Login   <boulat_m@epitech.net>
** 
** Started on  Mon Mar  9 17:49:13 2015 Mickael BOULAT
** Last update Tue Apr  7 16:26:23 2015 Mickael BOULAT
*/

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
      i++;
    }
  //  display(&ac, &av);
  if ((close_socket(&config)) == -1)
    status = EXIT_FAILURE;
  return (status);
}
