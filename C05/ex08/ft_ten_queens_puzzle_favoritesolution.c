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

void			ft_print_sol(int *board)
{
	int			index;
	char		c;

	index = -1;
	while (++index < 10)
	{
		c = board[index] + 48;
		write(1, &c, 1);
	}
	write(1, "\n", 1);
}

int				ft_abs(int value)
{
	if (value < 0)
		value = -value;
	return (value);
}

int				ft_check_place(int *board, int index)
{
	int			okay;
	int			o_index;

	okay = 1;
	o_index = -1;
	while (++o_index < index && okay)
	{
		if (board[index] == board[o_index])
			okay = 0;
		if (ft_abs(o_index - index) == ft_abs(board[o_index] - board[index]))
			okay = 0;
	}
	return (okay);
}

void			ft_place_queens(int index, int *count)
{
	static	int	board[10] = {0};
	int			pos;

//	printf("\n BOARD: %i|%i|%i|%i|%i|%i|%i|%i|%i|%i", board[0], board[1], board[2], board[3], board[4], board[5], board[6], board[7], board[8], board[9]);

	pos = -1;
	while (++pos < 10)
	{
		board[index] = pos;
		if (ft_check_place(board, index))
		{
			if (index < 9)
				ft_place_queens(index + 1, count);
			else
			{
				++(*count);
				ft_print_sol(board);
			}
		}
	}
}

int				ft_ten_queens_puzzle(void)
{
	int			count;

	count = 0;
	ft_place_queens(0, &count);
	return (count);
}

int main(void)
{
	printf("%i", ft_ten_queens_puzzle());
}
