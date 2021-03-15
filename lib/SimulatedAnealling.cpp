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

  pair <vector<bool>, int> run(Solution solution, vector <Clausule> clausule, int maxIterations, double initialTemp, double finalTemp, int tempFunction) {
    // Set the initial solution
    Solution fooSolution = solution;
    int sucess = 0, fooSucess = 0;
    double temperature = initialTemp;
    int probability, cost, counter = 0;
    int i;
    int iteraction = -1;

    cout << "compare: " << ((double)temperature * 1.0) - finalTemp << " " << temperature << " " << finalTemp  << endl;
    while (temperature > finalTemp) {
      cout << "Iteraction : " << iteraction << endl;
      cout << "Temperature : " << temperature << endl;
      for (i = 0; i < maxIterations && iteraction < 250000; i++) {
        //Essa variável iteraction que será passada para a temperatura
        iteraction++;
        //Modifica a solucao em porcentagem
        fooSolution.modify((solution.nVariable / 20) ? solution.nVariable / 20 : 1);
        //Verificar se a solução atual é melhor que a anterior
        fooSucess = sucessAmount(fooSolution, clausule);
        if (fooSucess > sucess) {
          sucess = fooSucess;
          solution = fooSolution;
        }
        else {
          // Função para atualizar a temperatura
          // If para ver se aceita a nova solução ou não
          probability = (double)rand() / RAND_MAX;
          cost = exp((double)-(fooSucess - sucess) / temperature);
          if (cost > probability) {
            sucess = fooSucess;
            solution = fooSolution;
          }
        }
      }
      cout << "função temperatura : " << calculateTemperature2(i, maxIterations, initialTemp, finalTemp) << endl;
      if (tempFunction == 1) temperature = calculateTemperature2(iteraction, maxIterations, initialTemp, finalTemp);
      else temperature = calculateTemperature(iteraction, maxIterations, initialTemp, finalTemp);
      i = 0;
    }
    return make_pair(solution.solution, sucess);
  }

  bool compare(double x, double y, double epsilon = 0.0000001f){
   return fabs(x - y) > epsilon;
  }

};

#endif // SIMULATEDANEALLING