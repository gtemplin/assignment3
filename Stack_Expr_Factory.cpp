#include "Expr_Command_Factory.h"
#include "Stack_Expr_Factory.h"
#include "Commands.cpp" 



addCommand* Stack_Expr_Command_Factory::create_addCommand(void){
    addCommand* returnCommand = new addCommand(this->stack);
    return returnCommand;
}//end create command 



subtractCommand* Stack_Expr_Command_Factory::create_subtractCommand(void){
    subtractCommand* returnCommand = new subtractCommand(this->stack);
    return returnCommand;
}//end create command 



multiplyCommand* Stack_Expr_Command_Factory::create_multiplyCommand(void){
    multiplyCommand* returnCommand = new multiplyCommand(this->stack);
    return returnCommand; 
}//end create command



divideCommand* Stack_Expr_Command_Factory::create_divideCommand(void){
    divideCommand* returnCommand = new divideCommand(this->stack);
    return returnCommand; 
}//end create command 



moduloCommand* Stack_Expr_Command_Factory::create_moduloCommand (void){
    moduloCommand* returnCommand = new moduloCommand(this->stack);
    return returnCommand; 
}//end create commad 



numberCommand* Stack_Expr_Command_Factory::create_numberCommand (int num){
    numberCommand* returnCommand = new numberCommand(this->stack, num);
    return returnCommand;
}



int returnTopOfStack(void) {
    return this->stack.top();
}


//Stack_Expr_Command_Factory::~Stack_Expr_Command_Factory(void){

//}//




   
