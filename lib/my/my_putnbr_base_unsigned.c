/*
** my_putnbr_base_unsgned.c for  in /home/picher_y/rendu/PSU_2015_my_printf/lib/my
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Tue Nov 10 18:25:10 2015 Yann Pichereau
** Last update Tue Nov 10 18:46:35 2015 Yann Pichereau
*/

#include "my.h"

int		my_putnbr_base_unsigned(unsigned int nbr, char *base)
{
  unsigned int	div;
  unsigned int	n_base;
  int		result;
  int		count;

  div = 1;
  count = 0;
  n_base = my_strlen(base);
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
