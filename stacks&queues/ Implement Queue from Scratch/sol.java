/*
Implement Queue from Scratch

Like Stack, Queue is a linear structure which follows a particular order in which the 
operations are performed. The order is First In First Out (FIFO).  A good example of 
queue is any queue of consumers for a resource where the consumer that came first is served first. 

The difference between stacks and queues is in removing. In a stack we remove the item the most 
recently added; in a queue, we remove the item the least recently added.

Operations on Queue: 
Mainly the following four basic operations are performed on queue:
Enqueue: Adds an item to the queue. If the queue is full, then it is said to be an Overflow condition. 
Dequeue: Removes an item from the queue. The items are popped in the same order in which they are pushed. 
If the queue is empty, then it is said to be an Underflow condition. 
Front: Get the front item from queue. 
Rear: Get the last item from queue. 


Applications of Queue: 
Queue is used when things don’t have to be processed immediately, but have to be processed in 
First InFirst Out order like Breadth First Search. This property of Queue makes it also useful 
in following kind of scenarios.
1) When a resource is shared among multiple consumers. Examples include CPU scheduling, Disk Scheduling. 
2) When data is transferred asynchronously (data not necessarily received at same rate as sent) between two processes. Examples include IO Buffers, pipes, file IO, etc.
See this for more detailed applications of Queue and Stack.
Array implementation Of Queue 
For implementing queue, we need to keep track of two indices, front and rear. 
We enqueue an item at the rear and dequeue an item from the front. 
If we simply increment front and rear indices, then there may be problems, 
the front may reach the end of the array. The solution to this problem is to increase 
front and rear in circular manner.

*/


// Java program for array
// implementation of queue

// A class to represent a queue
class Queue {
	int front, rear, size;
	int capacity;
	int array[];

	public Queue(int capacity)
	{
		this.capacity = capacity;
		front = this.size = 0;
		rear = capacity - 1;
		array = new int[this.capacity];
	}

	// Queue is full when size becomes
	// equal to the capacity
	boolean isFull(Queue queue)
	{
		return (queue.size == queue.capacity);
	}

	// Queue is empty when size is 0
	boolean isEmpty(Queue queue)
	{
		return (queue.size == 0);
	}

	// Method to add an item to the queue.
	// It changes rear and size
	void enqueue(int item)
	{
		if (isFull(this))
			return;
		this.rear = (this.rear + 1)
					% this.capacity;
		this.array[this.rear] = item;
		this.size = this.size + 1;
		System.out.println(item
						+ " enqueued to queue");
	}

	// Method to remove an item from queue.
	// It changes front and size
	int dequeue()
	{
		if (isEmpty(this))
			return Integer.MIN_VALUE;

		int item = this.array[this.front];
		this.front = (this.front + 1)
					% this.capacity;
		this.size = this.size - 1;
		return item;
	}

	// Method to get front of queue
	int front()
	{
		if (isEmpty(this))
			return Integer.MIN_VALUE;

		return this.array[this.front];
	}

	// Method to get rear of queue
	int rear()
	{
		if (isEmpty(this))
			return Integer.MIN_VALUE;

		return this.array[this.rear];
	}
}

// Driver class
public class Test {
	public static void main(String[] args)
	{
		Queue queue = new Queue(1000);

		queue.enqueue(10);
		queue.enqueue(20);
		queue.enqueue(30);
		queue.enqueue(40);

		System.out.println(queue.dequeue()
						+ " dequeued from queue\n");

		System.out.println("Front item is "
						+ queue.front());

		System.out.println("Rear item is "
						+ queue.rear());
	}
}



/*
Output: 

10 enqueued to queue
20 enqueued to queue
30 enqueued to queue
40 enqueued to queue
10 dequeued from queue
Front item is 20
Rear item is 40
Complexity Analysis:  

Time Complexity:
Operations              Complexity
Enque(insertion)           O(1)
Deque(deletion)            O(1)
Front(Get front)           O(1)
Rear(Get Rear)             O(1)              
Auxiliary Space: O(N). 
N is the size of array for storing elements.
Pros of Array Implementation:  

Easy to implement.
Cons of Array Implementation:  

Static Data Structure, fixed size.
If the queue has a large number of enqueue and dequeue operations, 
at some point (in case of linear increment of front and rear indexes) 
we may not be able to insert elements in the queue even if the queue is empty 
(this problem is avoided by using circular queue).

*/