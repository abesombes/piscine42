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

int 	ft_check_pos(int board[11], int j)
{
	int k;
	int col;
 	int r;

	k = -1;
	col = 0;
	printf("\nligne 40 - j = %i---board complet: %i|%i|%i|%i|%i|%i|%i|%i|%i|%i ---- %i", j, board[0], board[1], board[2], board[3], board[4], board[5], board[6], board[7], board[8], board[9], board[10]);
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
		printf("\nligne 52 - board[%i] = %i - LOWER SQUARE = %i | UPPER SQUARE = %i", r, board[r], j - col + r, j + col - r);
		if ((board[r] == j) || (board[r] == j - col + r) || (board[r] == j + col - r))
			return 0;
//			printf("\nWarning - problème collision même ligne!");
	} 

	return 1;
}

int 	ft_solver(int board[11])
{
	int j;
	int k;
	int tmp;

	j = -1;
	while (++j <= 9)
	{
		if (ft_check_pos(board, j))
		{
			board[board[10]]=j;
			board[10]=board[10]+1;
			ft_solver(board);
		}
	}
	if (j == 10)
	{
		board[10] = board[10] - 1;
		board[board[10]+1] = - 1;
		tmp = board[board[10]];
		board[board[10]] = - 1;

		printf("\n line91 - Arrivée en bas de colonne %i sans solution valable - Tentative de réinjection à la colonne %i à un niveau %i ---board complet: %i|%i|%i|%i|%i|%i|%i|%i|%i|%i ---- %i", board[10]+1, board[10], tmp+1, board[0], board[1], board[2], board[3], board[4], board[5], board[6], board[7], board[8], board[9], board[10]);

		k = 1;
		printf("\n line94 - board[board[10]]: %i -  k = %i", tmp, k);

		while (tmp + k <= 9 && !ft_check_pos(board,tmp + k))
		{
		printf("\n line98 - tmp: %i -  k = %i", tmp, k);
		if (ft_check_pos(board,tmp + k))
		{
			printf("\n line101 - board[10]: %i | board[board[10]] : %i", board[10], board[board[10]]);
			board[board[10]] = tmp + k;
			printf("\n line103 Réinjection successful | board complet: %i|%i|%i|%i|%i|%i|%i|%i|%i|%i", board[0], board[1], board[2], board[3], board[4], board[5], board[6], board[7], board[8], board[9]);

			ft_solver(board);
			k = 10;
		}
		k++;
		}
//		board[10] = board[10] - 1;
//		board[board[10]+1] = -1;
//		printf("\n RESET POTENTIELLEMENT FOIREUX");
		ft_solver(board);
	}
	return 0;
}

int 	ft_ten_queens_puzzle(void)
{
	int board[11];
	int i;

	i = -1;
	while (++i <= 9)
		board[i]=-1;
	board[10]=0;

	ft_solver(board);
	return 0;
}

int 	main (void)
{
	printf("\nnb of board options: %i", ft_ten_queens_puzzle());
}
