/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brute_force_algorithm.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akuburas <akuburas@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 10:09:03 by akuburas          #+#    #+#             */
/*   Updated: 2024/02/16 10:20:00 by akuburas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
// This will be a sort of brute force method to sorting the stack. 
// First we will have a method for sorting 3 numbers.
// Then for the rest.
// 1. Push 2 number from stack a to stack b
// 2. Find the cheapest number to push to stack b
// After that certain point, now we will count all the time. We will count and calculate for every number one by one before each push. We will calculate how many operations it would take to push the number into the correct position in the STACK_B
// The important part is that if we have the new biggest or smallest number then its always pushed to the top of stack b.
// For now lets just start with the first part where we create the algorithm that sorts 3 values.
// For now lets also create a struct inside push_swap.h