# snake
A simple C terminal snake game.

# what is this?
This is an old personal project I wanted to bring back. I originally wrote it in 2013, at the time I had just enrolled in CS degree and it used terrible programming (but it worked).

The current version is almost equal to the original one, but I refactored it partially for better programming practices and using pure C (old version used a weird mixture of C and C++ using STL queues, this one includes a q'n'd pure-C implementation of queue).

# How to compile

As usual.

 make clean
 make all
 
Run with ./snake. Ensure to have permissions.

# iqueue

iqueue is a pure-C implementation of a dynamically-alloated queue data structure. It works as follows:

* It defines a \_qitem data structure which holds a void pointer named _data_ and a void pointer named _next_.
* The queue is represented as a pointer to a \_qitem data type. In this item, _data_ points to the last item of the queue and _next_ to the next item of the queue.
* In each item of the queue, _data_ points to the value itself, and _next_ to the next item of the queue.

To make only iqueue, use the provided Makefile, or use the following command:

 gcc -c iqueue.c -o iqueue.o
 
And link it with your program.

 gcc myprogram.c iqueue.o -o myprogram
 
# cutils

cutils is a console manipulation toolkit which provides several console manipulation functions. Further documentation will follow.

# drawprocs

Drawprocs is a helper module which renders the snake.

# Why this code looks fine in some places and so weird in others?

It's a dirty refactored version of a "so weird" original. It's not fully cleaned, but I thought it would be nice to post it already.

I'll try to clean it more in further versions.

# In which language are comments and part of the code??

Catalan, I haven't translated the code to English, but the program strings are. I will translate it to English too in further versions.

# So, how the game worked?

It simply consisted of two queues (now that I have this handy iqueue, I could just make a queue of tuples), one for X and one for Y. The program peeked the end of the queue (last item pushed) to know which is the next position of the snake (based on direction), and popped the queue to remove the first item pushed. This is then rendered to screen, resulting in the snake movement. A timer controls then if it's time to move the snake.

# I can move snake faster when pressing arrow keys!

The condition that the game is checking is "has the timer elapsed" OR "has the user pressed a key", so pressing an arrow key finishes the current cycle, making snake go forward.

Removing the second condition makes it less responsive.
