#ifndef QUEUE_H_
#define QUEUE_H_

#define SIZE 5

class queue
{
private:
		int arr[SIZE];
		int rear;
		int front;
public:
		queue(void);
		bool is_queue_full(void);
		bool is_queue_empty(void);
		void enqueue(int ele);
		void dequeue(void);
		int get_front(void);
};

#endif /* QUEUE_H_ */
