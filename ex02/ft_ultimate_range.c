/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwong <hwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 10:38:53 by hwong             #+#    #+#             */
/*   Updated: 2022/09/06 12:04:20 by hwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;
	int	count;
	int	*array;

	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	size = max - min;
	array = (int *)malloc(sizeof(int) * size);
	if (!array)
	{
		*range = 0;
		return (-1);
	}
	*range = array;
	count = 0;
	while ((min + count) < max)
	{
		array[count] = min + count;
		count++;
	}
	return (count);
}

/*
#include <stdio.h>
int	main(void)
{
	int	min;
	int	max;
	int	*range;
	int	size;
	int	i;

	min = 5;
	max = 10;
	size = ft_ultimate_range(&range, min, max);
	i = 0;
	printf("%p\n", range);
	while (i < size)
	{
		printf("%i ", range[i]);
		i++;
	}
	return (0);
}
*/