/*
** bonus.c for bonus in /home/lentz_f/rendu/projet/CPE_2015_Allum1/bonus
**
** Made by florian lentz
** Login   <lentz_f@epitech.net>
**
** Started on  Tue Jul 19 19:15:00 2016 florian lentz
** Last update Tue Jul 19 22:07:53 2016 florian lentz
*/

#include <stdlib.h>
#include "my_bonus.h"

void		check_choice(int *recept)
{
  char		*str;

  str = get_next_line(0);
  if ((*recept = my_getnbr(str)) < 1 || (*recept = my_getnbr(str)) > 2)
    {
      my_putstr("Please choose only 1 or 2\n");
      my_putstr("Please enter your choice : ");
      return (check_choice(recept));
    }
}

void		check_player1_turn(int *line, int *matches, int *tab)
{
  my_putchar('\n');
  my_putstr("Player 1 turn:\nLine: ");
  check_error_line(line, tab);
  my_putstr("Matches: ");
  check_error_matches(line, matches, tab);
  check_error_tab(line, matches, tab);
}

int		player_vs_player(int *line, int *matches, int *tab)
{
  if ((tab = malloc(LINE * MATCHES)) == NULL)
    return (-1);
  init_tab(tab);
  while (1)
    {
      player1_turn(line, matches, tab, 0);
      if (tab[0] == 0 && tab[1] == 0 && tab[2] == 0 && tab[3] == 0)
        {
          player1_loose();
          return (0);
        }
      player2_turn(line, matches, tab, 0);
      if (tab[0] == 0 && tab[1] == 0 && tab[2] == 0 && tab[3] == 0)
        {
          player2_loose();
          return (0);
        }
    }
}

int		player_vs_ai(int *line, int *matches, int *tab)
{
  if ((tab = malloc(LINE * MATCHES)) == NULL)
    return (-1);
  init_tab(tab);
  while (1)
    {
      player_turn(line, matches, tab, 0);
      if (tab[0] == 0 && tab[1] == 0 && tab[2] == 0 && tab[3] == 0)
        {
          player_loose();
          return (0);
        }
      ai_turn(line, matches, tab, 0);
      if (tab[0] == 0 && tab[1] == 0 && tab[2] == 0 && tab[3] == 0)
        {
          ai_loose();
          return (0);
        }
    }
}

void		player_turn(int *line, int *matches, int *tab, int i)
{
  int		space;

  space = 3;
  check_player_turn(line, matches, tab);
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
