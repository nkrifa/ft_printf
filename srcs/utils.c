/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkrifa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 23:30:40 by nkrifa            #+#    #+#             */
/*   Updated: 2017/10/04 23:31:22 by nkrifa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

void	add_space(unsigned int size_to_add)
{
  while (size_to_add > 0)
  {
    write(1, " ", 1);
    size_to_add = size_to_add - 1;
  }
}

void	add_zero(unsigned int size_to_add)
{
  while (size_to_add > 0)
  {
    write(1, "0", 1);
    size_to_add = size_to_add - 1;
  }
}

unsigned int	my_strlen(char *str)
{
  unsigned int	i;

  i = 0;
  while (str[i])
    i = i + 1;
  return (i);
}

int	my_atoi(const char *str)
{
  int	i;
  int	number;

  i = 0;
  number = 0;
  while (str[i] >= '0' && str[i] <= '9')
  {
    number = number * 10;
    number = number + ((int)str[i] - '0');
    i = i + 1;
  }
  return (number);
}
