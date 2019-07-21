/*
** my_strdup.c for my_strdup in /home/picher_y/rendu/PJ08/ex_01
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Wed Oct  7 23:19:14 2015 Yann Pichereau
** Last update Sun Dec  6 19:29:26 2015 Yann Pichereau
*/

#include <stdlib.h>
#include "my.h"

char	*my_strdup(char *src)
{
  int	size;
  char	*str;

  size = my_strlen(src);
  str = malloc(size + 1);
  str[size] = '\0';
  my_strcpy(str, src);
  return (str);
}
