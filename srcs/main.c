/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkrifa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 23:08:27 by nkrifa            #+#    #+#             */
/*   Updated: 2017/10/04 23:48:17 by nkrifa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int main (int ac, char **av)
{

	int i = 0;
	while (i < 10)
	{
	ft_printf("%35.10d je suis donc je pense %% \n",i);
	i++;
	}

	return(0);
}