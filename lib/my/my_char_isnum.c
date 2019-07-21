/*
** my_char_isnum.c for  in /home/picher_y/rendu/PSU_2015_my_printf/lib/my
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Thu Nov 12 00:03:25 2015 Yann Pichereau
** Last update Thu Nov 12 00:04:32 2015 Yann Pichereau
*/

int	my_char_isnum(char c)
{
  if (c < '0' || c > '9')
    return (0);
  return (1);
}
