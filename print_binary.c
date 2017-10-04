/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_binary.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkrifa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 23:27:50 by nkrifa            #+#    #+#             */
/*   Updated: 2017/10/04 23:28:01 by nkrifa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	print_binary(t_tmp_arg *tmp, t_params *params,
		unsigned int s_to_add,
		unsigned int s_to_print)
{
	unsigned int	chars_written;

	chars_written = 0;
	tmp->uint = convert_uint_length(tmp->uint, params);
	s_to_print = calc_size_to_print(tmp, 'b');
	if (s_to_print < params->precision)
		s_to_print = params->precision;
	if (s_to_print < params->width)
		s_to_add = params->width - s_to_print;
	chars_written = s_to_print + s_to_add;
	if (params->less == 1)
		my_put_unsigned_nb(tmp->uint, s_to_print, "01");
	if (params->width >= params->precision && params->zero == 1
			&& params->is_precision == 0 && params->less == 0
			&& params->width > s_to_print)
		add_zero(s_to_add);
	else if (params->width >= (params->precision)
			&& params->width > s_to_print)
		add_space(s_to_add);
	if (params->less == 0)
		my_put_unsigned_nb(tmp->uint, s_to_print, "01");
	return (chars_written);
}
