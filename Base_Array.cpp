//Base array .cpp file. Do not include the .h file 


#define default_length 10 

#include <stdexcept>

#include <iostream>



//
// Array
//
template <typename T>
Base_Array <T>::Base_Array(void) 
	:data_(new T[default_length]),
	cur_size_(default_length){}
	//end default constructor

//
// Array (size_t)
//
template <typename T>
Base_Array <T>::Base_Array(size_t length) 
	:data_(new T[length]),
	cur_size_(length){}//end particular length constructor 



//
// Array (size_t, char)
//
template <typename T>
Base_Array <T>::Base_Array(size_t length, T fill)
	:data_(new T[length]),
	cur_size_(length){
	//allocate a pointer for the start of the data and
	//fill each pointer with the input type T 
	T* pointer = this->data_;
	for (size_t i = 0; i < length; i++) {
		*pointer = fill;
		++pointer;
	}//end for loop 
}//end method 



//
// Array (const Array &)
//copy constructor 
template <typename T>
Base_Array <T>::Base_Array(const Base_Array<T>& array)
	:cur_size_(array.cur_size_),
	data_(new T[array.cur_size_]) {
	//copy data from the input array  
	T* initialArray = array.data_;
	T* copyArray = this->data_;
	for (size_t i = 0; i < array.cur_size_; i++) {
		*copyArray = *initialArray;
		++copyArray;
		++initialArray;
	}//end for
}//end copy constructor method



//
// ~Array
//
template <typename T>
Base_Array <T>::~Base_Array(void)
{
	delete[] data_;
}



template <typename T>
size_t Base_Array <T>::size(void) const {
	return this->cur_size_; 
}




//
// operator []
//
template <typename T>
T& Base_Array <T>::operator [] (size_t index)
{
	//go to the index of the array and return the value (if within range)
	if (index < this->cur_size_) {
		T* returnvalue = this->data_;
		returnvalue += index; //add the index 	
		return *returnvalue; //return the value that the pointer points to
	}//end if
	else {
		throw std::out_of_range("OutOfRange");
	}//end else 
} //end operator overload not constant 



//
// operator [] 
//
template <typename T>
const T& Base_Array <T>::operator [] (size_t index) const
{
	//go to the index of the array and return the value (if within range)
	//but this time the return value is constant 
	if (index < this->cur_size_) {
		const T* returnvalue = this->data_;
		returnvalue += index; //add the index 	
		return *returnvalue; //return the value that the pointer points to 
	}
	else {
		throw std::out_of_range("OutOfRange");
	}//end else 
}//end const [] overload 



//
// get. returns the value stored at the pointer 
//
template <typename T>
T Base_Array <T>::get(size_t index) const
{
	//size_t currentSize = this->cur_size_;
	if (index <= (this->cur_size_ - 1)) {
		T* returnvalue = this->data_;//pointer to the 0th element
		returnvalue += index;//increment to the desired index
		//std::cout<<"\nWithin Base_Array get method, the return pointer = " << returnvalue << std::endl;
		return *returnvalue; //return what is stored at the return value
	}//end if 
	else {
		throw std::out_of_range("OutOfRange");
	}//end else 
} //end get method 



//
// set
//
template <typename T>
void Base_Array <T>::set(size_t index, T value)
{
	size_t currentSize = this->cur_size_;
 
	if (index <= (this->cur_size_ - 1)) {
		T* toSet = this->data_;
		toSet += index;
		*toSet = value; //value at the location to set is equal to input value
	}//end if
	else {
		throw std::out_of_range("OutOfRange");
	}//end else
}//end set method 




//return the index where a value is found 
template <typename T>
int Base_Array <T>::find(T val, size_t start) const
{
	if (start < this->cur_size_) {
		int output = -1; //this will be the output if nothing is found
		size_t size = this->cur_size_;//how many places to look
		T* arrayElement;
		T* temp;
		T comparison;
		temp = this->data_; //pointer to the 0th array element 
		//for loop starting from the input start value	
		for (int i = start; i < size; i++) {
			arrayElement = temp + i;//pointer to ith element of the array
			comparison = *arrayElement; //what is the actual element held there
			//if found, return the index where it was found 
			if (comparison == val) {
				output = i; //the index is output 
				return output;
			}//end if, and do nothing otherwise 
		}//end for, have looked through the whole array
		return output;//if not found in the for loop, return negative one
	}//end if
	else {
		throw std::out_of_range("OutOfRange");
	}//end else

} //end find with start index method



//
// operator ==
//
template <typename T>
bool Base_Array <T>::operator == (const Base_Array& rhs) const
{
	if (this == &rhs) {
		return true;
	}//end self comparison

	T* current = this->data_;//pointer to 0th element of the array 
	T currentValue;
	T* currentComparison = rhs.data_;
	T currentComparisonValue;
	size_t iterations = this->cur_size_;
	for (size_t i = 0; i < iterations; i++) {
		current += i; //will increment throughout the whole array 
		currentValue = *current; //the actual element held
			//obtain values for the rhs array	
		currentComparison += i;
		currentComparisonValue = *currentComparison;
		if (currentValue != currentComparisonValue) {
			return false;
		}//end if 
	}//end for loop
	//if found no inequalities, arrays are equal
	return true;

}//end == overload 



//
// operator !=
//
template <typename T>
bool Base_Array <T>::operator != (const Base_Array& rhs) const
{
	//use already made '==' overload
	if (*this == rhs) {
		return false;
	}//end if 
	else {
		return true;
	}//end else
} //end != overload method 



//
// fill
//
template <typename T>
void Base_Array <T>::fill(T value)
{
	int iterations = this->cur_size_;
	for (int i = 0; i < iterations; i++) {
		this->set(i,value); //use the set method 
	}//end for 	

}//end fill method 



//
//	Print Array 
//
template <typename T>
void Base_Array<T>::printArray(void) const {
	std::cout << "\nContents stored: " << std::endl;
	T output; 
	for (size_t i = 0; i < this->cur_size_; i++) {
		output = this->get(i);
		std::cout << "[" << i << "] = " << output << std::endl;
	}//end for
}//end print array method 



//
//	reverse 
//
template <typename T>
void Base_Array <T>::reverse(void)
{
	size_t size = this->cur_size_;
	//initially have pointers to the first element and last element of the array 
	T* currentLower = this->data_;//pointer to the character lower in index
	T* currentHigher = (this->data_) + size - 1; //pointer to the character higher in index 
	T temp; //intermediate variable 	
		//will loop, switching values at pointers until the pointers are at least equal
	while (currentHigher > currentLower) {
		temp = *currentLower;
		*currentLower = *currentHigher;
		*currentHigher = temp;
		++currentLower;
		--currentHigher;
	}//end while 
}//end reverse



//
//	Set the current size 
//
template <typename T>
void Base_Array<T>::set_cur_size_(size_t new_cur_size_)
{
	this->cur_size_ = new_cur_size_; 
}



//
// Returns the data pointer
//
template <typename T>
T* Base_Array <T>:: get_data_pointer(void){
	return this->data_;
}//end get data_ method 



//
// Returns data pointer but its const 
//
template <typename T>
T* Base_Array <T>::get_data_pointer_const(void) const
{
	return this->data_;
} //end return const data pointer method 



//
// Swaps the data pointers at two Base_Array objects 
//
template <typename T>
void Base_Array<T>::swap(Base_Array& rhs) {
	//swap the current size values
	int between = this->cur_size_;
	this->cur_size_ = rhs.cur_size_;
	rhs.cur_size_ = between;

	//swap the data_ pointers 
	T* intermediate;
	intermediate = this->data_;
	this->data_ = rhs.data_;
	rhs.data_ = intermediate;
}//end swap 



//
// Sets the data pointer of the calling object to that of the rhs. Go from the beginning index 
//
template <typename T>
void Base_Array<T>::setData_pointer(const Base_Array& rhs, size_t begin) {
	this->data_= rhs.data_; //want to give in rhs the calling objects pointer 
	this->data_ += begin;
}//end set data_ pointer 



template <typename T>
void Base_Array<T>::set_data_null(void){
	T* toSetNull = this->data_;
	for(size_t i = 0; i < this->cur_size_; i++)
		toSetNull = nullptr;
		toSetNull++;
}//end set data null 



//
// reallocates memory to a particular size 
//
template <typename T> 
void Base_Array<T>:: reallocate_memory(size_t dataLength){
	
	T* newData = new T[dataLength]; 
	delete [] data_; 
	this->data_ = newData;
 	
}//end reallocation method 



