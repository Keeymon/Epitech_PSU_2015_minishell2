/*
** my_printf_formatage.c for  in /home/picher_y/rendu/PSU_2015_my_printf/lib/my
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Thu Nov 12 00:38:14 2015 Yann Pichereau
** Last update Thu Nov 12 15:32:38 2015 Yann Pichereau
*/

#include <stdarg.h>

int	formatage(const char *format, int count, va_list *list, int *i)
{
  va_arg(list, void*);
  format = format;
  count = count;
  list = list;
  i = i;
  return (count);
}
