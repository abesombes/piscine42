/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombes <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 17:19:29 by abesombes         #+#    #+#             */
/*   Updated: 2020/09/07 17:28:36 by abesombes        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

void 	ft_display(int board[10])
{
	int i;
	char tmp;

	i = -1;
	while (++i <=9 )
	{
//		printf("\nboard[%i]: %i", i, board[i]);
		tmp = board[i] + 48;
		write(1, &tmp, 1);
	}
}

int 	ft_check_pos(int board[10], int j)
{
	int k;
	int col;
 	int r;

	k = -1;
	col = 0;
	printf("\nj = %i---board complet: %i|%i|%i|%i|%i|%i|%i|%i|%i|%i", j, board[0], board[1], board[2], board[3], board[4], board[5], board[6], board[7], board[8], board[9]);
	while (++k <= 9)
	{
		if (board[k] == -1)
		{
			col = k;
			k = 10;
		}
	}
	r = -1;
	while (++r < col)
	{
		printf("\nboard[%i] = %i - j = %i - col = %i - r = %i et j - col + r = %i", r, board[r], j, col, r,  j - col + r);
		if ((board[r] == j) || (board[r] == j - col + r) || (board[r] == j + col - r))
			return 0;
//			printf("\nWarning - problème collision même ligne!");
	} 
//	r = col;
//	while  (--r >=0)
//	{
//		if ((board[r] == j - col + r) || (board[r] == j + col - r))
//			return 0;
	//printf("\nWarning - problème collision diagonale");
//	}

	return 1;
}

int 	ft_ten_queens_puzzle(void)
{
	int board[11];
	int i;
	int j;

	i = -1;
	while (++i <= 9)
		board[i]=-1;
	board[10]=0;
	i = 0;
	k = -1;
	
	if (i <= 9)
	{
			j = -1;
			while (++j <= 9)
			{
				if (ft_check_pos(board, j))
				{
					board[i]=j;
					j = -1;
					i++;
				}
			}
			i--;
	}
	else if (i == 10)
		ft_display(board);

	return 0;
}

int 	main (void)
{
	printf("\nnb of board options: %i", ft_ten_queens_puzzle());
}
