/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwong <hwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 11:39:57 by hwong             #+#    #+#             */
/*   Updated: 2022/09/06 12:04:00 by hwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	size;
	int	count;
	int	*array;

	count = 0;
	size = max - min;
	array = (int *)malloc(sizeof(int) * size);
	if ((!array) || (min >= max))
		return (0);
	while (min < max)
	{
		array[count] = min;
		min++;
		count++;
	}
	return (array);
}

/*
#include <stdio.h>
int	main(void)
{
	int	*tab;
	int	i;
	int	min;
	int	max;

	i = 0;
	min = 7;
	max = 10;
	tab = ft_range(min, max);
	while (i < (max - min))
	{
		printf("%i ", tab[i]);
		i++;
	}
	return (0);
}
*/