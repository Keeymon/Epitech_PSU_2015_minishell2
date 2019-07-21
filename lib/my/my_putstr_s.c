/*
** my_putstr_s.c for  in /home/picher_y/rendu/PSU_2015_my_printf/lib/my
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Sun Nov  8 00:49:20 2015 Yann Pichereau
** Last update Tue Nov 10 18:38:35 2015 Yann Pichereau
*/

#include "my.h"

int	my_putstr_s(char *str)
{
  int	i;
  int	count;

  count = 0;
  i = 0;
  while (str[i] != '\0')
    {
      if (my_char_isprintable(str[i]) == 0)
	{
	  my_putchar('\\');
	  if (str[i] <= 7)
	    my_putstr("00");
	  else if (str[i] >= 8 && str[i] <= 63)
	    my_putchar('0');
	  my_putnbr_base(str[i], "01234567");
	  count += 3;
	}
      else
	my_putchar(str[i]);
      i++;
      count++;
    }
  return (count);
}
