/*
** my_put_nbr_unsigned.c for  in /home/picher_y/rendu/PSU_2015_my_printf/lib/my
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Sun Nov  8 16:49:18 2015 Yann Pichereau
** Last update Tue Nov 10 18:37:01 2015 Yann Pichereau
*/

#include "my.h"

int		my_put_nbr_unsigned(unsigned int nb)
{
  unsigned int	nb_tmp;
  unsigned int	div;
  int		count;

  div =1;
  count = 0;
  nb_tmp = nb;
  while (nb_tmp > 9)
    {
      nb_tmp /= 10;
      div *= 10;
    }
  while (div >= 1)
    {
      my_putchar(nb / div % 10 + '0');
      div /= 10;
      count++;
    }
  return (count);
}
