/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 22:35:47 by crebelo-          #+#    #+#             */
/*   Updated: 2023/08/10 22:35:47 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<stdio.h>

int	*ft_range(int start, int end)
{
	int	*ar;
	int	len;
	int	i;

	i = 0;
	if (start > end)
		len = start - end + 1;
	else
		len = end - start + 1;
	ar = (int *)malloc(sizeof(int) * (len));
	while (i < len)
	{
		if (end < start)
		{
			ar[i] = end;
			i++;
			end++;
		}
		else
		{
			ar[i] = end;
			i++;
			end--;
		}
	}
	return (ar);
}

// int main()
// {
// 	int start = 0;
// 	int end = -3;

// 	int *result = ft_range(start, end);

// 	printf("Generated array:\n");
// 	for (int i = 0; i < abs(end - start) + 1; i++)
// 	{
// 		printf("%d ", result[i]);
// 	}

// 	free(result);  // Don't forget to free the allocated memory

// 	return 0;
// }