/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   palinD.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodavid <thodavid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 09:54:12 by thodavid          #+#    #+#             */
/*   Updated: 2025/10/20 08:46:41 by thodavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

bool	isPalindrome(int x)
{
	unsigned int	len;
	unsigned int	i;
	int		num;
	int		*arr;

	len	= 1;
	i	= 0;
	num	= x;
	arr	= NULL;

	if (x <= 10)
		return (false);
	while ((num /= 10) != 0 )
		len++;
	arr = malloc(sizeof(int) * len);
	if (!arr)
		return (false);
	while (i < len)
	{
		arr[i] = x % 10;
		x /= 10;
		i++;
	}
	i = 0;
	while (i < len)
	{
		if (arr[i] != arr[(len-1) - i])
			return (free(arr), (false));
		i++;
	}
	return (free(arr), (true));
}

int	main(int ac, char **av)
{
	if (ac != 2 || av[1][0] == '\0')
		return (fprintf(stderr, "==arg err==\n"), (0));
	
	if (isdigit(av[1][0]))
	{
		if (isPalindrome(atoi(av[1])))
			printf("true\n");
		else
			printf("false\n");
	}
	else
		printf("false\n");

	return (0);
}

