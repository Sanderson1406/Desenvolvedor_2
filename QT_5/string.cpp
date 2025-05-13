#include <iostream>
#include <string>

void inverterString(std::string& str) {
    int n = str.length();

    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - 1 - i];
        str[n - 1 - i] = temp;
    }
}

int main() {
    std::string texto;

    std::cout << "Digite uma string: ";
    std::getline(std::cin, texto);

    inverterString(texto);

    std::cout << "String invertida: " << texto << std::endl;

    return 0;
}
