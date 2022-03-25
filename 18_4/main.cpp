#include <iostream>

void evenCounter (long long int& num, int& result){
    if(num == 0) return;
    if(num % 10 % 2 == 0) result++;
    long long int temp = num / 10;
    evenCounter(temp, result);
}

int main() {
    int ans = 0;
    long long int digits = 9223372036854775806;

    evenCounter(digits, ans);

    std::cout << "There are " << ans << " even digits in the number " << digits << std::endl;
    return 0;
}
