#include <iostream>

int povrh(int n, int m) {
    if(n ==m || n == 1 || m ==0) {
        return 1;
    }
    return povrh(n-1, m-1) + povrh(n-1,m);
}

int main() {
    std::cout << povrh(50,43);
}
