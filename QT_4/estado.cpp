#include <iostream>
#include <map>
#include <iomanip>

int main() {
    std::map<std::string, float> estados = {
        {"SP", 67836.43},
        {"RJ", 36678.66},
        {"MG", 29229.88},
        {"ES", 27165.48},
        {"Outros", 19849.53}
    };

    float total = 0;
    for (const auto& estado : estados) {
        total += estado.second;
    }
    
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Percentual de representacao de cada estado:\n";
    for (const auto& estado : estados) {
        float percentual = (estado.second / total) * 100;
        std::cout << estado.first << ": " << percentual << "%\n";
    }

    return 0;
}
