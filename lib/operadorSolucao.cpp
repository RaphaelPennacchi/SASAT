#include <vector>
#include <random>
#include <iostream>

using namespace std;

typedef struct operadorSolucao {
  int nVariable = 0;
  vector<int> solution = vector<int>(0);



  void gerar(void) {
    // Se nVariable não for setada retorna vetor vazio;
    if (!nVariable) { solution = vector<int>(0); return; }
    // Coisas pro random
    if (!solution.empty()) solution.clear();
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, 1);
    vector<int> clausule;
    // gera os numeros e coloca no vetor;
    for (int i = 0; i < nVariable; i++) {
      int holder = distrib(gen);
      if (!holder) holder = -1;
      solution.push_back(holder);
    }
  }

  void printSolution(void) {
    cout << "Possivel solucao" << endl;
    for (auto& literal : solution) {
      cout << literal;
    }
    cout << endl;
  }

  operadorSolucao(int n) {
    // Inicializa a estrutura
    nVariable = n;
  }

} OperadorSolucao;
