//create the postfix expression
#include "Infix_Postfix_Evaluator.h"
#include "Stack.h"
#include "Array.h"

//Built in libraries 
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <ctype.h> 

//make commands from the postfix expression to solve 
#include "Expr_Command_Factory.h"
#include "Stack_Expr_Command_Factory.h"


#define default_length 10

int returnPostfix(std::string & infixString, Stack_Expr_Command_Factory factory, Array<Expr_Command*> postfix){
    int result = 0;
    Stack<std::string> toolStack; //stack to be used in the infix-postfix algorithm
    Array<std::string> commandFactoryInput; //array of strings that will be used by the command factory 
    commandFactoryInput.set_cur_size_(infixString.length() + default_length); //set size of the array w/ padding 
    int nextArrayIndex = 0; //tells function where it should append to the command factory input 
    std::string algoToken = ""; //will be the token (opeator or number) input to the algorithm 
    
    infixString += ' '; //makes algorithm simpler 

    //traverse the string, store whatever is in between spaces. 
    //then use that stored string as the algorithm's input 
    for (auto it = infixString.cbegin(); it != infixString.cend(); ++it){

	std::cout<<"\nChar to be analyzed: "<< *it << std::endl;
	std::cout<<"The nextArrayIndex variable is "<<nextArrayIndex<<std::endl;	

        if(*it != ' '){
            algoToken += *it; //append if a space was not seen
        }
        else if(*it == ' '){
            std::cout<<"\nThe token to be used is [" << algoToken << "]" << std::endl;
            infix_to_postfix(algoToken, toolStack, commandFactoryInput, nextArrayIndex); //input to the algorithm 
            algoToken = ""; //reset the token to be appendable 
        }//end if-else
    }//end for 


	std::cout << "\nEmpty the stack " << std::endl;
    //have gone through the whole input expression. Now pop remaining symbols 
    //from the stack and append them to the postfix expression 
    while(!toolStack.is_empty()){
	toolStack.printStack();
        algoToken = toolStack.top();
	std::cout<<"\nPlace " << algoToken << " within the postfix array" << std::endl;
        commandFactoryInput.set(nextArrayIndex, algoToken);
        nextArrayIndex++;
	toolStack.pop();
    }//end while


	std::cout<<"\nFinished. Next is the postfix"<<std::endl;
	commandFactoryInput.printArray();


    std::cout<<"\nComplete postfix expression: ";
    commandFactoryInput.printArray();    
    //now take the postfix expression and create the command array 
    postfix = makeCommandArray(commandFactoryInput);
    //now postfixArray holds the postfix expression commands and can be evaluated
    result = evaluatePostfix(postfix);
    return result; 

}//end return postfix 



//updates postfixArray with every token input 
void infix_to_postfix(std::string token, Stack<std::string> & stack, Array<std::string> & postfixArray, int & nextArrayIndex){
   
    //these functions describe what to do with operators and numerical digits 
    if(isOperator(token) == true){    
	    operatorTool(token, stack, postfixArray, nextArrayIndex);
    }
    else if (isNumber(token) == true){
        postfixArray.set(nextArrayIndex, token);
        nextArrayIndex++;
	std::cout<<"\nSet the number in the postfix array" << std::endl;
    }//end if-else
    else{
	std::cout<<"\nToken is " << token << " within algo" << std::endl;
    }//end else

	std::cout<<"\nPostfix within the algorithm function: "<<std::endl;
	postfixArray.printArray();
	stack.printStack();

} //end algorithm 


void operatorTool(std::string & token, Stack<std::string> & stack, Array<std::string> & postfixArray, int & nextArrayIndex){
    std::cout<<"\nEntered the operator tool "; 
    //keep going while the elements on the stack have >= precedence compared to the token 
    while(higherOrEqualPrecedence(token, topOfStackIfNotEmpty(stack))){
           postfixArray.set(nextArrayIndex, topOfStackIfNotEmpty(stack));
           nextArrayIndex++;
    }//end while 
	
	std::cout<<"\nUsed the operator tool, now push operator onto the stack"<<std::endl;

    stack.push(token);

	std::cout<<"\nPushed onto the stack"<<std::endl;
}//end operator tool


/////// Tool functions ///////

bool isOperator(std::string token){


    if(token.compare("*") == 0 || token.compare("/") == 0 || token.compare("%") == 0 || token.compare("+") == 0 || token.compare("-") == 0){
        std::cout<<"\nThe token was an operator" << std::endl;
	return true;
    }
    else{
        return false;
    }
}//end is operator 

bool isNumber(std::string token){
     for (char c : token){
        if (!isdigit(c)) {
            return false;
        }
     }

     std::cout<<"\nThe token was a number" << std::endl;
     return true; 
}//end is number 

std::string topOfStackIfNotEmpty(Stack<std::string> & stack){
    if(stack.is_empty()){
        return "Empty";
    }
    else{
        return stack.top();
    }
}//end topOfStack

//returns true if the test has higher precednce than the token 
bool higherOrEqualPrecedence(std::string token, std::string test){
    //if the test is F, that means that stack was empty and there is no need to empty it 
    if(test.compare("Empty") == 0)
        return false;

    // *, /, and % all have the same higher precedence 
    if(test.compare("*") == 0 || test.compare("/") == 0 || test.compare("%") == 0){
        return true; //all these tokens have the same or greater precedence  
    }
    // + and - only have equal precedence to + or -
    // if the test and the token are a + or -, return true
    else if(test.compare("+") == 0 || test.compare("-") == 0){
        if(token.compare("+") == 0 || token.compare("-") == 0){
            return true; //these have equal precedence 
        }
        else{
            return false; //otherwise test have lower precedence 
        }
    }
    else if(test.compare("(") == 0){
        return false; //if the top is a ( , can move on also 
    }
    else{
        std::cout << "\nError: is not any operator" << std::endl; 
        return false;
    }
}//end test precedence 


/////////////////////


/*
    The following functions will be used to make the commands 
    and to evaulate the postfix command array, giving an actual value 
*/
Array<Expr_Command*> makeCommandArray(Array<std::string> & postfixArray){
	Array<Expr_Command*> expr;
	return expr; 
}

//will evaluate the command array 
int evaluatePostfix(Array<Expr_Command*> & array){
	return 0;
}//end evaluate postfix 


