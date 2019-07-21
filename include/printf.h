/*
** printf.h for  in /home/picher_y/rendu/PSU_2015_my_printf/lib/my
** 
** Made by Yann Pichereau
** Login   <picher_y@epitech.net>
** 
** Started on  Mon Nov  9 23:32:58 2015 Yann Pichereau
** Last update Thu Nov 12 00:48:07 2015 Yann Pichereau
*/

#ifndef PRINTF_H_
# define PRINTF_H_
# include <stdarg.h>

typedef struct	s_flag
{
  char		c;
  int		(*flag)(va_list*);
}		t_flag;

int	my_printf(const char *format, ...);
int	check_format(const char *format, int i);
int	display_format(const char *format, int count, int *i);
int	formatage(const char *format, int count, va_list *list, int *i);
int	my_putchar_printf(va_list *list);
int	my_put_nbr_printf(va_list *list);
int	my_put_nbr_u_printf(va_list *list);
int	my_putstr_printf(va_list *list);
int	my_putstr_s_printf(va_list *list);
int	my_show_address_printf(va_list *list);
int	my_putnbr_base_hex_printf(va_list *list);
int	my_putnbr_base_hex_min_printf(va_list *list);
int	my_putnbr_base_oct_printf(va_list *list);
int	my_putnbr_base_bin_printf(va_list *list);

#endif /* !PRINTF_H_ */
