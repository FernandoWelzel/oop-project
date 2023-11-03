#ifndef _QUEUE_HPP_
#define _QUEUE_HPP_

using namespace std;

template<typename T> class Queue {
private:
    size_t size;
    
    int front;
    int rear;

public:
    T* data;
    
    // Constructor
    Queue(size_t initSize) {
        // Allocating memory for data
        data = new T [initSize];

        size = initSize;

        front = 0;
        rear = 0;
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

        // Increments rear in case of overwriting
        if(front == rear)  {
            rear = (rear + 1)%(size);
        }
        
        // Increments pointer wrapping to the end
        front = (front + 1)%(size);
    };
    
    T deQueue(){
        // Checks for not dequeing an empty list
        if(front == 0 && rear == 0)  {
            cerr << "ERROR: Dequeing an empty list" << endl;
            
            return data[rear];  
        }

        T result = data[rear];

        // Increments rear wrapping to the end
        rear = (rear + 1)%(size);
        
        return result;
    };
};

#endif