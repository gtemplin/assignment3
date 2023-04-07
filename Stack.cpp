// $Id: Stack.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help
// on this assignment.



#define default_length 10
#include "Stack.h"
#include "Array.h"
#include <stdio.h>

//
// Stack
//
template <typename T>
Stack <T>::Stack (void)
	:topElement(nullptr),
	topElementIndex(default_length), //this is one greater than the alloted number of indices
	stackSize(0),
	array(default_length){
	//allocate an array of the default length 
	//and indicate that no values are stored yet 
	//this->array(default_length);
	//this->array.set_data_null(); //data pointers will contain nothing until you push 
}//end default constructor 



//
// create a stack with a specific array size (which is what you input)
//
template <typename T>
Stack <T>::Stack(size_t arraySize)
	:topElement(nullptr),
	topElementIndex(default_length), //this is one greater than the alloted number of indices
	stackSize(0),
	array(arraySize) {
	//allocate an array of the default length 
	//and indicate that no values are stored yet 
	//this->array(default_length);
	//this->array.set_data_null(); //data pointers will contain nothing until you push 
}


//
// Stack copy constructor 
//
template <typename T>
Stack <T>::Stack (const Stack & stack) :Array<T>(stack)
{
	this->topElement = stack.topElement; //top is the same 
	this->topElementIndex = stack.topElementIndex; //indicates that the stack is empty, as index of 0 implies there is an element 
	this->stackSize = stack.stackSize; 
	this->array = stack.array;
} //end copy constructor 


//
// ~Stack
//
template <typename T>
Stack <T>::~Stack (void)
{} //end destructor 


//
// Push a new \a element onto the stack. The element is inserted
// before all the other elements in the list.
//
template <typename T>
void Stack <T>::push (T element)
{
	//See what the next index would be if you were to push. Will decrement the value 
	//If that value doesn't overrule the default size of the stack, you can just push
	//If it does, will need to allocate more data for the stack 
	int potential_stack_index = this->topElementIndex - 1; 
	if (potential_stack_index >= 0) {
		//Push the element onto the stack 
		this->topElementIndex -= 1;
		this->stackSize += 1;
	   	 this->array.set(topElementIndex, element);
		this->topElement = this->array.get_data_pointer() + this->array.size() - this->stackSize; //gives the pointer where the last element was stored 
		
	}//end if
	else {
		size_t oldSize = this->array.size(); //what was the former stack size?
		size_t newSize = oldSize + default_length; //what will the size of the new stack be?
		Stack<T>* newStack = new Stack<T>(newSize);//this stack will have an array size that can handle all of the data elements 
	

		//copy all of the old data back into the new stack 
		//leaving default_length-1 spots empty 

		T elementToSet;
		size_t sizeOf = this->stackSize;
		size_t storingIndex;  
		for (size_t i = 0; i < this->stackSize; i++){
			
			storingIndex = i + default_length;
			
			elementToSet = this->array.get(i);
			
			newStack->array.set(storingIndex, elementToSet); 

		}//end 


		//put the newly added element on the stack 
		newStack->array.set(default_length - 1,element);
		

		//set all of the new stack's member variables (aside from the array)
		newStack->topElement = newStack->array.get_data_pointer() + default_length - 1; //top of stack is what was just added (address)
		newStack->topElementIndex = default_length - 1; 
		newStack->stackSize = this->stackSize + 1;  


		
		//set the old array equal to the newly allocated one 
		*this = *newStack;

		delete newStack; 

	}// end else
	
}//end push method 

//
// pop
//
template <typename T>
void Stack <T>::pop (void)
{
	//will get rid of the top element of the stack and set it to a null pointer 
	//if the stack is already empty, will send an exception indicating 
	if (this->stackSize == 0)
		throw empty_exception();

	//see if stackSize is default_length (currently 10) less than the array size. if so, reallocate to save memory
	//if it is not, keep the same array 
	int sizeDifference = this->stackSize - this->array.size();

	if(sizeDifference < default_length){
		std::cout << "\n Keep the same array" << std::endl; 
		this->topElementIndex += 1; //go more to the right of the array
		this->stackSize -= 1; 
		this->topElement = this->array.get_data_pointer() + this->topElementIndex; //also one to the right 
	}//end if 
	else{
		std::cout << "\n Make new stack/array" << std::endl; 
		//set the array from the point where data matters (after the pop)
		size_t newIndex = this->topElementIndex + 1;
		size_t newStackSize = this->stackSize - 1; 
 		//New stack created with an array size equal to what the new stack size will be after popping 
		Stack<T>* newStack = new Stack<T>(newStackSize);

		for(size_t i = 0; i < newStackSize; i++)
			newStack->array.set(i, this->array.get(i + newIndex)); 
			//should set the new array starting from 0, but get starting from one greater than the former top index 
		

		newStack->topElementIndex = 0; 
		newStack->stackSize = this->stackSize - 1; 
		newStack->topElement = newStack->array.get_data_pointer(); 

		*this = *newStack;

		delete newStack; 
	}//end else 

}//end pop method 


//
// operator =
//
template <typename T>
const Stack <T> & Stack <T>::operator = (const Stack & rhs)
{
	this->topElement = rhs.topElement;
	this->topElementIndex = rhs.topElementIndex;
	this->stackSize = rhs.stackSize;
	this->array = rhs.array;
	return *this;
}// end '=' overload

//
// clear
//
template <typename T>
void Stack <T>::clear (void){
	Stack<T>* clearedStack = new Stack<T>();
	*this = *clearedStack;
	delete clearedStack;
}//end clear 




/*
   * Get the top-most element on the stack. 
 */
template <typename T>
T Stack <T>::top(void) const {
	if (this->stackSize == 0)
		throw empty_exception();
	else
		return *(this->topElement); //return value of the pointer to the top 
}//end return top method 

/*
 * Test if the stack is empty
 */
template <typename T>
bool Stack <T>::is_empty(void) const {
	if (this->stackSize == 0)
		return true;
	else
		return false; 
}//end is empty method 

/*
	Number of element on the stack.
 */
template <typename T>
size_t Stack <T>::size(void) const {
	return this->stackSize; 
}//end return size method 



//
// Show the stack from top to bottom indicating the index of the array that the element is stored at 
//
template <typename T>
void Stack<T>::printStack(void) {
	T output;
	size_t sizeOf = this->stackSize;
	std::cout << "\nStack contents for stack size =  " << sizeOf << ":" << std::endl;
	for (size_t i = 0; i < this->stackSize; i++) {
		output = this->array.get(topElementIndex + i);
		std::cout << "[" << topElementIndex + i << "] = " << output;
		std::cout<<std::endl;
	}//end for 
}//end print stack



template <typename T>
void Stack<T>:: printStackArrayIndex(size_t index){
	std::cout<<"\nArray at index " << index << " = " << this->array.get(index) << std::endl; 
}









