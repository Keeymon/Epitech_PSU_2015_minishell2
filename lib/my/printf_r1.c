/*
** printf_r1.c for  in /home/picher_y/rendu/PSU_2015_my_printf/lib/my
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Sat Nov  7 18:43:08 2015 Yann Pichereau
** Last update Tue Nov 10 18:40:57 2015 Yann Pichereau
*/

#include <stdarg.h>
#include "my.h"

int	my_putchar_printf(va_list *list)
{
  my_putchar(va_arg(list, int));
  return (1);
}

int	my_putstr_printf(va_list *list)
{
  int	count;
  void	*str;

  str = va_arg(list, char *);
  if (str == 0)
    {
      my_putstr("(null)");
      count = 6;
    }
  else
    count = my_putstr(str);
  return (count);
}

int	my_putstr_s_printf(va_list *list)
{
  int	count;

  count = my_putstr_s(va_arg(list, char *));
  return (count);
}

int	my_show_address_printf(va_list *list)
{
  int	count;
  void	*add;

  add = va_arg(list, void *);
  if (add == 0)
    {
      my_putstr("(nil)");
      count = 3;
    }
  else
    {
      my_putstr("0x");
      count = my_show_address_2(add);
    }
  return (count + 2);
}

int	my_put_nbr_u_printf(va_list *list)
{
  int	count;

  count = my_put_nbr_unsigned(va_arg(list, unsigned int));
  return (count);
}
