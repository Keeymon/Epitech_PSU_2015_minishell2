/*
** shell.c for  in /home/picher_y/rendu/PSU_2015_minishell1
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Sun Dec  6 22:35:04 2015 Yann Pichereau
** Last update Sun Dec  6 22:47:09 2015 Yann Pichereau
*/

#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include "mysh.h"
#include "my.h"

void	shell(t_mysh *mysh, char *str)
{
  char	*path;
  int	status;

  if ((mysh->tab = my_str_to_wordtab_del(str, ' ')) != NULL)
    {
      if (builtin(mysh) == 1)
	{
	  path = search_bin(mysh);
	  if (path != NULL)
	    {
	      if (fork() == 0)
		execve(path, mysh->tab, mysh->envp);
	      wait(&status);
	      free(path);
	    }
	  else
	    my_printf("%s: Command not found.\n", mysh->tab[0]);
	}
      free(str);
    }
}
