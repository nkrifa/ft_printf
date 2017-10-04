/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkrifa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/04 23:25:11 by nkrifa            #+#    #+#             */
/*   Updated: 2017/10/04 23:25:15 by nkrifa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	calc_int(long long nb)
{
  unsigned int	size;

  size = 1;
  if (nb < 0)
  {
    size = 2;
    nb = -nb;
  }
  while (nb / 10 > 0)
  {
    size = size + 1;
    nb = nb / 10;
  }
  return (size);
}

unsigned int	calc_uint(unsigned long long nb)
{
  unsigned int	size;

  size = 1;
  while (nb / 10 > 0)
  {
    size = size + 1;
    nb = nb / 10;
  }
  return (size);
}

unsigned int	calc_octal(unsigned long long nb)
{
  unsigned int	size;

  size = 1;
  while (nb / 8 > 0)
  {
    nb = nb / 8;
    size = size + 1;
  }
  return (size);
}

unsigned int	calc_hexa(unsigned long long nb)
{
  unsigned int	size;

  size = 1;
  while (nb / 16 > 0)
  {
    nb = nb / 16;
    size = size + 1;
  }
  return (size);
}

unsigned int	calc_binary(unsigned long long nb)
{
  unsigned int	size;

  size = 1;
  while (nb / 2 > 0)
  {
    nb = nb / 2;
    size = size + 1;
  }
  return (size);
}
