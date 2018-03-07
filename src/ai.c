/*
** ai.c for ai in /home/lentz_f/rendu/projet/CPE_2015_Allum1
**
** Made by florian lentz
** Login   <lentz_f@epitech.net>
**
** Started on  Fri Jul 15 22:59:48 2016 florian lentz
** Last update Tue Jul 19 20:18:24 2016 florian lentz
*/

#include <stdlib.h>
#include "my.h"

void		check_line_ai(int *line, int *tab)
{
  (*line) = (rand() % 4) + 1;
  if (tab[*line - 1] == 0)
    {
      (*line) = (rand() % 4) + 1;
      return (check_line_ai(line, tab));
    }
}

void		check_matches_ai(int *line, int *matches, int *tab)
{
  (*matches) = (rand() % 7) + 1;
  if ((*matches) > tab[*line - 1])
    {
      check_line_ai(line, tab);
      (*matches) = (rand() % 7) + 1;
      return (check_matches_ai(line, matches, tab));
    }
}

int		ai_loose(void)
{
  my_putstr("I lost.. snif.. but I’ll get you next time!!\n");
  return (0);
}

void		ai_turn(int *line, int *matches, int *tab, int i)
{
  int		space;

  space = 3;
  my_putchar('\n');
  my_putstr("AI's turn...\n");
  check_line_ai(line, matches);
  check_matches_ai(line, matches, tab);
  my_putstr("AI removed ");
  my_putnbr(*matches);
  my_putstr(" match(es) from line ");
  my_putnbr(*line);
  my_putchar('\n');
  (*line)--;
  my_putstr("*********\n");
  while (i < 4)
    {
      if (*line == i)
	tab[*line] = tab[i] - (*matches);
      print_allum(tab[i], space);
      my_putchar('\n');
      i++;
      space--;
    }
  my_putstr("*********\n");
}
