#include <vector>
#include <random>
#include <iostream>

using namespace std;


#if !defined(SOLUTION)
#define SOLUTION

struct Solution {
  int nVariable = 0;
  vector<bool> solution = vector<bool>(0);

  void generate(void) {
    // Se nVariable não for setada retorna vetor vazio;
    if (!nVariable) { solution = vector<bool>(0); return; }
    // Coisas pro random
    if (!solution.empty()) solution.clear();
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, 1);
    vector<int> clausule;
    // gera os numeros e coloca no vetor;
    for (int i = 0; i < nVariable; i++) {
      int holder = distrib(gen);
      solution.push_back(holder);
    }
  }

  void modify(int amountOfChanges) {
    // Random functions 
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, nVariable-1);
    // Real code
    for(int i=0; i < amountOfChanges; i++){
      int holder = distrib(gen);
      flip(holder);
    }
  }

  void flip(int position){
    solution[position] = solution[position] > 0 ? false : true;
  }

  void print(void) {
    cout << "Possivel solucao" << endl;
    for (auto&& literal : solution) {
      cout << literal;
    }
    cout << endl;
  }


  // Solution Constructor
  Solution(int n) {
    // Inicializa a estrutura
    nVariable = n;
  }
};

#endif // MACRO