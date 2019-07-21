/*
** my_putnbr_base.c for my_putnbr_base in /home/picher_y/rendu/PJ06/ex_16
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Tue Oct  6 13:07:19 2015 Yann Pichereau
** Last update Tue Nov 10 18:35:53 2015 Yann Pichereau
*/

#include "my.h"

int		my_putnbr_base(int nbr, char *base)
{
  unsigned int	count;
  int		n_base;
  int		div;
  int		result;

  div = 1;
  count = 0;
  n_base = my_strlen(base);
  if (nbr < 0)
    {
      my_putchar('-');
      nbr *= -1;
    }
  while (nbr / div >= n_base)
    div *= n_base;
  while (div > 0)
    {
      result = (nbr / div) % n_base;
      my_putchar(base[result]);
      div /= n_base;
      count++;
    }
  return (count);
}
