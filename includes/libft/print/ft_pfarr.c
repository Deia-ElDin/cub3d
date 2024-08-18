/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pfarr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 22:02:49 by dehamad           #+#    #+#             */
/*   Updated: 2024/08/18 14:38:10 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

void	ft_pfarr(t_fmt *fmt)
{
	char	**arr;
	char	*str;
	size_t	len;
	int		index;

	arr = va_arg(fmt->args, char **);
	index = 0;
	while (arr[index])
	{
		str = arr[index];
		len = ft_strlen(str);
		fmt->len += ft_strlen(arr[index]);
		ft_putchar_fd('.', fmt->fd);
		ft_putstr_fd(arr[index++], fmt->fd);
		ft_putchar_fd('.', fmt->fd);
		if (str[len - 1] != '\n')
			ft_putchar_fd('\n', fmt->fd);
	}
}
