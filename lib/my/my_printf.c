/*
** my_printf.c for my_printf in /home/picher_y/rendu/PSU_2015_my_printf
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Tue Nov  3 17:06:42 2015 Yann Pichereau
** Last update Thu Nov 12 00:47:51 2015 Yann Pichereau
*/

#include <stdlib.h>
#include <stdarg.h>
#include "my.h"

static const t_flag	g_flag[] =
{
  {'c', &my_putchar_printf},
  {'s', &my_putstr_printf},
  {'S', &my_putstr_s_printf},
  {'d', &my_put_nbr_printf},
  {'i', &my_put_nbr_printf},
  {'u', &my_put_nbr_u_printf},
  {'X', &my_putnbr_base_hex_printf},
  {'x', &my_putnbr_base_hex_min_printf},
  {'o', &my_putnbr_base_oct_printf},
  {'b', &my_putnbr_base_bin_printf},
  {'p', &my_show_address_printf},
  {0, NULL}
};

int	modulo()
{
  return (my_putchar('%'));
}

int	modulo_n(va_list *list, int count)
{
  int	*n;

  n = va_arg(list, int *);
  *n = count;
  return (count);
}

int	flag(const char *format, int count, va_list *list, int *i)
{
  int		j;

  j = 0;
  while (j < 12)
    {
      if (g_flag[j].c == format[*i])
	{
	  count += g_flag[j].flag(list);
	  j = 12;
	}
      j++;
    }
  if (j == 12)
    {
      if (check_format(format, *i) == 1)
	count += formatage(format, count, list, i);
      else
	count += display_format(format, count, i);
    }
  return (count);
}

int		my_printf(const char *format, ...)
{
  va_list	list;
  int		i;
  int		count;

  i = 0;
  count = 0;
  va_start(list, format);
  while (format[i] != '\0')
    {
      if (format[i] != '%')
	count += my_putchar(format[i]);
      else
	{
	  i++;
	  if (format[i] == '%')
	    count += modulo();
	  else if (format[i] == 'n')
	    count += modulo_n(&list, count);
	  else
	    count += flag(format, count, &list, &i);
	}
      i++;
    }
  va_end(list);
  return (count);
}
