#include <iostream>

bool pertenceFibonacci(int num) {
    int a = 0, b = 1, temp;

    while (a <= num) {
        if (a == num) return true;
        temp = a + b;
        a = b;
        b = temp;
    }
    return false;
}

int main() {
    int numero;
    std::cout << "Digite um numero: ";
    std::cin >> numero;

    if (pertenceFibonacci(numero)) {
        std::cout << numero << " pertence a sequencia de Fibonacci.\n";
    } else {
        std::cout << numero << " NAO pertence a sequencia de Fibonacci.\n";
    }

    return 0;
}