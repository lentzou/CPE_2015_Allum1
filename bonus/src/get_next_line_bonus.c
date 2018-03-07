/*
** get_next_line.c for gnl.c in /home/lentz_f/rendu/projet/CPE_2015_getnextline
**
** Made by florian lentz
** Login   <lentz_f@epitech.net>
**
** Started on  Mon Jun  6 13:20:47 2016 florian lentz
** Last update Tue Jul 19 19:01:20 2016 florian lentz
*/

#include "get_next_line_bonus.h"

char		*init_function(char **line, int *count)
{
  if ((*line = my_realloc(*line, *count)) == NULL)
    return (NULL);
  return (*line);
}

char		*my_realloc(char *str, int count)
{
  int		i;
  char		*rea;

  i = 0;
  if (count == 0 && ((str = malloc(READ_SIZE + 1)) == NULL))
    return (NULL);
  if ((rea = malloc(count + READ_SIZE + 1)) == NULL)
    return (NULL);
  while (i <= count)
    {
      rea[i] = str[i];
      i++;
    }
  rea[i] = '\0';
  free(str);
  return (rea);
}

void		end_function(char *line, int *count, int *index)
{
  line[*count] = '\0';
  *index = 0;
}

char		*get_next_line(const int fd)
{
  static int	ret;
  static int	index;
  static int	count;
  static char	*line;
  static char	buffer[READ_SIZE];

  if (index == 0 && (ret = read(fd, buffer, READ_SIZE)) < 1)
    return (NULL);
  init_function(&line, &count);
  while (index < ret)
    {
      if (buffer[index] == '\n')
	{
	  index++;
	  line[count] = '\0';
	  count = 0;
	  return (line);
	}
      line[count] = buffer[index];
      index++;
      count++;
    }
  end_function(line, &count, &index);
  get_next_line(fd);
  return (line);
}
