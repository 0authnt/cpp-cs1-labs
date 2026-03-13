#include <iostream>


int main(){

    int fibonacci(int n){
        if(n == 0){
            return 0;
        }
        else if(n == 1){
            return 1;
        }
        else{
            return fibonacci(n-1) + fibonacci(n-2)
        }
    }


    fibonacci(300);
}


#include <iostream>

void fibRecursive(int n, int a, int b) {
    if (n <= 0) return;
    std::cout << a << ' ';
    fibRecursive(n - 1, b, a + b);
}

void fibTailHelper(int n, int a, int b) {
    if (n <= 0) return;
    std::cout << a << ' ';
    fibTailHelper(n - 1, b, a + b);
}

void fibTail(int n) {
    fibTailHelper(n, 0, 1);
}

int fibValue(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibValue(n - 1) + fibValue(n - 2);
}

void printRegular(int n, int i = 0) {
    if (i >= n) return;
    std::cout << fibValue(i) << ' ';
    printRegular(n, i + 1);
}

int main() {
    int n;
    std::cout << "How many Fibonacci numbers? ";
    std::cin >> n;

    std::cout << "Regular recursion: ";
    printRegular(n);
    std::cout << std::endl;

    std::cout << "Tail recursion: ";
    fibTail(n);
    std::cout << std::endl;

    return 0;
}

//this should not run lol
