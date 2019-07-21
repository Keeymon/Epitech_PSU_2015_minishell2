/*
** my_show_address_2.c for  in /home/picher_y/rendu/PSU_2015_my_printf/lib/my
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Mon Nov  9 19:14:10 2015 Yann Pichereau
** Last update Tue Nov 10 18:39:50 2015 Yann Pichereau
*/

#include "my.h"

int	my_show_address_2(void *add)
{
  int	count;
  long	nbr;
  long	div;
  char	*base;
  int	result;

  base = "0123456789abcdef";
  count = 0;
  div = 1;
  nbr = (long)(add);
  while (nbr / div >= 16)
    div *= 16;
  while (div > 0)
    {
      result = (nbr / div) % 16;
      my_putchar(base[result]);
      div /= 16;
      count++;
    }
  return (count);
}
