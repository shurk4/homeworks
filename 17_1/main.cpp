#include <iostream>

void foo(int *pa, int *pb){
    std::cout << "pa before swap: " << *pa << std::endl;
    std::cout << "pb before swap: " << *pb << std::endl;

    std::swap(pa, pb);

    std::cout << "pa after swap: " << *pa << std::endl;
    std::cout << "pb after swap: " << *pb << std::endl;
}

int main() {
    int a = 2,
        b = 5;

    int *pa = &a,
        *pb = &b;

    foo(&a,&b);

    std::cout << "a: " << a << " b: " << b << std::endl;

    return 0;
}
