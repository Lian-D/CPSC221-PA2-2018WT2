/**
 * @file deque.cpp
 * Implementation of the Deque class.
 *
 */

/* Constructor for the Deque class */
template <class T>
Deque<T>::Deque(){

/* your code here */
// k1 tracks the last element, k2 tracks the first element
k1 = -1;
k2 = 0;

}

/**
 * Adds the parameter object to the right of the Deque.
 *
 * @param newItem object to be added to the Deque.
 */
template <class T>
void Deque<T>::pushR(T const& newItem)
{
    /**
     * @todo Your code here!
     */
    data.push_back(newItem);
    k1++;
}

/**
 * Removes the object at the left of the Deque, and returns it to the
 * caller.
 *
 * See .h file for implementation notes. 
 *
 * @return The leftmost item of the Deque.
 */
template <class T>
T Deque<T>::popL()
{
    if (!isEmpty()){
        T popped = data[k2];
        k2++;
        // cout << "printing data size" << endl;
        // cout << data.size() << endl;
        if(data.size() == 2*(k1-k2+1)){
            vector<T> temp;
            int k2c = k2;
            for(int i = 0; i < (k1-k2+1); i++){
                temp.push_back(data[k2c]);
                k2c++;
            }
            // cout << "we have reached" << endl;
            data.clear();
            data = temp;
            k1 = data.size()-1;
            k2 = 0;
            }
            // cout << "new data size should be " << endl;
            // cout << data.size() << endl;
            // cout << data[k2] << endl;
            // cout << data[k1] << endl;
     return popped;       
    }     
}
/**
 * Removes the object at the right of the Deque, and returns it to the
 * caller.
 *
 * @return The rightmost item of the Deque.
 */
template <class T>
T Deque<T>::popR()
{
    if (!isEmpty()){
        T popped = data[k1];
        k1--;
        data.pop_back();
        return popped;
    }
}

/**
 * Finds the object at the left of the Deque, and returns it to the
 * caller. Unlike popL(), this operation does not alter the deque.
 *
 * @return The item at the left of the deque.
 */
template <class T>
T Deque<T>::peekL()
{
        T popped = data[k2];
        return popped;

}

/**
 * Finds the object at the right of the Deque, and returns it to the
 * caller. Unlike popR(), this operation does not alter the deque.
 *
 * @return the value of The item at the right of the deque.
 */
template <class T>
T Deque<T>::peekR()
{
        T popped = data[k1];
        return popped;
    }

/**
 * Determines if the Deque is empty.
 *
 * @return bool which is true if the Deque is empty, false otherwise.
 */
template <class T>
bool Deque<T>::isEmpty() const
{
    /**
     * @todo Your code here! 
     */
    if (k1 < 0 || k2 > k1){
        return true;
    }
    else{
        return false;
    }
}
