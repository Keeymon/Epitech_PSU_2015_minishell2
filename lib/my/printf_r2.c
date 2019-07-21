/*
** printf_r2.c for  in /home/picher_y/rendu/PSU_2015_my_printf/lib/my
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Sat Nov  7 23:24:10 2015 Yann Pichereau
** Last update Tue Nov 10 19:06:55 2015 Yann Pichereau
*/

#include <stdarg.h>
#include "my.h"

int	my_put_nbr_printf(va_list *list)
{
  int	count;

  count = my_put_nbr(va_arg(list, int));
  return (count);
}

int		my_putnbr_base_hex_printf(va_list *list)
{
  unsigned int	nb;
  int		count;

  nb = va_arg(list, unsigned int);
  count = my_putnbr_base_unsigned(nb, "0123456789ABCDEF");
  return (count);
}

int		my_putnbr_base_hex_min_printf(va_list *list)
{
  unsigned int	nb;
  int		count;

  nb = va_arg(list, unsigned int);
  count = my_putnbr_base_unsigned(nb, "0123456789abcdef");
  return (count);
}

int	my_putnbr_base_oct_printf(va_list *list)
{
  int	count;

  count = my_putnbr_base_unsigned(va_arg(list, unsigned int), "01234567");
  return (count);
}

int	my_putnbr_base_bin_printf(va_list *list)
{
  int	count;

  count = my_putnbr_base_unsigned(va_arg(list, unsigned int), "01");
  return (count);
}
