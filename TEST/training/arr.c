/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thodavid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 09:25:50 by thodavid          #+#    #+#             */
/*   Updated: 2025/10/10 13:30:23 by thodavid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

/*
   1/alloc new arr with the new len
   2/copy old arr into the new
   3/free the old arr
   4/old ptr->new
   */


void printArr(int *arr, int len)
{
	int	i = 0;

	if (!arr)
	{
		printf("arr is NULL\n");
		return;
	}
	while (i < len)
	{
		printf("arr[%i] ---> %i\n",i ,arr[i]);
		i++;
	}
}

int	*arr_creat(len)
{
	int 	i = 0;
	int	*tmp;
	
	tmp = malloc(sizeof(int) * len);
        if (!tmp)
                exit(1);
	while (i < len)
	{
		printf("please put the number of the case number %i...  ", i);
		scanf("%i", &tmp[i]);
		printf("put a number for case [%i] : ==%i==\n", i, tmp[i]);
		i++;
	}
	return (tmp);
}

int	*rezignArr(int *arr, int new_len, int len)
{
	int	*tmp;
	int	i;

	i = 0;
	if (len <= 0)
		return (NULL);
	tmp = malloc(sizeof(int) * new_len);
	if (!tmp)
		return (NULL);
	while (i < len)
	{
		tmp[i] = arr[i];
		i++;
	}
	if(i < new_len)
	{
		tmp[i] = 0;
		i++;
	}
	arr = tmp;
	return (arr);	
}

int	main (void)
{
	unsigned int 	len;
	unsigned int 	new_len;
	int 		*arr;

	printf("please put a LEN and press ENTER...  ");
	scanf("%u", &len);
	printf("array of len ==%u==\n", len);
	if (len > 10)
	{
		printf("please calm down little hacker, reload try again\n");
		return (0);
	}
	arr = arr_creat(len);

	printArr(arr, len);
        printf("please put a NEW LEN and press ENTER...  ");
        scanf("%u", &new_len);
	rezignArr(arr, new_len, len);
	printArr(arr, new_len);
	free(arr);
	return (0);
}



