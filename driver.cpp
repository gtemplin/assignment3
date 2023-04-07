
//Built in librariers 
#include <string.h>
#include <iostream>

//Arrays and array helpers 
#include "Array.h"
#include "Array_Iterator.h"

//Commands and their helpers 
#include "Expr_Command.h"
#include "Commands.cpp"
#include "Expr_Command_Factory.h"
#include "Stack_Expr_Command_Factory.h"

//Functions that perform the calculator operations 
#include "Infix_Postfix_Evaluator.h"

//Default length if needed
#define default_length 10


int main(){


	std::string infix = "Begin";

	//create the stack and factory that will be used to create the commands  
	Stack<int> result;
	Stack_Expr_Command_Factory factory(result);

	//define an array to store the created commands 
	Array <Expr_Command*> postfix;

	int value = 0; //will store the result of the equation
	value++; 
	
	while(infix != "QUIT"){
		std::cout << "Input an infix expression: "; 
		std::getline(std::cin, infix);
		std::cout<<"\nInfix outside of function: " << infix << std::endl;
		value = returnPostfix(infix, factory, postfix);
		infix = "QUIT";
	}//end while 

	return 0;
}//end main





	
