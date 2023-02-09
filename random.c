/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amejia <amejia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 16:40:27 by amejia            #+#    #+#             */
/*   Updated: 2023/02/09 17:40:26 by amejia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int random_uint(unsigned int range)
{
    static int seed;   
    long a;
    long m;
    
    if (seed == 0)
        seed = SEED_N;

    a = 16807;
    m = 2147483647;
    seed = (a * seed) % m;
    range = seed % range;
    return (range);
    
}