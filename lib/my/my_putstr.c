/*
** my_putstr.c for day04 in /home/picher_y/rendu/Piscine_C_J04
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Thu Oct  1 16:03:18 2015 Yann Pichereau
** Last update Tue Nov 10 18:38:10 2015 Yann Pichereau
*/

#include <unistd.h>
#include "my.h"

int	my_putstr(char *str)
{
  int	count;

  count = my_strlen(str);
  write(1, str, count);
  return (count);
}
