/*
** get_next_line.h for  in /home/picher_y/rendu/CPE_2015_get_next_line
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Tue Nov 24 15:57:30 2015 Yann Pichereau
** Last update Sat Dec  5 23:58:59 2015 Yann Pichereau
*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_
# ifndef READ_SIZE
#  define READ_SIZE (4096)
# endif /* !READ_SIZE */

typedef struct	s_line
{
  int		index;
  int		nb;
  int		len;
  int		end;
  char		*buff;
}		t_line;

char	*get_next_line(const int fd);

#endif /* !GET_NEXT_LINE_H_ */
