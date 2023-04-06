   // -*- C++ -*-
// $Id: Stack.h 380 2010-02-08 05:10:33Z hillj $

//==============================================================================
/**
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _CS507_STACK_H_
#define _CS507_STACK_H_

#include <exception>

#include "Array.h" 

#include <cstring>

// COMMENT You should use aggregation instead of inheritance since logically a
// stack is not an array. Because you are using inheritence, you are force to hide
// methods that do not make sense to this class.
// Included an array as a member instead - Grant Templin 

/**
 * @class Stack
 *
 * Basic stack for abitrary elements.
 * Will be derived from the 
 */
template <typename T>
class Stack
{	
public:
  /// Type definition of the type.
  typedef T type;

  /**
   * @class empty_exception
   *
   * Exception thrown to indicate the stack is empty.
   */
  class empty_exception : public std::exception
  {
  public:
    /// Default constructor.
    empty_exception (void)
      : std::exception () { }

    /**
     * Initializing constructor.
     *
     * @param[in]      msg         Error message.
     */
    empty_exception (const char * msg)
      : std::exception(msg) { }
  };

  /// Default constructor.
  Stack (void);

  /// constructor for stack of different size 
  Stack(size_t arraySize);

  /// Copy constructor.
  Stack (const Stack & s);

  /// Destructor.
  ~Stack (void);



  /**
   * Assignment operator
   *
   * @param[in]      rhs           Right-hand side of operator
   * @return         Reference to self
   */
  const Stack & operator = (const Stack & rhs);



  /**
   * Push a new \a element onto the stack. The element is inserted
   * before all the other elements in the list.
   *
   * @param[in]      element       Element to add to the list
   */
  void push (T element);



  /**
   * Remove the top-most element from the stack.
   *
   * @exception      empty_exception    The stack is empty.
   */
  void pop (void);



  /**
   * Get the top-most element on the stack. If there are no element 
   * on the stack, then the stack_is_empty exception is thrown.
   *
   * @return         Element on top of the stack.
   * @exception      empty_exception    The stack is empty
   */
  T top (void) const;



  /**
   * Test if the stack is empty
   *
   * @retval         true          The stack is empty
   * @retval         false         The stack is not empty
   */
  bool is_empty (void) const;



  /**
   * Number of element on the stack.
   *
   * @return         Size of the stack.
   */
  size_t size (void) const;



  /// Remove all elements from the stack.
  void clear (void); 


  // Prints the contents of the stack with the top element being
  // printed first and the bottom element being printed last 
  void printStack(void);

  void printStackArrayIndex(size_t index);

private:
  // add member variable here

    T * topElement; //contains the top of the stack, whatever it may be type wise 
    size_t topElementIndex; 
    size_t stackSize; 
    Array<T> array; //is the array that holds the stack's data 
};

// include the inline files
//#include "Stack.inl"

#include "Stack.cpp"

#endif  // !defined _CS507_STACK_H_
