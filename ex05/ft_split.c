/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwong <hwong@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 09:02:16 by hwong             #+#    #+#             */
/*   Updated: 2022/09/06 12:03:51 by hwong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	in_string(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen_sep(char *str, char *sep)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && in_string(str[i], sep) == 0)
		i++;
	return (i);
}

int	count_words(char *str, char *seperator)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		while (str[i] && in_string(str[i], seperator) == 1)
			i++;
		if (str[i])
			words++;
		while (str[i] && in_string(str[i], seperator) == 0)
			i++;
	}
	return (words);
}

char	*insert_word(char *str, char *sep)
{
	char	*word;
	int		i;

	word = (char *)malloc(sizeof(char) * ft_strlen_sep(str, sep) + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (str[i] && in_string(str[i], sep) == 0)
		word[i] = str[i++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**output;
	int		i;

	output = (char **)malloc(sizeof(char *) * count_words(str, charset));
	if (!output)
		return (NULL);
	i = 0;
	while (*str)
	{
		while (*str && in_string(*str, charset) == 1)
			str++;
		if (*str)
			output[i++] = insert_word(str, charset);
		while (*str && in_string(*str, charset))
			str++;
	}
	output[i] = 0;
	return (output);
}

/*
#include <stdio.h>
int	main(int argc, char **argv)
{
	int		index;
	char	**split;

	(void)argc;
	split = ft_split(argv[1], argv[2]);
	index = 0;
	while (split[index])
		printf("%s\n", split[index++]);
}
*/