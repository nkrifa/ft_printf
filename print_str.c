/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkrifa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 23:29:42 by nkrifa            #+#    #+#             */
/*   Updated: 2017/10/04 23:29:48 by nkrifa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
