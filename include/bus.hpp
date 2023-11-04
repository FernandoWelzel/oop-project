#ifndef _BUS_HPP_
#define _BUS_HPP_

#include "component.hpp"

#include <iostream>
#include <list>
#include <vector>
#include <algorithm>  

using namespace std;

class Bus: public Component {
public:
    int width;
    int counter = 0;

    vector<bool> status; // TRUE == Ready, FALSE == pending
    list<DataValue> variable; // Store variables
    string source;

    Component *sourceP;
 
    int simulate(){ 
        replace(this->status.begin(), this->status.end(), false, true); // Moves all pending to Ready
        int i;  // iterator
        list<DataValue> result; // Store simulate method results 

        auto itr = result.begin();  // iterator
        DataValue& element = *itr;  // Used to access elements of result
        cout << "before loop" << endl;

        for (i = 0; i < this->width; i++){
            result.push_front(this->read());  // calling read method to store value

            if (!(itr->valid)){         // if value invalid, break
                // cout << "Invalid value detected, iteration: " << i << endl;
                return 1;
                break;
            }
            else{
                this->status.push_back(false);   // stored as pending 
            }
        }
        // cout << "Temporary message - memory simulation method" << endl;
        return 1;
    };

    DataValue read(){
        // cout << "Memory read method" << endl;
        counter++;
        // cout << "Counter: " << counter << endl;
        return get(variable, counter-1);
    };
    
    // Constructor
    Bus(string busPath);
    // Destructor
    ~Bus();

    DataValue get(list<DataValue> _list, int counter);
};

#endif