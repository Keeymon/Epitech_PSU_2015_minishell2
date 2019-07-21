/*
** free_tab.c for  in /home/picher_y/rendu/PSU_2015_minishell1
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Sun Dec  6 22:22:27 2015 Yann Pichereau
** Last update Sun Dec  6 22:33:08 2015 Yann Pichereau
*/

#include <stdlib.h>
#include "mysh.h"

void	free_tab(t_mysh *mysh)
{
  free(mysh->tab);
  free(mysh->path);
}
