#include <iostream>
#include <map>
#include <fstream>

std::pair<int, float> maior(const std::map<int, float>& faturamento) {
    int diaMaiorValor = 0;
    float maiorValor = 0;

    for (const auto& par : faturamento) {
        if (par.second > maiorValor) {
            maiorValor = par.second;
            diaMaiorValor = par.first;
        }
    }

    return {diaMaiorValor, maiorValor};
}

std::pair<int, float> menor(const std::map<int, float>& faturamento) {
    int diaMenorValor = 0;
    float menorValor = faturamento.begin()->second; 

    for (const auto& par : faturamento) {
        if (par.second < menorValor) {
            menorValor = par.second;
            diaMenorValor = par.first;
        }
    }

    return {diaMenorValor, menorValor};
}

float media(const std::map<int, float>& faturamento) {
    float soma = 0;
    int qtdValores = faturamento.size();

    for (const auto& par : faturamento) {
        soma += par.second;
    }

    return qtdValores > 0 ? soma / qtdValores : 0;
}

int diasAcimaDaMedia(const std::map<int, float>& faturamento) {
    float medias = media(faturamento);
    int contador = 0;

    for (const auto& par : faturamento) {
        if (par.second > medias) {
            contador++;
        }
    }

    return contador;
}

int main() {
    std::map<int, float> faturamento;
    int dia;
    float valor;
    char continuar;

    do {
        std::cout << "Digite o dia do faturamento: ";
        std::cin >> dia;

        std::cout << "Digite o valor do faturamento: ";
        std::cin >> valor;

        faturamento[dia] = valor;

        std::cout << "Deseja inserir outro valor? (s/n): ";
        std::cin >> continuar;

    } while (continuar == 's' || continuar == 'S');

    std::cout << "\nLista de faturamento:\n";
    for (const auto& par : faturamento) {
        std::cout << "Dia " << par.first << ": R$ " << par.second << std::endl;
    }

    std::pair<int, float> resultadoMaior = maior(faturamento);
    int diaMaior = resultadoMaior.first;
    float maiorValor = resultadoMaior.second;
    std::cout << "\nO maior faturamento foi de R$ " << maiorValor << " no dia " << diaMaior << ".\n";

    std::pair<int, float> resultadoMenor = menor(faturamento);
    int diaMenor = resultadoMenor.first;
    float menorValor = resultadoMenor.second;
    std::cout << "O menor faturamento foi de R$ " << menorValor << " no dia " << diaMenor << ".\n";

    std::cout << "A media de faturamento foi de R$ " << media(faturamento) << ".\n";

    int diasAcima = diasAcimaDaMedia(faturamento);
    std::cout << "Numero de dias com faturamento superior a media: " << diasAcima << std::endl;

    std::cout << "\nPrograma finalizado!" << std::endl;

    return 0;
}
