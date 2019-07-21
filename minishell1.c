/*
** minishell1.c for  in /home/picher_y/rendu/PSU_2015_minishell1
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Tue Dec  1 18:13:15 2015 Yann Pichereau
** Last update Sun Dec  6 22:44:00 2015 Yann Pichereau
*/

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"
#include "mysh.h"
#include "my.h"

char	*search_bin(t_mysh *mysh)
{
  int	i;
  int	size;
  char	*pa;

  if (mysh->tab == NULL)
    return (NULL);
  if (access(mysh->tab[0], X_OK) == 0)
    return (my_strdup(mysh->tab[0]));
  else
    {
      i = 0;
      while (mysh->path[i] != NULL)
	{
	  size = my_strlen(mysh->path[i]) + 1 + my_strlen(mysh->tab[0]);
	  if ((pa = malloc(sizeof(char) * (size + 1))) == NULL)
	    return (NULL);
	  pa[size] = '\0';
	  my_strcat(my_strcat(my_strcpy(pa, mysh->path[i]), "/"), mysh->tab[0]);
	  if (access(pa, X_OK) == 0)
	    return (pa);
	  free(pa);
	  i++;
	}
    }
  return (NULL);
}

int	search_path(t_mysh *mysh)
{
  int	i;

  i = 0;
  while (mysh->envp != NULL && my_strncmp(mysh->envp[i], "PATH=", 5) != 0)
    i++;
  if (mysh->envp && my_strncmp(mysh->envp[i], "PATH=", 5) == 0)
    {
      if ((mysh->path =
	   my_str_to_wordtab_del(my_strdup(mysh->envp[i]) + 5, ':')) == NULL)
	return (1);
    }
  return (0);
}

void	init_tabfct(t_tabfct *tabfct)
{
  tabfct[0].builtin = "exit";
  tabfct[0].fctptr = &exit_sh;
  tabfct[1].builtin = "cd";
  tabfct[1].fctptr = &cd_sh;
  tabfct[2].builtin = "setenv";
  tabfct[2].fctptr = &setenv_sh;
  tabfct[3].builtin = "unsetenv";
  tabfct[3].fctptr = &unsetenv_sh;
}

int		builtin(t_mysh *mysh)
{
  t_tabfct	fct[4];
  int		i;

  i = 0;
  mysh->ret = 0;
  init_tabfct(fct);
  while (i < 4)
    {
      if (my_strcmp(fct[i].builtin, mysh->tab[0]) == 0)
	{
	  fct[i].fctptr(mysh);
	  return (0);
	}
      i++;
    }
  return (1);
}

int		main(int ac, char **av, char **envp)
{
  t_mysh	mysh;
  char		*str;

  ac = ac;
  av = av;
  mysh.envp = envp;
  if (search_path(&mysh) != 0)
    return (1);
  mysh.run = 1;
  my_printf("$>");
  while (mysh.run == 1 && (str = get_next_line(0)) != NULL)
    {
      shell(&mysh, str);
      if (mysh.run == 1)
	my_printf("$>");
    }
  free_tab(&mysh);
  return (mysh.ret);
}
