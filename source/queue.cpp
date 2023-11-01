#include <string>
#include <fstream>
#include <iostream>

#include "queue.hpp"

using namespace std;

// TODO: REMOVE FUNCTION DECLARATIONS OF THE HEADER

// template<typename T>
// Queue<T>::Queue(size_t initSize){
//     // Allocating memory for data
//     data = new T [initSize];

//     size = initSize;

//     front = 0;
//     rear = 0;
// }

// template<typename T>
// Queue<T>::~Queue(){
//     // Freeing data 
//     delete [] data;
// }

// template<typename T>
// void Queue<T>::enQueue(T value){
//     // Increments pointer wrapping to the end
//     front = (front + 1)%(size);

//     // Increments rear in case of overwriting
//     if(front == rear)  {
//         rear = (rear + 1)%(size);
//     }
    
//     // Writes value on front
//     data[front] = value;
// }

// template<typename T>
// T Queue<T>::deQueue(){
//     // Checks for not dequeing an empty list
//     if(front == rear)  {
//         cerr << "ERROR: Dequeing an empty list" << endl;
        
//         return data[rear];  
//     }

//     T result = data[rear];

//     // Increments rear wrapping to the end
//     rear = (rear + 1)%(size);
    
//     return result;
// }
