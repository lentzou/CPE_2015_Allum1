/*
** check_error.c for check_error in /home/lentz_f/rendu/projet/CPE_2015_Allum1
**
** Made by florian lentz
** Login   <lentz_f@epitech.net>
**
** Started on  Tue Jul 19 16:00:12 2016 florian lentz
** Last update Tue Jul 19 19:05:02 2016 florian lentz
*/

#include "my_bonus.h"

void		check_error_line(int *line, int *tab)
{
  char		*str;

  str = get_next_line(0);
  if ((*line = my_getnbr(str)) < 0)
    {
      my_putstr("Error: invalid input (positive number expected)\nLine: ");
      return (check_error_line(line, tab));
    }
  if ((*line = my_getnbr(str)) == 0 || (*line = my_getnbr(str)) > 4)
    {
      my_putstr("Error: this line is out of range\nLine: ");
      return (check_error_line(line, tab));
    }
  if (tab[*line - 1] == 0)
    {
      my_putstr("Error: this line is empty\nLine: ");
      return (check_error_line(line, tab));
    }
}

void		check_error_matches(int *line, int *matches, int *tab)
{
  char		*str;

  str = get_next_line(0);
  if ((*matches = my_getnbr(str)) < 0)
    {
      my_putstr("Error: invalid input (positive number expected)\nLine: ");
      check_error_line(line, tab);
      my_putstr("Matches: ");
      return (check_error_matches(line, matches, tab));
    }
  if ((*matches = my_getnbr(str)) == 0)
    {
      my_putstr("Error: you have to remove at least one match\nLine: ");
      check_error_line(line, tab);
      my_putstr("Matches: ");
      return (check_error_matches(line, matches, tab));
    }
  if ((*matches = my_getnbr(str)) > 7)
    {
      my_putstr("Error: not enough matches on this line\nLine: ");
      check_error_line(line, tab);
      my_putstr("Matches: ");
      return (check_error_matches(line, matches, tab));
    }
}

void		check_error_tab(int *line, int *matches, int *tab)
{
  if ((*matches) > tab[*line - 1])
    {
      my_putstr("Error: not enought matches on this line\nLine: ");
      check_error_line(line, tab);
      my_putstr("Matches: ");
      check_error_matches(line, matches, tab);
      return (check_error_tab(line, matches, tab));
    }
}
