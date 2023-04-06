#ifndef _STACK_EXPR_COMMAND_FACTORY_H_
#define _STACK_EXPR_COMMAND_FACTORY_H_


#include "Commands.cpp" 
#include "Expr_Command_Factory.h"

class Stack_Expr_Command_Factory: public Expr_Command_Factory
{
    public:
        virtual ~Stack_Expr_Command_Factory(void){} 

        virtual addCommand * create_addCommand (void); 

        virtual subtractCommand * create_subtractCommand (void); 

        virtual multiplyCommand * create_multiplyCommand (void); 

        virtual divideCommand * create_divideCommand (void); 

        virtual moduloCommand * create_moduloCommand (void); 

        virtual numberCommand * create_numberCommand (int num); 

        Stack_Expr_Command_Factory (Stack<int> & inputStack):
            stack(inputStack){} 

    private: 
       Stack <int> & stack;

};

#endif
