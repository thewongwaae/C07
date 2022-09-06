/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwong <hwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 10:49:18 by hwong             #+#    #+#             */
/*   Updated: 2022/09/06 12:19:18 by hwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	str_len(char *str)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

int	str_cpy_len(char *des, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		des[i] = src[i];
		i++;
	}
	des[i] = '\0';
	return (i);
}

int	get_total_len(int size, char **strs, char *sep)
{
	int	num_str;
	int	totallength;

	num_str = 0;
	totallength = 0;
	while (num_str < size)
	{
		if (num_str != size - 1)
			totallength += str_len(sep);
		totallength += str_len(strs[num_str++]);
	}
	return (totallength);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*string;
	int		str_i;
	int		num_str;

	if (size == 0)
		return ((char *)malloc(sizeof(char)));
	string = (char *)malloc(sizeof(char) * get_total_len(size, strs, sep) + 1);
	if (!(string))
		return (NULL);
	num_str = 0;
	str_i = 0;
	while (num_str < size)
	{
		str_i += str_cpy_len(string + str_i, strs[num_str]);
		if (num_str != size - 1)
			str_i += str_cpy_len(string + str_i, sep);
		num_str++;
	}
	string[str_i] = '\0';
	return (string);
}

/*
#include <stdio.h>
int	main(void)
{
	char	**strs;
	char	*separator;
	char	*result;
	int		i;

	i = 0;
	strs = (char **)malloc(sizeof(char *) * 4);
	while (i < 4)
		strs[i++] = (char *)malloc(sizeof(char) * 6);
	strs[0] = "Hello";
	strs[1] = "I";
	strs[2] = "am";
	strs[3] = "why";
	separator = " , ";
	result = ft_strjoin(0, strs, separator);
	printf("When no size = %d : %s\n", 0, result);
	free(result);
	result = ft_strjoin(4, strs, separator);
	printf("Result with size = %d : %s\n", 4, result);
}
*/
/*
#include <stdio.h>
int	main(void)
{
	int		size;
	char	*ret;
	char	*sep;

	char *strs[4] = {
		"Hello",
		"How",
		"are",
		"you"};
	sep = ", ";
	size = 4;
	ret = ft_strjoin(size, strs, sep);
	printf("%s", ret);
	free(ret);
	return (0);
}
*/