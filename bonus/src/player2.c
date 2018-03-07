/*
** player2.c for player2 in /home/lentz_f/rendu/projet/CPE_2015_Allum1
**
** Made by florian lentz
** Login   <lentz_f@epitech.net>
**
** Started on  Tue Jul 19 21:43:15 2016 florian lentz
** Last update Tue Jul 19 22:04:37 2016 florian lentz
*/

#include "my_bonus.h"

int		player_loose(void)
{
  my_putstr("You lost, too bad..\n");
  return (0);
}

void		check_player_turn(int *line, int *matches, int *tab)
{
  my_putchar('\n');
  my_putstr("Your turn:\nLine: ");
  check_error_line(line, tab);
  my_putstr("Matches: ");
  check_error_matches(line, matches, tab);
  check_error_tab(line, matches, tab);
}

void		check_player2_turn(int *line, int *matches, int *tab)
{
  my_putchar('\n');
  my_putstr("Player 2 turn:\nLine: ");
  check_error_line(line, tab);
  my_putstr("Matches: ");
  check_error_matches(line, matches, tab);
  check_error_tab(line, matches, tab);
}

int		player2_loose(void)
{
  my_putstr("Player 2 lost, too bad..\n");
  return (0);
}

void		player2_turn(int *line, int *matches, int *tab, int i)
{
  int		space;

  space = 3;
  check_player2_turn(line, matches, tab);
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
