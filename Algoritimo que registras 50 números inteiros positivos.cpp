#include <iostream>
#include <limits>

// Função para inserir números na lista sem repetição
void inserirSemRepetir(int v[], int valor, int& pos, int max) {
    bool existe = false;

    // Verifica se o número já existe na lista
    for (int i = 0; i < pos; i++) {
        if (v[i] == valor) {
            existe = true;
            break;
        }
    }

    // Insere o número se ele não existe e há espaço na lista
    if (!existe && pos < max) {
        v[pos] = valor;
        pos++;
    }
}

// Função para listar os números da lista
void listar(int v[], int quantidade) {
    for (int i = 0; i < quantidade; i++) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

// Função para limpar o buffer de entrada
void limparBuffer() {
    std::cin.clear(); // Limpa o estado de erro
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignora o restante da entrada
}

int main() {
    const int MAX_NUMEROS = 50;
    int numeros[MAX_NUMEROS];
    int pos = 0;
    int valor;

    std::cout << "Digite até 50 números inteiros. A inserção para quando um número negativo for digitado." << std::endl;

    while (pos < MAX_NUMEROS) {
        std::cout << "Digite um número: ";
        std::cin >> valor;

        // Verifica se a entrada foi inválida
        if (std::cin.fail()) {
            std::cout << "Entrada inválida! Por favor, digite apenas números inteiros." << std::endl;
            limparBuffer();  // Limpa o buffer de entrada
            continue;  // Solicita nova entrada
        }

        if (valor < 0) {
            break; // Interrompe a inserção ao digitar um número negativo
        }

        inserirSemRepetir(numeros, valor, pos, MAX_NUMEROS);
    }

    std::cout << "Números inseridos sem repetição: ";
    listar(numeros, pos);

    return 0;
}