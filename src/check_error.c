/*
** check_error.c for check_error in /home/lentz_f/rendu/projet/CPE_2015_Allum1
**
** Made by florian lentz
** Login   <lentz_f@epitech.net>
**
** Started on  Tue Jul 19 16:00:12 2016 florian lentz
** Last update Sat Jul 23 14:56:49 2016 florian lentz
*/

#include <stdlib.h>
#include "my.h"

int		check_player_turn(int *line, int *matches, int *tab)
{
  my_putchar('\n');
  my_putstr("Your turn:\nLine: ");
  if ((check_error_line(line, tab)) == -1)
    return (-1);
  my_putstr("Matches: ");
  if ((check_error_matches(line, matches, tab)) == -1)
    return (-1);
  else if ((check_error_tab(line, matches, tab)) == -1)
    return (-1);
  return (0);
}

int		check_error_line(int *line, int *tab)
{
  char		*str;

  if ((str = get_next_line(0)) == NULL)
    return (-1);
  if (str[0] == '\0')
    return (-1);
  if ((*line = my_getnbr(str)) < 0)
    {
      my_putstr("Error: invalid input (positive number expected)\nLine: ");
      return (check_error_line(line, tab));
    }
  else if ((*line = my_getnbr(str)) == 0 || (*line = my_getnbr(str)) > 4)
    {
      my_putstr("Error: this line is out of range\nLine: ");
      return (check_error_line(line, tab));
    }
  else if (tab[*line - 1] == 0)
    {
      my_putstr("Error: this line is empty\nLine: ");
      return (check_error_line(line, tab));
    }
  return (0);
}

int		check_error_m2(int *line , int *matches, int *tab, char *str)
{
  if ((*matches = my_getnbr(str)) < 0)
    {
      my_putstr("Error: invalid input (positive number expected)\nLine: ");
      if ((check_error_line(line, tab)) == -1)
	return (-1);
      my_putstr("Matches: ");
      return (check_error_matches(line, matches, tab));
    }
  return (0);
}

int		check_error_matches(int *line, int *matches, int *tab)
{
  char		*str;

  if ((str = get_next_line(0)) == NULL)
    return (-1);
  if (str[0] == '\0')
    return (-1);
  if ((check_error_m2(line, matches, tab, str)) == -1)
    return (-1);
  else if ((*matches = my_getnbr(str)) == 0)
    {
      my_putstr("Error: you have to remove at least one match\nLine: ");
      if ((check_error_line(line, tab)) == -1)
	return (-1);
      my_putstr("Matches: ");
      return (check_error_matches(line, matches, tab));
    }
  else if ((*matches = my_getnbr(str)) > 7)
    {
      my_putstr("Error: not enough matches on this line\nLine: ");
      if ((check_error_line(line, tab)) == -1)
	return (-1);
      my_putstr("Matches: ");
      return (check_error_matches(line, matches, tab));
    }
  return (0);
}

int		check_error_tab(int *line, int *matches, int *tab)
{
  if ((*matches) > tab[*line - 1])
    {
      my_putstr("Error: not enought matches on this line\nLine: ");
      if ((check_error_line(line, tab)) == -1)
	return (-1);
      my_putstr("Matches: ");
      if ((check_error_matches(line, matches, tab)) == -1)
	return (-1);
      return (check_error_tab(line, matches, tab));
    }
  return (0);
}
