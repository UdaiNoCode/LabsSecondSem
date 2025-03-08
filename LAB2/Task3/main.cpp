#include <iostream>



class Expression{
public:
    virtual double evaluate() = 0;
};

class Number: public Expression{
private:
    double number;

public:
    explicit Number(double num): number(num){

    }

    double evaluate() override{
        return this->number;
    }

};

class BinaryOperation: public Expression{
private:
    Expression* leftOperand;
    Expression* rightOperand;
    char operation;

public:
    BinaryOperation(Expression* leftOperand, char operation,Expression* rightOperand){
        this->leftOperand = leftOperand;
        this->rightOperand = rightOperand;
        this->operation = operation;
    }

    ~BinaryOperation(){
        delete leftOperand;
        delete rightOperand;
    }

    double evaluate() override{
        switch (this->operation) {
            case '+':{
                return leftOperand->evaluate() + rightOperand->evaluate();
            }
            case '-':{
                return  leftOperand->evaluate() - rightOperand->evaluate();
            }
            case '*':{
                return  leftOperand->evaluate() * rightOperand->evaluate();
            }
            case '/':{
                if(rightOperand->evaluate() == 0){
                    std::cout<<"Limited to infinity\n";
                }else {
                    return leftOperand->evaluate() / rightOperand->evaluate();
                }
                break;
            }
            default:{
                std::cout<<"Something went wrong!\n";
            }

        }
        return 0;
    }
};

int main() {
    Expression* sube = new BinaryOperation(new Number(0), '*', new Number(0));

    Expression* expr = new BinaryOperation(new Number(3), '/', sube);

    std::cout << expr->evaluate() << std::endl;

    delete expr;
}
