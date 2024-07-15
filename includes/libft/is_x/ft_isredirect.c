/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isredirect.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42abudhabi.ae>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 19:26:47 by dehamad           #+#    #+#             */
/*   Updated: 2024/05/19 21:30:35 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "is.h"

int	ft_isredirect(char *str)
{
	return ((*str == '>' || *str == '<' || *str == '|' || *str == '&')
		&& *(str + 1) == *str);
}