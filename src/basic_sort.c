/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agras <agras@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 16:57:05 by agras             #+#    #+#             */
/*   Updated: 2022/07/26 16:57:40 by agras            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/prototypes.h"

void	sort_basic_to_bottom(t_stacks *prog, int top, int mid, int bot)
{
	if (mid > top && mid > bot && top < bot)
	{
		swap_a(prog);
		rotate_a(prog);
	}
	else if (mid < top && mid > bot && top > bot)
	{
		swap_a(prog);
		rrotate_a(prog);
	}
}

void	basic_sort(t_stacks *prog)
{
	int	top;
	int	mid;
	int	bot;

	top = prog->a->content;
	mid = prog->a->next->content;
	if (!prog->a->next->next)
	{
		rotate_a(prog);
		return ;
	}
	bot = prog->a->next->next->content;
	if (mid < top && mid < bot && top < bot)
		swap_a(prog);
	else if (mid < top && mid < bot && top > bot)
		rotate_a(prog);
	else if (mid > top && mid > bot && top > bot)
		rrotate_a(prog);
	else
		sort_basic_to_bottom(prog, top, mid, bot);
}
