/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_chars_written.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkrifa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 23:30:05 by nkrifa            #+#    #+#             */
/*   Updated: 2017/10/04 23:30:11 by nkrifa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	save_chars(t_tmp_arg *tmp, unsigned int chars_to_save)
{
  *(tmp->chars_to_save) = chars_to_save;
  return (0);
}
