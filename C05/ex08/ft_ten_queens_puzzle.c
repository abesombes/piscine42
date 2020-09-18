/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: audumont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 16:55:56 by audumont          #+#    #+#             */
/*   Updated: 2019/08/15 18:02:16 by audumont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void 	ft_print_sol(int *board)
{
	int col;
	char c;

	col = -1;
	while (++col <= 9)
	{
		c = board[col] + 48;
		write(1, &c, 1);
	}
	write(1,"\n",1);
}

int ft_abs(int  nb)
{
	if (nb < 0)
	nb = -nb;
	return nb;
}

int ft_checkpos(int *board, int col)
{
	int okay;
	int o_col;

	okay = 1;
	o_col = -1;

	while (++o_col < col && okay)
	{
	if (board[o_col]==board[col])
		okay = 0;
	if (ft_abs(board[o_col] - board[col]) == ft_abs(o_col - col))
		okay = 0;
	}
	return okay;
}

void ft_position_queens(int col, int *count)
{
	static int board[10] = {0};
	int pos;

	pos = -1;
	while (++pos < 10)
	{
		board[col] = pos;
		if (ft_checkpos(board, col))
		{
			if (col < 9)
				ft_position_queens(col + 1, count);
			else
			{
				++(*count);
				ft_print_sol(board);
			}
		}
	}

}

int ft_ten_queens_puzzle(void)
{
	int count;

	count = 0;
	ft_position_queens(0, &count);
	return (count);
}

int main(void)
{
	printf("%i", ft_ten_queens_puzzle());
}
