#include <iostream>
#include <vector>
#include "vector.h"

int main() {



    myStd::vector<int> v = {};

    myStd::vector<int> v_2 = {1,10,7};
    std::cout<<"\n";
    std::vector<int> vv;

    myStd::vector<int> values { 10, 20, 30, 40, 50 };
    myStd::vector<int> numbers3 { 1, 2, 3, 4, 5 };
    auto iter3 = numbers3.begin(); // константный итератор указывает на первый элемент
// добавляем после первого элемента три первых элемента из вектора values
    numbers3.insert(iter3 + 1, values.begin(), values.begin() + 3);
    for (const auto &item: numbers3){
        std::cout<<item << " ";
    }
    std::cout<<std::endl;

    numbers3.erase(numbers3.begin() + 1, numbers3.begin() + 5);

    for (const auto &item: numbers3){
        std::cout<<item << " ";
    }

//numbers3 = { 1, 10, 20, 30, 2, 3, 4, 5};
    return 0;
}
