/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isletter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dehamad <dehamad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 13:55:13 by dehamad           #+#    #+#             */
/*   Updated: 2024/08/17 13:59:06 by dehamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "is.h"

int	ft_isletter(char *line, char sep)
{
	return (!ft_isdigit(*line) && !ft_isspace(*line) && !ft_issep(*line, sep));
}
