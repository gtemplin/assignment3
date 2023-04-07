// -*- C++ -*-
// $Id: Array.h 380 2010-02-08 05:10:33Z hillj $

//==============================================================================
/**
 * @file       Array.h
 *
 * $Id: Array.h 380 2010-02-08 05:10:33Z hillj $
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <cstring>          // for size_t definition

#include "Base_Array.h"


/**
 * @class Array
 *
 * Basic implementation of a standard array class for chars.
 */
template <typename T>
class Array : public Base_Array<T>
{
public:
  /// Type definition of the element type.
  typedef T type;



  /// Default constructor.
  Array(void);



  /**
   * Initializing constructor.
   *
   * @param[in]      length        Initial size
   */
  Array(size_t length);



  /**
   * Initializing constructor.
   *
   * @param[in]      length        Initial size
   * @param[in]      fill          Initial value for each element
   */
  Array(size_t length, T fill);



  /**
   * Copy constructor
   *
   * @param[in]     arr         The source array.
   */
  Array(const Array& arr);



  /*
  
	Methods that are added on from the base array class
  
  */



  /*
	Equality operator 
	Not in base class due to issues with fixed array
  */
  const Array& operator = (const Array& rhs);



  /**
   * Retrieve the maximum size of the array.
   *
   * @return          The maximum size
   */
  size_t max_size(void) const;



  /**
   * Set a new size for the array. If \a new_size is less than the current
   * size, then the array is truncated. If \a new_size if greater then the
   * current size, then the array is made larger and the new elements are
   * not initialized to anything. If \a new_size is the same as the current
   * size, then nothing happens.
   *
   * The array's original contents are preserved regardless of whether the
   * array's size is either increased or decreased.
   *
   * @param[in]       new_size              New size of the array
   */
  void resize(size_t new_size);


  //shrink method
  void shrink(void);



  //increments the current size of the array 
  void increment_cur_size_(int value);



  //increments the max size of the array 
  void increment_max_size_(int value);



  /**
	 Shallow copy slice method 
  */
  Array slice(size_t begin) const;

  /**
   Shallow copy slice method 
   */
  Array slice(size_t begin, size_t end) const;


  private:
  /// Pointer to the actual data.
  
  T * data_;

  //char * data_;

  /// Current size of the array.
  size_t cur_size_;

  /// Maximum size of the array.
  size_t max_size_;
};

//for method declarations 
#include "Array.cpp"


#endif   // !defined _ARRAY_H_
