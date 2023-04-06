#pragma once

#ifndef _BASE_ARRAY_H_ 
#define _BASE_ARRAY_H_

#include <cstring>          // for size_t definition

#define default_length 10 

template <typename T>
class Base_Array  
{
public:

	/// Type definition of the element type.
	typedef T type;

	/// Default constructor 
	Base_Array(void);


	/**
	 * Initializing constructor.
	 *
	 * @param[in]      length        Initial size
	 */
	Base_Array(size_t length);


	/**
	 * Initializing constructor.
	 *
	 * @param[in]      length        Initial size
	 * @param[in]      fill          Initial value for each element
	 */
	Base_Array(size_t length, T fill);


	//
	//Copy constructor
	//
	Base_Array(const Base_Array<T>& array);

	

	/// Destructor.
	 ~Base_Array(void);



	//Below are methods that every single array, fixed or not, should have



	/**
   * Retrieve the current size of the array.
   *
   * @return          The current size
   */
	size_t size(void) const;


	/**
	 * Get the character at the specified index. If the index is not
	 * within the range of the array, then std::out_of_range exception
	 * is thrown.
	 *
	 * @param[in]       index               Zero-based location
	 * @exception       std::out_of_range   Invalid \a index value
	 */
	T& operator [] (size_t index);

	/**
	 * @overload
	 *
	 * The returned character is not modifiable.
	 */
	const T& operator [] (size_t index) const;

	
	/**
	 * Get the character at the specified index. If the \a index is not within
	 * the range of the array, then std::out_of_range exception is thrown.
	 *
	 * @param[in]       index                 Zero-based location
	 * @return          Character at \index
	 * @exception       std::out_of_range     Invalid index value
	 */
	T get(size_t index) const;


	/**
   * Set the character at the specified \a index. If the \a index is not
   * within range of the array, then std::out_of_range exception is 
   * thrown.
   *
   * @param[in]       index                 Zero-based location
   * @param[in]       value                 New value for character
   * @exception       std::out_of_range     Invalid \a index value
   */
	void set(size_t index, T value);


	/**
   * @overload
   *
   * This version allows you to specify the start index of the search. If
   * the start index is not within the range of the array, then the
   * std::out_of_range exception is thrown.
   *
   * @param[in]       ch                   Character to search for
   * @param[in]       start                Index to begin search
   * @return          Index value of first occurrence
   * @retval          -1                   Character not found
   * @exception       std::out_of_range    Invalid index
   */
	int find(T element, size_t start) const;


	/**
   * Test the array for equality.
   *
   * @param[in]       rhs                  Right hand side of equal to sign
   * @retval          true                 Left side is equal to right side
   * @retval          false                Left side is not equal to right side
   */
	bool operator == (const Base_Array& rhs) const;


	/**
	 * Test the array for inequality.
	 *
	 * @param[in]       rhs                  Right-hand size of not equal to sign
	 * @retval          true                 Left side is not equal to right side
	 * @retval          false                Left size is equal to right side
	 */
	bool operator != (const Base_Array& rhs) const;


	/**
	 * Fill the contents of the array.
	 *
	      
	 * @param[in]       ch                   Fill character
	 */
	void fill(T element);

	//
	// Prints the contents of the array 
	//
	void printArray(void) const;


	/// Reverse the contents of the array such that the first element is now
	/// the last element and the last element is the first element.
	void reverse(void);


	//
	// Sets the current size of the array
	//
	void set_cur_size_(size_t new_cur_size_);

	
	

	
 	 /*
   	*	Returns the 0th element pointer 
  	*/
  	T* get_data_pointer(void);

	T* get_data_pointer_const(void) const;



	//
	//	swaps the data values for two arrays 
	//
	void swap(Base_Array& rhs);


	//
	// Set data pointer
	//
	void setData_pointer(const Base_Array& rhs, size_t begin);



	//
	//sets all the data pointers within the array to a null pointer
	//
	void set_data_null(void);



	//
	// reallocates memory 
	//
	void reallocate_memory(size_t dataLength);



private:
	/// Pointer to the actual data.   
	T* data_;  

	//Size of the array 
	size_t cur_size_; 

}; //end class definition 

//for function implementations  
#include "Base_Array.cpp"


#endif //_BASE_ARRAY_H_ defined 
