#ifndef _COMMANDS_CPP_
#define _COMMANDS_CPP_

#include "Expr_Command.h"
#include "Stack.h"


class addCommand: public Expr_Command{
    public: 
    //constructor 
        addCommand(Stack<int> & stack_input):
            stack(stack_input){}

    //execute command
        virtual void execute(void){
            //get the top two values of the stack 
            //and pop them 
            int n2 = stack.top();
            stack.pop();
            int n1 = stack.top();
            stack.pop(); 
            //push the value after expression 
            stack.push(n1+n2);
        }//end execute adding 

    private: 
        Stack <int> & stack;
        
}; //end add command 



class subtractCommand: public Expr_Command{
    public: 
    //constructor 
        subtractCommand(Stack<int> & stack_input):
            stack(stack_input){}

    //execute command
        virtual void execute(void){
            //get the top two values of the stack 
            //and pop them 
            int n2 = stack.top();
            stack.pop();
            int n1 = stack.top();
            stack.pop(); 
            //push the value after expression 
            stack.push(n1-n2); 
        }//end execute adding 

    private: 
        Stack <int> & stack;

}; //end subtract command 




class multiplyCommand: public Expr_Command{
    public: 
    //constructor 
        multiplyCommand(Stack<int> & stack_input):
            stack(stack_input){}

    //execute command
        virtual void execute(void){
            //get the top two values of the stack 
            //and pop them 
            int n2 = stack.top();
            stack.pop();
            int n1 = stack.top();
            stack.pop(); 
            //push the value after expression 
            stack.push(n1*n2); 
        }//end execute adding 

    private: 
        Stack <int> & stack;

}; //end multiply command 



class divideCommand: public Expr_Command{
    public: 
    //constructor 
        divideCommand(Stack<int> & stack_input):
            stack(stack_input){}

    //execute command
        virtual void execute(void){
            //get the top two values of the stack 
            //and pop them 
            int n2 = stack.top();
            stack.pop();
            int n1 = stack.top();
            stack.pop(); 
            //push the value after expression 
            stack.push(n1/n2); 
        }//end execute adding 

    private: 
        Stack <int> & stack;

}; //end divide command 



class moduloCommand: public Expr_Command{
    public: 
    //constructor 
        moduloCommand(Stack<int> & stack_input):
            stack(stack_input){}

    //execute command
        virtual void execute(void){
            //get the top two values of the stack 
            //and pop them 
            int n2 = stack.top();
            stack.pop();
            int n1 = stack.top();
            stack.pop(); 
            //push the value after expression 
            stack.push(n1%n2); 
        }//end execute adding 

    private: 
        Stack <int> & stack;

}; //end modulo command 



class numberCommand: public Expr_Command{
    public: 
    //constructor 
        numberCommand(Stack<int> & stack_input, int inputNumber):
            stack(stack_input),
            number(inputNumber){}

    //execute command
        virtual void execute(void){
            stack.push(number);
        }//end execute adding 

    private: 
        Stack <int> & stack;
        int number; 

}; //end number command 



#endif
