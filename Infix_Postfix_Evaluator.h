#ifndef _INFIX_POSTFIX_EVALUATOR_
#define _INFIX_POSTFIX_EVALUATOR_

#include <stdio.h>
#include <string>
#include "Array.h"
#include "Stack.h"
#include "Expr_Command_Factory.h"
#include "Stack_Expr_Factory.h"
#include "Commands.cpp"


//recieve an input string in infix form
//return the value of that equation input  
int returnPostfix(std::string & infixString, Stack_Expr_Command_Factory factory, Array<Expr_Command*> postfix);

//turn a character into part of the array of command expressions 
void infix_to_postfix(std::string token, Stack<std::string> & stack, Array<std::string> & postfixArray, int & nextArrayIndex);

//evaluate the array of command expressions 
int evaluatePostfix(Array<Expr_Command*> & array);


//will use this function when want to append stack/postfixArray for the infix-postfix algorithm 
void operatorTool(std::string & token, Stack<std::string> & stack, Array<std::string> & postfixArray, int & nextArrayIndex);


//see if an input string is an operator
bool isOperator(std::string token);
//see if an input string is a number
bool isNumber(std::string token);


//checks to see if the top of stack is empty
//if it is, returns the char 'F' to indicate that the precedence test should be false and the program should move on 
//if not, it returns the top of the stack 
std::string topOfStackIfNotEmpty(Stack<std::string> & stack);


//see if a token has equal or higher precedence 
bool higherOrEqualPrecedence(std::string token, std::string testPrecedence);


//tells us what command should be created  
std::string whichCommand(std::string token); 




//////////////////////////////////////////////////////////////////////////



//returns the command array 
Array<Expr_Command*> makeCommandArray(Array<std::string>& postfixArray, Stack_Expr_Command_Factory factory);


//This function assists with setting the stack and postfix array if the token is an operator



/* Code for paranthesis later 



    if(token.compare("(") == 0){
        stack.push(token);
    }//end (

    else if(token.compare(")") == 0){
        //pop off the top of the array and append it to the postfix array. 
        //afterwards, update the next out.
        //repeat until you get to the left parenthesis 
        bool poppedLeft = false;
        while(poppedLeft == false){
           postfixArray.set(nextArrayIndex, topOfStackIfNotEmpty(stack));
           nextArrayIndex++;
           if(topOfStackIfNotEmpty(stack).compare("(") == 0){
            poppedLeft = true;
           }
           stack.pop(); 
        }//end while
    }//end )




*/



#endif 
