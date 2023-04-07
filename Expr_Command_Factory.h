#ifndef _EXPR_COMMAND_FACTORY_H_
#define _EXPR_COMMAND_FACTORY_H_

#include "Commands.cpp" 

class Expr_Command_Factory
{
    public:
        //virtual ~Expr_Command_Factory(void) = 0; 

        virtual addCommand * create_addCommand (void) = 0; 

        virtual subtractCommand * create_subtractCommand (void) = 0; 

        virtual multiplyCommand * create_multiplyCommand (void) = 0; 

        virtual divideCommand * create_divideCommand (void) = 0; 

        virtual moduloCommand * create_moduloCommand (void) = 0; 

        virtual numberCommand * create_numberCommand (int num) = 0; 

        Expr_Command_Factory(){}

        ~Expr_Command_Factory(void){};
        
    private:
       // Expr_Command_Factory (const Expr_Command_Factory &){}

       // const Expr_Command_Factory & operator = (const Expr_Command_Factory &){}
};

#endif
