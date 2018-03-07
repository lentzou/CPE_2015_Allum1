/*
** main.c for main in /home/lentz_f/rendu/projet/CPE_2015_Allum1
**
** Made by florian lentz
** Login   <lentz_f@epitech.net>
**
** Started on  Thu Jul 14 16:11:32 2016 florian lentz
** Last update Tue Jul 19 21:55:09 2016 florian lentz
*/

#include <stdlib.h>
#include "my_bonus.h"

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

  space = 3;
  i = 0;
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

int		player1_loose(void)
{
  my_putstr("Player 1 lost, too bad..\n");
  return (0);
}

void		player1_turn(int *line, int *matches, int *tab, int i)
{
  int		space;

  space = 3;
  check_player1_turn(line, matches, tab);
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
}

int		main(void)
{
  int		recept;
  int		tab;
  int		line;
  int		matches;

  my_putstr("What do you want ?\n");
  my_putstr("Player vs player, enter : 1\n");
  my_putstr("Player vs ai, enter : 2\n");
  my_putstr("Please enter your choice : ");
  check_choice(&recept);
  if (recept == 1)
    player_vs_player(&line, &matches, &tab);
  if (recept == 2)
    player_vs_ai(&line, &matches, &tab);
  return (0);
}
