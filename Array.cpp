// $Id: Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor receieved any help
// on this assignment.


#include <stdexcept>         // for std::out_of_bounds exception

#include <cstring>


#define default_length 10



//
// Array
//
template <typename T>
Array <T>::Array (void) 
	:Base_Array<T>(),
	max_size_ (default_length * 2){}

//
// Array (size_t)
//
template <typename T>
Array <T>::Array (size_t length)
	:Base_Array<T>(length),
	max_size_ (length + default_length){} //added padding to max size 

//
// Array (size_t, char)
//
template <typename T>
Array <T>::Array(size_t length, T fill)
	:Base_Array<T>(length, fill), 
	max_size_(length + default_length) {}
	


// Array (const Array &)
//copy constructor 
//
template <typename T>
Array <T>::Array (const Array & array)
	:Base_Array<T>(array),
	max_size_(array.max_size_) {}



//
// Return the max size of the array
//
template <typename T>
size_t Array <T>::max_size(void) const {
	return this->max_size_;
}



/*
	Increment methods that are used for testing other methods  
*/
template <typename T>
void Array <T>::increment_cur_size_(int value) {
	int new_size = this->size() + value; 
	this->resize(new_size); 
}//end increment current size 

template <typename T>
void Array <T>::increment_max_size_(int value) {
	this->max_size_ += value;
}//end increment current size 



//
//	slice to the end 
//
template <typename T>
Array<T> Array <T>::slice(size_t begin) const
{
	size_t currentSize = this->size() - begin;
	Array* returnArray = new Array(currentSize); 
	*returnArray = slice(begin, this->size() - 1);
	return *returnArray;
}//end first slice method 



//
//	slice from index = begin to index = end 
//
template <typename T>
Array<T> Array <T>::slice(size_t begin, size_t end) const
{
	size_t currentSize = end - begin + 1;
	Array<T>* returnArray = new Array(currentSize); //values are currently garbage 
	
	returnArray->setData_pointer(*this, begin); //sets the data pointer of the returnArray to that of the array that called the function
	
	return *returnArray;
}//end slice method 



//
// Shrink the array to reclaim unused space 
//
template <typename T>
void Array <T>::shrink(void)
{
	int currentSize = this->size();
	Array<T>* array = new Array<T>(currentSize); //allocate a new array
	array->set_cur_size_(currentSize);
	T valToSet;
	for (int i = 0; i < currentSize; i++) {
		valToSet = this->get(i);
		array->set(i, valToSet); //set the values within the shrunken array
	}//end for 
	*this = *array; //now the array that called this method is equal to our newly created array
}//end shrink method


template <typename T>
void Array <T>::resize (size_t new_size)
{

	//will allocate extra space as needed. will preserve old data if no
	//new allocations are required 
	int current = this->size();
						
	if(current > new_size){
	//cut off extra until the size matches 
		this->set_cur_size_(new_size); //change the current size 
	}//end if
	else if(current < new_size){
		
		this->set_cur_size_(new_size);

		//allocate a new array 
		Array<T> * array = new Array<T>(new_size);
		
		//will store what needs to be filled in the new array
		T valueToFillWith;

		//fill the new array with all of the old data
		for(int i = 0; i < current; i++){
			valueToFillWith = this->get(i);
			array->set(i,valueToFillWith);	
		}//end for 

		//set the old array equal to the newly made array with added size 
		*this = *array;
		delete array; 
		this->printArray();	

		//ensure that the max is greater 
		this->max_size_ = this->size() + default_length;

	}//end else if	//if its equal, don't need to do anything

	size_t currentMaximum = this->max_size_;
	if(new_size > currentMaximum){
		this->max_size_ = new_size;
	}//end if 

}//end resize method





//
// '=' operator overload 
//
template <typename T>
const Array<T>& Array<T>::operator = (const Array& rhs)
{

	if (this == &rhs) {
		return *this;
	}//end check for self assignment


	//the array that called the method should have a size equal to that of the rhs
	this->set_cur_size_(rhs.size());
	
	//call reallocate memory method to set to rhs value	
	this->reallocate_memory(rhs.size());


	//assign data from the rhs array to this new array
	for (size_t i = 0; i < rhs.size(); i++)
		this->set(i, rhs.get(i));

	
	return *this; //return the actual array
}//end assignment operation







