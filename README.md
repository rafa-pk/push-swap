# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    README.md                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rvaz-da- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/17 18:50:02 by rvaz-da-          #+#    #+#              #
#    Updated: 2025/12/17 19:07:56 by rvaz-da-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

*This project has been created as part of the 42 curriculum by rvaz-da-.*

#**Description**
The pushswap project aims to create a program which sorts a given stack of integers 
within the least possible amount of moves. By moves we mean movements 
specified in the subject, hereby listed:
- sa: Swap the first two elements at the top of stack a.
- sb: Swap the first two elements at the top of stack b.
- ss: sa and sb at the same time.
- pa: Take the first element at the top of b and push it to the top of a. Do nothing
	  if b is empty.
- pb: Take the first element at the top of a and push it to the top of b. Do nothing
	  if a is empty.
- ra: Shift up all elements of stack a by 1. The first element becomes the last.
- rb: Shift up all elements of stack b by 1. The first element becomes the last.
- rr: ra and rb at the same time.
- rra: Shift down all elements of stack a by 1. The last element becomes the first.
- rrb: Shift down all elements of stack b by 1. The last element becomes the first.
- rrr: rra and rrb at the same time.
As you may have noticed, two stacks are present. This is because there are actually two
of them: one of them contains all the integers to sort, the other one is used as a tool
for the sorting algorithm, to stock data temporarily. By default, stack a is the one
containing the integers, and stack b is empty.

The program's only output is the moves used to sort the stack.
My approach was to use an algorithm which
#**Instructions**

#**Resources**
