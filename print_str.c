/*
** print_char.c for my_printf in /home/chapui_s/travaux/my_printf/new
**
** Made by chapui_s
** Login   <chapui_s@epitech.net>
**
** Started on  Sat Nov 16 18:53:44 2013 chapui_s
** Last update Sun Nov 17 01:46:55 2013 chapui_s
*/

#include "my_printf.h"

void		my_putstr(char *str)
{
  unsigned int	i;

  i = 0;
  while (str[i])
  {
    ft_putchar(str[i]);
    i = i + 1;
  }
}

void		put_n_str(char *str, unsigned int n)
{
  unsigned int	i;

  i = 0;
  while (str[i] && i < n)
  {
    ft_putchar(str[i]);
    i = i + 1;
  }
}

unsigned int	print_str(t_tmp_arg *tmp, t_params *params,
			  unsigned int s_to_add, unsigned int s_to_print)
{
  unsigned int	chars_written;

  chars_written = 0;
  if (params->is_precision == 1
      && params->precision <= my_strlen(tmp->t_char))
    s_to_print = params->precision;
  else
    s_to_print = my_strlen(tmp->t_char);
  if (s_to_print < params->width)
    s_to_add = params->width - s_to_print;
  chars_written = s_to_print + s_to_add;
  if (params->less == 1)
    put_n_str(tmp->t_char, s_to_print);
  if (params->width >= s_to_print)
    add_space(s_to_add);
  if (params->less == 0)
    put_n_str(tmp->t_char, s_to_print);
  return (chars_written);
}
