/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkrifa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 23:28:25 by nkrifa            #+#    #+#             */
/*   Updated: 2017/10/04 23:42:53 by nkrifa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>

long long	convert_int_length(long long nb, t_params *params)
{
  if (params->length == HH)
    return ((char)nb);
  if (params->length == H)
    return ((short)nb);
  if (params->length == L)
    return ((long)nb);
  if (params->length == LL)
    return ((long long)nb);
  if (params->length == Z)
    return ((size_t)nb);
  if (params->length == J)
    return ((intmax_t)nb);
  if (params->length == T)
    return ((ptrdiff_t)nb);
  return ((int)nb);
}

void	my_putnbr(long long nb, int precision, int is_space, int is_plus)
{
  int	size_nb;

  size_nb = calc_int(nb);
  if (nb < 0)
  {
    ft_putchar('-');
    nb = -nb;
  }
  else if (nb >= 0 && (is_space == 1 || is_plus == 1))
  {
    if (is_plus == 1)
      ft_putchar('+');
    precision = precision - 1;
  }
  while (precision > size_nb)
  {
    ft_putchar('0');
    precision = precision - 1;
  }
  if (nb >= 10)
    my_putnbr(nb / 10, 0, size_nb, 0);
  ft_putchar((nb % 10) + '0');
}

void	begin_int(t_tmp_arg *tmp, t_params *params,
		  unsigned int *s_to_add, unsigned int *s_to_print)
{
  tmp->t_int = convert_int_length(tmp->t_int, params);
  *s_to_print = calc_size_to_print(tmp, 'd');
  if (*s_to_print < params->precision)
    *s_to_print = params->precision;
  if (params->space == 1 && params->plus == 0 && tmp->t_int >= 0)
    ft_putchar(' ');
  if (tmp->t_int < 0 && params->precision >= *s_to_print)
    *s_to_print = *s_to_print + 1;
  if ((params->plus == 1 || params->space == 1) && tmp->t_int >= 0)
    *s_to_print = *s_to_print + 1;
  if (*s_to_print < params->width)
    *s_to_add = params->width - *s_to_print;
  if (params->less == 1)
    my_putnbr(tmp->t_int, *s_to_print, params->space, params->plus);
}

void	inter_int(t_tmp_arg *tmp, t_params *params,
		  unsigned int *s_to_add, unsigned int *s_to_print)
{
  if (params->zero == 1 && params->is_precision == 0 && tmp->t_int < 0
      && params->less == 0)
  {
    ft_putchar('-');
    tmp->t_int = -(tmp->t_int);
    *s_to_print = *s_to_print - 1;
    params->plus = 0;
  }
  else if (params->zero == 1 && params->plus == 1 && params->less == 0
    && tmp->t_int >= 0)
  {
    if (params->less == 1)
      ft_putchar('+');
    if (params->less == 1)
      params->plus = 0;
    if (params->zero == 1 && params->plus == 0)
      *s_to_add = *s_to_add + 1;
    if (params->space == 0)
      *s_to_add = *s_to_add - 1;
  }
}

unsigned int	print_int(t_tmp_arg *tmp, t_params *params,
			  unsigned int s_to_add, unsigned int s_to_print)
{
  unsigned int	chars_written;

  chars_written = 0;
  begin_int(tmp, params, &s_to_add, &s_to_print);
  chars_written = s_to_print + s_to_add;
  inter_int(tmp, params, &s_to_add, &s_to_print);
  if (params->width >= params->precision && params->zero == 1
      && params->is_precision == 0 && params->less == 0
      && params->width > s_to_print)
    add_zero(s_to_add);
  else if (params->width >= (params->precision) && params->width > s_to_print)
    add_space(s_to_add);
  if (params->less == 0)
    my_putnbr(tmp->t_int, s_to_print, params->space, params->plus);
  return (chars_written);
}
