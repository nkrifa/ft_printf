/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkrifa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 23:30:15 by nkrifa            #+#    #+#             */
/*   Updated: 2017/10/04 23:30:21 by nkrifa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stddef.h>

void	stock_arg(va_list *arg, t_tmp_arg *tmp, char c)
{
  tmp->uint = 0;
  tmp->t_int = 0;
  tmp->t_char = NULL;
  tmp->ptr = NULL;
  tmp->chars_to_save = NULL;

  if (c == 's' || c == 'S')
    tmp->t_char = va_arg(*arg, char *);
  else if (c == 'p')
    tmp->ptr = va_arg(*arg, void *);
  else if (c == 'c' || c == 'd' || c == 'i')
    tmp->t_int = va_arg(*arg, long long);
  else if (c == 'n')
    tmp->chars_to_save = va_arg(*arg, unsigned int *);
  else
    tmp->uint = va_arg(*arg, unsigned long long);
}
