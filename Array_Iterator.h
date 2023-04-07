#ifndef _ARRAY_ITERATOR_H_
#define _ARRAY_ITERATOR_H_



#include "Array.h"
#include <cstring>



template <typename T>
class Array_Iterator {

    public:

        typedef T type; 

        //Iterator constructor 
        Array_Iterator(Array <T> & a):
            array(a),
            current_index(0){}
        
        //Iterator destructor 
        //~Array_Iterator(void);
        


        /*
        returns true if have parsed through the whole array
        returns false otherwise
        */
        bool is_done (void){
            if(current_index < this->array.size())
                return false;
            else
                return true; 
        }//end is done method 



        /*
        Method to advance one index 
        */
        void advance (void){
            this->current_index += 1;
        }//end advance method 



        /*
        Operator overload that will return
        the data stored at the current array index 
        */
        T & operator * (void){
	    size_t toReturn = this->current_index; 

            return this->array[toReturn];
        }//end overload


        /*
        Operator overload that will return a reference
        to the data stored at the current array index 
        */
        T * operator -> (void){
             size_t toReturn = this->current_index; 

	     return &this->array[toReturn]; 
        }//end overload 



    private: 

        Array <T> & array; //reference to the array to be iterated through 
        size_t current_index; //current size of the array to be iterated through 

};



#endif 
