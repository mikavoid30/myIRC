/*
** get_next_line.c for get_next_line in /home/boulat_m/rendu/Projets/get_next_line/src
** 
** Made by Mickael BOULAT
** Login   <boulat_m@epitech.net>
** 
** Started on  Fri Nov 28 16:26:13 2014 Mickael BOULAT
** Last update Mon Mar 16 10:53:58 2015 Mickael BOULAT
*/

#include <stdlib.h>
#include <unistd.h>
#include "client.h"

void	my_memset(char *buff, int nb)
{
  int	i;

  i = 0;
  while (i <= nb)
    {
      buff[i] = '\0';
      i++;
    }
}

char			*get_next_line(int fd)
{
  char			*line;
  int			j;
  static int		i;
  static int		read_length = -1;
  static char		buff[LINE_SIZE];

    j = 0;
  if((line = malloc(LINE_SIZE + 1)) != 0)
    my_memset(line, (LINE_SIZE + 1));
  if(i < read_length)
    {
      while ((i < read_length) && (buff[i] != '\n'))
	line[j++] = buff[i++];
    }
  if ((i = 0) || (read_length = read(fd, buff, LINE_SIZE)) == 0)
    {
      free(line);
      return (0);
    }
  while ((i < read_length) && (buff[i] != '\n'))
    line[j++] = buff[i++];
  i++;
  return (line);
}
