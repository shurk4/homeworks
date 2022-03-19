#include <iostream>

void foo(int *pa, int *pb){
    std::cout << "before swap: " << *pa << std::endl;
    std::cout << "before swap: " << *pb << std::endl;

    std::swap(pa, pb);

    std::cout << "after swap: " << *pa << std::endl;
    std::cout << "after swap: " << *pb << std::endl;
}

int main() {
    int a = 2,
        b = 5;

    foo(&a,&b);

    return 0;
}
