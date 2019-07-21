/*
** builtin.c for  in /home/picher_y/rendu/PSU_2015_minishell1
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Sun Dec  6 20:39:49 2015 Yann Pichereau
** Last update Sun Dec  6 23:33:00 2015 Yann Pichereau
*/

#include <unistd.h>
#include <stdlib.h>
#include "mysh.h"
#include "my.h"

void	exit_sh(t_mysh *mysh)
{
  my_printf("exit\n");
  if (mysh->tab[1] != NULL)
    mysh->ret = my_getnbr(mysh->tab[1]);
  else
    mysh->ret = 0;
  mysh->run = 0;
}

void	cd_sh(t_mysh *mysh)
{
  int	i;

  i = 0;
  if (mysh->tab[1] == NULL)
    {
      while (mysh->envp && my_strncmp(mysh->envp[i], "HOME=", 5) != 0)
	i++;
      if (chdir(mysh->envp[i] + 5) == -1)
	my_printf("%s: No such file or directory.\n", mysh->tab[1]);
    }
  else if (mysh->tab[1] != NULL && my_strncmp(mysh->tab[1], "-", 1) == 0)
    {
      while (mysh->envp && my_strncmp(mysh->envp[i], "OLDPWD=", 7) != 0)
	i++;
      if (chdir(mysh->envp[i] + 7) == -1)
	my_printf("%s: No such file or directory.\n", mysh->tab[1]);
    }
  else if (chdir(mysh->tab[1]) == -1)
    my_printf("%s: No such file or directory.\n", mysh->tab[1]);
}

void	setenv_sh(t_mysh *mysh)
{
  int	i;
  int	size;
  char	*str;

  i = 0;
  size = my_strlen(mysh->tab[1]);
  while (mysh->envp && my_strncmp(mysh->envp[i], mysh->tab[1], size) != 0)
    i++;
  if (mysh->tab[2] != NULL)
    {
      size = my_strlen(mysh->tab[2]) + 1;
      if ((str = malloc(sizeof(char) * (size + 1))) == NULL)
	mysh->ret = 1;
      str[size] = '\0';
      my_strcpy(str, mysh->tab[1]);
      my_strcat(str, "=");
      my_strcat(str, mysh->tab[2]);
    }
  mysh->envp[i] = str;
}

void	unsetenv_sh(t_mysh *mysh)
{
  (void)mysh->tab;
}
