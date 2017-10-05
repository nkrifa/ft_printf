/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkrifa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 23:28:06 by nkrifa            #+#    #+#             */
/*   Updated: 2017/10/04 23:28:20 by nkrifa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

unsigned int	print_percent(void)
{
	ft_putchar('%');
	return (1);
}

unsigned int	print_char(t_tmp_arg *tmp, t_params *params,
		unsigned int s_to_add,
		unsigned int s_to_print)
{
	unsigned int	chars_written;

	chars_written = 0;
	tmp->t_int = (unsigned char)tmp->t_int;
	s_to_print = 1;
	if (s_to_print < params->width)
		s_to_add = params->width - s_to_print;
	chars_written = s_to_print + s_to_add;
	if (params->less == 1)
		ft_putchar(tmp->t_int);
	if (params->width >= s_to_print)
		add_space(s_to_add);
	if (params->less == 0)
		ft_putchar(tmp->t_int);
	return (chars_written);
}
