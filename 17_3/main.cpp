#include <iostream>

bool substr(char *x, char *y){
    bool result = false;
    for (int i = 0; x[i] != '\0'; i++){
        if(result) break;
        if(x[i] == y[0]){
            for (int j = 1; y[j] != '\0'; j++){
                if (x[i + j] == y[j]){
                    result = true;
                } else {
                    result = false;
                    break;
                }
            }
        }
    }
}

int main() {
    char* a = "Hello world";
    char* b = "wor";
    char* c = "banana";

    std::cout << "Substring b: " << (substr(a,b) ? "True\n" : "False\n");
    std::cout << "Substring c: " << (substr(a,c) ? "True\n" : "False\n");
    return 0;
}
