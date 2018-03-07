/*
** functions.c for functions in /home/lentz_f/rendu/projet/PSU_2015_minitalk
**
** Made by florian lentz
** Login   <lentz_f@epitech.net>
**
** Started on  Mon Jul 11 18:02:44 2016 florian lentz
** Last update Tue Jul 19 21:35:36 2016 florian lentz
*/

#include <unistd.h>
#include "my_bonus.h"

void		my_putchar(char c)
{
  write(1, &c, 1);
}

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

void		my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}

void		my_putnbr(int nb)
{
  if (nb < 0)
    {
      my_putchar('-');
      nb = nb * - 1;
    }
  if (nb <= 9)
    my_putchar(nb + 48);
  if (nb > 9)
    {
      my_putnbr(nb / 10);
      my_putnbr(nb % 10);
    }
}

int		my_getnbr(char *str)
{
  int		i;
  int		nb;

  i = 0;
  nb = 0;
  if (str == NULL || str[0] == 0)
    return (-1);
  while (str[i])
    {
      nb = nb * 10 + (str[i] - 48);
      i++;
    }
  return (nb);
}
