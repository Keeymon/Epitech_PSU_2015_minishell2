/*
** my_revstr.c for my_revstr in /home/picher_y/rendu/PJ06/ex_04
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Mon Oct  5 12:30:02 2015 Yann Pichereau
** Last update Sun Nov  8 02:22:09 2015 Yann Pichereau
*/

#include "my.h"

char	*my_revstr(char *str)
{
  int	incre;
  int	decre;

  incre = 0;
  decre = my_strlen(str) - 1;
  while (incre < decre - incre)
    {
      my_swap_char(&str[incre], &str[decre - incre]);
      incre++;
    }
  return (str);
}
