/*
** get_next_line.h for gnl.h in /home/lentz_f/rendu/projet/CPE_2015_getnextline
**
** Made by florian lentz
** Login   <lentz_f@epitech.net>
**
** Started on  Mon Jun  6 13:24:18 2016 florian lentz
** Last update Thu Jul 14 18:47:46 2016 florian lentz
*/

#ifndef GET_NEXT_LINE_H_

# ifndef READ_SIZE
#  define READ_SIZE (1)
# endif /* !READ_SIZE */

# include <unistd.h>
# include <stdlib.h>

char		*init_function(char **line, int *count);
char		*my_realloc(char *str, int count);
void		end_function(char *line, int *count, int *index);
char		*get_next_line(const int fd);

#endif /* !GET_NEXT_LINE_H_ */
