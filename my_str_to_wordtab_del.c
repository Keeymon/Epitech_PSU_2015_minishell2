/*
** my_str_to_wordtab_delimiter.c for  in /home/picher_y/rendu/PSU_2015_minishell1
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Sat Dec  5 20:42:11 2015 Yann Pichereau
** Last update Sun Dec  6 19:15:37 2015 Yann Pichereau
*/

#include <stdlib.h>
#include "my.h"

void	incre_wordtab_del(char *str, int size, char **tab)
{
  int	i;
  int	nb_word;

  i = 0;
  nb_word = 0;
  while (i < size)
    {
      if ((i == 0 && str[i] != '\0') ||
	  (i != 0 && str[i] != '\0' && str[i - 1] == '\0'))
	{
	  tab[nb_word] = &str[i];
	  nb_word++;
	}
      i++;
    }
  tab[nb_word] = NULL;
}

int	count_word_del(char *str, char delimiter)
{
  int	i;
  int	nb_word;

  i = 0;
  nb_word = 0;
  while (str[i] != '\0')
    {
      if ((i == 0 && str[i] != delimiter) ||
	  (i != 0 && str[i] != delimiter && str[i - 1] == '\0'))
	nb_word++;
      else if (str[i] == delimiter)
	str[i] = '\0';
      i++;
    }
  return (nb_word);
}

char	**my_str_to_wordtab_del(char *str, char delimiter)
{
  int	size;
  int	nb_word;
  char	**tab;

  size = my_strlen(str);
  nb_word = count_word_del(str, delimiter);
  if (size == 0 || nb_word == 0)
    return (NULL);
  if ((tab = malloc(sizeof(char *) * (nb_word + 1))) == NULL)
    return (NULL);
  incre_wordtab_del(str, size, tab);
  return (tab);
}
