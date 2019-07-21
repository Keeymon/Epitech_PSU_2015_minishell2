/*
** mysh.h for  in /home/picher_y/rendu/PSU_2015_minishell1
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Sat Dec  5 21:15:26 2015 Yann Pichereau
** Last update Sun Dec  6 22:45:35 2015 Yann Pichereau
*/

#ifndef MYSH_H_
# define MYSH_H_

typedef struct	s_mysh
{
  char	**envp;
  char	**path;
  char	**tab;
  int	run;
  int	ret;
}		t_mysh;

typedef struct	s_tabfct
{
  char		*builtin;
  void		(*fctptr)(t_mysh *mysh);
}		t_tabfct;

void	shell(t_mysh *mysh, char *str);
char	**my_str_to_wordtab_del(char *str, char delimiter);
int	search_path(t_mysh *mysh);
char	*search_bin(t_mysh *mysh);
int	builtin(t_mysh *mysh);
void	exit_sh(t_mysh *mysh);
void	cd_sh(t_mysh *mysh);
void	setenv_sh(t_mysh *mysh);
void	unsetenv_sh(t_mysh *mysh);
void	free_tab(t_mysh *mysh);

#endif /* !MYSH_H_ */
