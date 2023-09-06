/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crebelo- <crebelo-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 21:56:32 by crebelo-          #+#    #+#             */
/*   Updated: 2023/08/10 21:56:32 by crebelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include<stdio.h>

int	*ft_range(int start, int end)
{
	int	*ar;
	int	len;
	int	i = 0;

	if (start > end)
		len = start - end + 1;
	else
		len = end - start + 1;
	ar = (int *)malloc(sizeof(int) * (len));
	while (i < len)
	{
		if (start < end)
		{
			ar[i] = start;
			i++;
			start++;
		}
		else
		{
			ar[i] = start;
			i++;
			start--;
		}
	}
	return (ar);
}

// int main()
// {
//     int start = 0;
//     int end = -3;

//     int *result = ft_range(start, end);

//     printf("Generated array:\n");
//     for (int i = 0; i < abs(end - start) + 1; i++)
//     {
//         printf("%d ", result[i]);
//     }

//     free(result);

//     return 0;
// }