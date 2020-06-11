#include "Pool.h"
#include <iostream>

int main() {

    
    Pool<int, 10> pool;

    //int* a = pool.allocate();
    //int* b= pool.allocate(3);
    //pool.deallocate(a);
    //pool.deallocate(b, 2);
    //int* c = pool.construct(42);
    

    std::cout << "Testing Setup" << std::endl;

    return 0;
}