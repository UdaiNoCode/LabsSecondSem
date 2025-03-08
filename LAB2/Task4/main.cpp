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

bool check_equals(Expression const* left, Expression const* right) {
    return *(double **)left == *(double  **)right;
}

int main() {
    Expression* a = new Number(5);
    Expression* b = new Number(10);
    Expression* c = new BinaryOperation(a, '+', b);

    bool result1 = check_equals(a, b); // true
    bool result2 = check_equals(a, c); // false

    std::cout<<result1 << " "<< result2;
}
