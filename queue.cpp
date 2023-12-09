#include <ostream>
#include "queue.h"


// Copy constructor
queue::queue(const queue& q):
	queue_size(0),
	front(nullptr),
	back(nullptr)
{

	node* cur=q.front;
	for(size_t i=0;i<q.queue_size;i++)
	{
		
		push(cur->value);
		cur=cur->next;

	}	


}

// Initializer list constructor
queue::queue(std::initializer_list<int> ilist):
	queue_size(0),
	front(nullptr),
	back(nullptr)
{

	size_t i=0;
	for(int val:ilist){
		push(val);
		++i;
	}	

  
}

// Copy assignment
queue& queue::operator=(const queue& q)
{
	if(queue_size!=q.queue_size)
	{
		node* current=front;
		node* next_current;

		while(current)
		{
			next_current=current->next;
			delete current;
			current=next_current;
			queue_size--;	
		}
		
		node* cur=q.front;
		while (cur)
		{
			push(cur->value);
			cur=cur->next;
		}
	}	

	return *this;
}

// Insert an item at the back of the queue
void queue::push(int val){
	
	node* new_back = new node (val);
	new_back->next=nullptr;
	if(queue::empty())
		front=new_back;
	else 
		back->next=new_back;
	// new_back is the new node that we
	// will insert into our list.
	
	// original back should be followed by
	// the new_back.
	back=new_back;
	// back of the list is now new_back.
	queue_size++;
}

// Returns the value of the front-most item of the queue;
// throws an exception if the queue is empty
int queue::peek() const{
	if(queue::empty())
		throw std::invalid_argument("Queue Empty!!!");
	else
		return front->value;
}

// Remove the front-most item from the queue
// throws an exception if the queue is empty
void queue::pop()
{
	if(!queue::empty())
	{
		node* old_front=front;	
		front=front->next;
		delete old_front;
		queue_size--;
	}
	else throw std::invalid_argument("Queue Empty!!!");		

}

// Remove everything from the queue
void queue::clear()
{
	queue_size=0;
}

// Returns the number of items on the queue
size_t queue::size() const
{
	return queue_size;
}

// Returns whether or not the queue is currently empty
bool queue::empty() const
{
	return (queue_size==0);
}

// Destructor
queue::~queue()
{
	node* cur=front;
	while(cur)
	{
		node* next=cur->next;
		delete cur;
		cur=next;	
	}
}






