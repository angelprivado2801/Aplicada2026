#include <iostream>

int main() {
    int x = 5;
    int* p = &x; 
    
    *p = 40;     
    
    std::cout << "x = " << x << "\n";
    
    return 0;
}
