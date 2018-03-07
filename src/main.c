/*
** main.c for main in /home/lentz_f/rendu/projet/CPE_2015_Allum1
**
** Made by florian lentz
** Login   <lentz_f@epitech.net>
**
** Started on  Thu Jul 14 16:11:32 2016 florian lentz
** Last update Thu Jul 21 17:52:06 2016 florian lentz
*/

#include <stdlib.h>
#include "my.h"

void		print_allum(int tab, int space)
{
  int		i;
  int		j;

  i = 7 - tab;
  j = 0;
  my_putchar('*');
  while (j < space)
    {
      my_putchar(' ');
      j++;
    }
  while (tab > 0)
    {
      my_putchar('|');
      tab--;
    }
  while (j < i)
    {
      my_putchar(' ');
      j++;
    }
  my_putchar('*');
}

void		init_tab(int *tab)
{
  int		i;
  int		space;

  i = 0;
  space = 3;
  tab[0] = 1;
  tab[1] = 3;
  tab[2] = 5;
  tab[3] = 7;
  my_putstr("*********\n");
  while (i < 4)
    {
      print_allum(tab[i], space);
      my_putchar('\n');
      i++;
      space--;
     }
  my_putstr("*********\n");
}

int		player_loose(void)
{
  my_putstr("You lost, too bad..\n");
  return (0);
}

int		player_turn(int *line, int *matches, int *tab, int i)
{
  int		space;

  space = 3;
  if ((check_player_turn(line, matches, tab)) == -1)
    return (-1);
  my_putstr("Player removed ");
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
  return (0);
}

int		main(void)
{
  int		*tab;
  int		line;
  int		matches;

  if ((tab = malloc(LINE * MATCHES)) == NULL)
    return (1);
  init_tab(tab);
  while (1)
    {
      if ((player_turn(&line, &matches, tab, 0)) == -1)
	return (1);
      if (tab[0] == 0 && tab[1] == 0 && tab[2] == 0 && tab[3] == 0)
	{
	  player_loose();
	  return (0);
	}
      ai_turn(&line, &matches, tab, 0);
      if (tab[0] == 0 && tab[1] == 0 && tab[2] == 0 && tab[3] == 0)
	{
	  ai_loose();
	  return (0);
	}
    }
  free(tab);
  return (0);
}
