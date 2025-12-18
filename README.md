*This project has been created as part of the 42 curriculum by rvaz-da-.*

**Description**


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
The program's only output is the moves used to sort the stack.

As you may have noticed, two stacks are present. This is because there are actually two
of them: one of them contains all the integers to sort, the other one is used as a tool
for the sorting algorithm, to stock data temporarily. By default, they are both empty. 
Stack a will be the one containing the integers, and stack b will remain empty until useful
in the sorting process.

After some research I ended up using an algorithm which pushes two numbers to stack b and 
then measures the least costly number to be added to stack b in the right position, to then 
move everything (once ordered in b) back to stack a. For this I used doubly linked lists, which
allowed me not only to properly familiarize myself with them, but also to facilitate some moving
processes. 
This is a not so "mathematical" algorithm, but more a way of thinking about the circularity of linked
lists and a way to use both stacks at the same time to minimise unnecessary moves.

Some other algorithms I stumbled accross were the radix sort and algorithms that sort the stack by 
breaking it down in smaller chunks, those seemed quite complex and I saw weren't even eligible for max
project score.
I first thought of using radix, but I later understood that its efficiently is much enhanced for much larger
stacks, which is the reason for its uneligibility.



**Instructions**


The program is compiled through the "make" command, which compiles all dependencies into a single executable
called "push_swap". In order to run the program you can therefore execute it: ./push_swap, with the necessary
arguments.

Now a silent debate arises — the program takes the list to be sorted as an argument (stack a), but how can it be
passed? Well, given the subject is not clear in regards to the matter, the decision is ours. Some people only implement
one method of passing arguments in their parsing, others accept every possible combination. I went for a middle ground,
arguments accepted are either:
- A single string argument containing every element to be sorted, separated by spaces, like this: ./push_swap "98 732 -12 9"
- Multiple string arguments, every one of which only containing one of the elements to be sorted, like this: ./push_swap 98 732 -12 9
I of course implemented the necessary parsing checks to run the program smoothly, which means out-of-int-bounds numbers, non-digits
and non-spaces will not be accepted. The only exceptions I let through were "+" and "-" signs, that will help with char->int conversion.

> ### TL;DR
> Steps to run the program:
> - make
> - ./push_swap <argument(s)>
> - make fclean



**Resources**


The first thing I did after having read the subject was to go online in search of project-overviews, in order to get a grasp of what I'll be doing. I
generally like to look at code on github, eventhough it does not give me any keys and despite not always understanding it. I started by looking at radix
implementations of old-peers from 42 Lisboa: hcarrasq and alencart. This enabled me to get a general idea of the project's size and the type of codebase
I'd be dealing with. 

After that I searched for Youtube videos and articles to understand how I would need to think about the subject and what my approach could be like.
Some Youtube videos that stood out from that research were:
- Oceano's "push_swap: a performant sorting algorithm using 2 stacks (100-630 moves | 500-5470 moves)", which gave me really good insight about how to go about 
the project from a technical standpoint and how I could implement and deal with linked lists.
- Thuggonaut's "push_swap TUTORIAL", which kind of cleared off the path I had to follow, given that she goes into how she approached the project.
- Polylog's "The fastest sorting algorithm", which very clearly and pedagogically explained the radix algorithm — its inner workings, advantages and disadvantages, 
example implementation. This video really helped me understand sorting algorithms and how to think about them, as well as was what first made me want to try radix.

I then had finished the binge watching part of my research and also wanted to read about the matter. I had talked with some of my peers also doing the project and they
told me about this "algorithm that is not really one" where you assign a move-cost to every node in the list and it had me thinking, so I went on with my research
with that in mind and read a couple of articles:
- "Push_swap: what is the most efficient way to sort given values using a limited set of instructions on two rotatable stacks?" on StackOverflow was the first thing
I stumbled upon, it wasn't very useful but it was quite nice seeing someone write about this.
- Jamie Dawson's "Push_Swap: The least amount of moves with two stacks" helped me understand the inner workings of the available moves, eventhough he used the splitting it 
into chunks method, which I found quite unelegant.
- Daniel Jelacik's "Push_swap: Sorting Without Traditional Algorithms", this was the article that made the project click for me. It approached in a very smart yet simple, 
problem-solving way that I really enjoyed and made me understand why I should do each part of the process in a way and not another and ended up guiding me quite a lot.
