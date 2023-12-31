#ifndef _QUEUE_HPP_
#define _QUEUE_HPP_

#include "formating.hpp"

using namespace std;

template<typename T> class Queue {
public:
    size_t size;
    
    int front;
    int rear;

    bool full;

    T* data;
    
    // Constructor
    Queue(size_t initSize) {
        // Allocating memory for data
        data = new T [initSize];

        size = initSize;

        front = 0;
        rear = 0;
        
        full = 0;
    };

    // Destructor
    ~Queue() {
        // Freeing data 
        delete [] data;
    };

    // TODO: REVIEW enqueue and dequeue logic
    // Queue methods
    void enQueue(T value){
        // Writes value on front
        data[front] = value;

        // Increments pointer wrapping to the end
        front = (front + 1)%(size);

        // Checks colision with the beggining of queue
        if(front == rear) {
            full = true;
        } else if(full)  {
            rear = (rear + 1)%(size);
        }
    };
    
    T deQueue(){
        // Checks for not dequeing an empty list
        if(isEmpty())  {
            throw runtime_error("Dequeing an empty list");
            
            return 0;  
        }

        T result = data[rear];

        // Increments rear wrapping to the end
        rear = (rear + 1)%(size);

        // If dequeued, queue is not full
        full = 0;
        
        return result;
    };

    bool isEmpty(){
        return front == rear && !full;
    };
};

#endif