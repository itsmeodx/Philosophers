/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:17:28 by oouaadic          #+#    #+#             */
/*   Updated: 2024/07/24 10:47:03 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

size_t	ft_strlen(const t_string s)
{
	size_t	length;

	length = 0;
	while (s[length])
		length++;
	return (length);
}

int	ft_atoi(const t_string nptr)
{
	int		sign;
	int		result;
	size_t	i;

	sign = 1;
	result = 0;
	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (sign * result);
}

static size_t	ft_getlen(long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

t_string	ft_itoa(int m)
{
	size_t		len;
	long		n;
	t_string	s;

	n = (long)m;
	len = ft_getlen(n);
	s = malloc(sizeof(char) * len + 1);
	if (!s)
		return (NULL);
	if (!n)
		s[0] = '0';
	if (n < 0)
	{
		s[0] = '-';
		n = -n;
	}
	s[len] = 0;
	while (n > 0)
	{
		s[--len] = n % 10 + 48;
		n /= 10;
	}
	return (s);
}

t_string	ft_strdup(t_string s)
{
	size_t		len;
	size_t		i;
	t_string	dup_str;

	if (!s)
		return (NULL);
	len = 0;
	while (s[len])
		len++;
	dup_str = (char *)malloc(len);
	if (dup_str == NULL)
		return (NULL);
	i = -1;
	while (s[++i])
		dup_str[i] = s[i];
	return (dup_str);
}
