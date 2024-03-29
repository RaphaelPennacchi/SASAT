#include <iostream>
#include "Solution.cpp"
#include "Clausule.cpp"
#include <utility>

#if !defined(SIMULATEDANEALLING)
#define SIMULATEDANEALLING

struct SimulatedAnealling {
  //vars
  int sucessAmount(Solution solution, vector <Clausule> clausule) {
    int counter = 0;
    for (long unsigned int i = 0; i < clausule.size(); i++) {
      if (clausule[i].isTrue(solution)) counter++;
    }
    return counter;
  }

  // TODO escolher a função

  double calculateTemperature(int actualIteration, int maxIteration, double initialTemp, double finalTemp) {
    return initialTemp - (double)actualIteration * ((initialTemp - finalTemp) / maxIteration);
  }

  double calculateTemperature2(int actualIteration, int maxIteration, double initialTemp, double finalTemp) {
    double a = (double)((initialTemp - finalTemp) * (maxIteration + 1)) / (double)maxIteration;
    double b = (double)initialTemp - a;
    return ((double)a / (double)(actualIteration + 1)) + (double)b;
  }

  pair <vector<bool>, int> run(Solution solution, vector <Clausule> clausule, int maxIterations, double initialTemp, double finalTemp, int tempFunction, int interLoop) {
    // Set the initial solution
    Solution fooSolution = solution;
    int sucess = 0, fooSucess = 0, maxGlobal = 0;
    double temperature = initialTemp;
    int probability, cost;
    int i;
    int iteraction = -1;

    while (iteraction < maxIterations) {
      iteraction++;
      if (iteraction%1000 == 0 and iteraction != 0) cout << iteraction << " " << maxGlobal << " " << endl;

      for (i = 0; i < interLoop; i++) {
        //Essa variável iteraction que será passada para a temperatura
        //Modifica a solucao em porcentagem
        fooSolution.modify((solution.nVariable / 20) ? solution.nVariable / 20 : 1);
        //Verificar se a solução atual é melhor que a anterior
        fooSucess = sucessAmount(fooSolution, clausule);
        if (fooSucess > sucess) {
          sucess = fooSucess;
          solution = fooSolution;
          maxGlobal = maxGlobal > sucess ? maxGlobal : sucess;
        }
        else {
          // Função para atualizar a temperatura
          // If para ver se aceita a nova solução ou não
          probability = (double)rand() / RAND_MAX;
          cost = exp((double)(fooSucess - sucess) / temperature);
          if (cost > probability) {
            sucess = fooSucess;
            solution = fooSolution;
          }
        }
      }

      //cout << "função temperatura : " << calculateTemperature2(i, maxIterations, initialTemp, finalTemp) << endl;
      if (tempFunction == 1) temperature = calculateTemperature2(iteraction, maxIterations, initialTemp, finalTemp);
      else temperature = calculateTemperature(iteraction, maxIterations, initialTemp, finalTemp);
      i = 0;
    }
    return make_pair(solution.solution, maxGlobal);
  }

  bool compare(double x, double y, double epsilon = 0.0000001f){
   return fabs(x - y) > epsilon;
  }

};

#endif // SIMULATEDANEALLING