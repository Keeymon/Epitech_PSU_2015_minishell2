/*
** my_str_isnum.c for my_str_isnum in /home/picher_y/rendu/PJ06/ex_12
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Tue Oct  6 11:03:02 2015 Yann Pichereau
** Last update Thu Nov 12 00:02:45 2015 Yann Pichereau
*/

int	my_str_isnum(char *str)
{
  while (*str != '\0')
    {
      if (*str < '0' || *str > '9')
	return (0);
      str++;
    }
  return (1);
}
