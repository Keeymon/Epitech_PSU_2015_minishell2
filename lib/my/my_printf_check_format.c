/*
** my_printf_format.c for  in /home/picher_y/rendu/PSU_2015_my_printf/lib/my
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Wed Nov 11 23:45:46 2015 Yann Pichereau
** Last update Mon Nov 16 17:55:03 2015 Yann Pichereau
*/

#include "my.h"

int	check_setting(char c)
{
  char	*setting;

  setting = "#-+.$*";
  while (*setting)
    {
      if (*setting == c)
	return (1);
      setting++;
    }
  return (0);
}

int	check_flag(char c)
{
  char	*flag;

  flag = "csSdiuXxobp";
  while (*flag)
    {
      if (*flag == c)
	return (1);
      flag++;
    }
  return (0);
}

int	check_format(const char *format, int i)
{
  while (check_setting(format[i]) == 1 || my_char_isnum(format[i]) == 1 ||
	 (format[i] == ' ' &&
	  (my_char_isnum(format[i + 1]) == 1 || check_flag(format[i + 1]) == 1)))
    i++;
  if (check_flag(format[i]) != 1)
    return (0);
  return (1);
}

int	display_format(const char *format, int count, int *i)
{
  int	j;

  j = *i;
  my_putchar('%');
  while (check_setting(format[j]) == 1 || my_char_isnum(format[j]) == 1 ||
	 (format[j] == ' ' &&
	  (my_char_isnum(format[j + 1]) == 1 || check_flag(format[j + 1]) == 1)))
    {
      my_putchar(format[j]);
      count++;
      j++;
    }
  my_putchar(format[j]);
  count += 2;
  *i = j;
  return (count);
}
