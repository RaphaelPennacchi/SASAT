#include <iostream>
#include "Solution.cpp"
#include "Clausule.cpp"
#include <utility>

#if !defined(SIMULATEDANEALLING)
#define SIMULATEDANEALLING
#define PI 3.14159265

struct SimulatedAnealling {
  //vars
  int sucessAmount(Solution solution, vector <Clausule> clausule) {
    int counter = 0;
    for (long unsigned int i = 0; i < clausule.size(); i++) {
      if (clausule[i].isTrue(solution)) counter++;
    }
    return counter;
  }
  // Pseudocode
  // Let s = s0
  // For k = 0 through kmax (exclusive):
  //     T ← temperature( (k+1)/kmax )
  //     Pick a random neighbour, snew ← neighbour(s)
  //     If P(E(s), E(snew), T) ≥ random(0, 1):
  //         s ← snew
  // Output: the final state s

  double calculateTemperature(int actualIteration, int maxIteration, double initialTemp, double finalTemp) {
    return initialTemp - (double)actualIteration * ((initialTemp - finalTemp) / maxIteration);
  }

  double calculateTemperature1(int actualIteration, int maxIteration, double initialTemp, double finalTemp) {
    return (double)(initialTemp * pow((finalTemp / initialTemp), (actualIteration / maxIteration)));
  }

  double calculateTemperature2(int actualIteration, int maxIteration, double initialTemp, double finalTemp) {
    double a = (double)((initialTemp - finalTemp) * (maxIteration + 1)) / (double)maxIteration;
    double b = (double)initialTemp - a;
    return ((double)a / (double)(actualIteration + 1 )) + (double)b;
  }

  double calculateTemperature3(int actualIteration, int maxIteration, double initialTemp, double finalTemp){
    double a = (double)log(initialTemp - finalTemp) / log(maxIteration);
    return (double)(initialTemp - pow((double)actualIteration, a));
  }

  double calculateTemperature4(int actualIteration, int maxIteration, double initialTemp, double finalTemp){
    return ((initialTemp - finalTemp) / (1 + exp(3 * (1 - (maxIteration/2))))) + finalTemp;
  }

  double calculateTemperature5(int actualIteration, int maxIteration, double initialTemp, double finalTemp){
    return ((double)1 / 2) * (initialTemp - finalTemp) * (1 + cos((actualIteration * M_PI)/ maxIteration)) + finalTemp;
  }

  double calculateTemperature6(int actualIteration, int maxIteration, double initialTemp, double finalTemp){
    return ((double)1 / 2) * (initialTemp - finalTemp) * (1 - tanh(((double)(10*actualIteration)/maxIteration) - 5)) + finalTemp;
  }

  double calculateTemperature7(int actualIteration, int maxIteration, double initialTemp, double finalTemp){
    return ((initialTemp - finalTemp) / cosh((double)(10*actualIteration)/ maxIteration)) + finalTemp;
  }

  double calculateTemperature8(int actualIteration, int maxIteration, double initialTemp, double finalTemp){
    double a = (double)( 1 / maxIteration) * log((double)initialTemp/finalTemp);
    return initialTemp * exp(-a * actualIteration);
  }

  double calculateTemperature9(int actualIteration, int maxIteration, double initialTemp, double finalTemp){
    double a = ((double)1 / pow(maxIteration, 2)) * log((double)initialTemp / finalTemp);
    return initialTemp * exp(-a * pow(actualIteration, 2));
  }

  pair <vector<bool>, int> run(Solution solution, vector <Clausule> clausule, int maxIterations, double initialTemp, double finalTemp) {
    // Set the initial solution
    Solution fooSolution = solution;
    int sucess = 0, fooSucess = 0;
    int temperature = initialTemp;
    int probability, cost;
    for (int i = 0; i < maxIterations; i++) {
      //Modifica a solucao em porcentagem
      fooSolution.modify((solution.nVariable / 20) ? solution.nVariable/20 : 1);
      //Verificar se a solução atual é melhor que a anterior
      fooSucess = sucessAmount(fooSolution, clausule);
      if (fooSucess > sucess) {
        sucess = fooSucess;
        solution = fooSolution;
      }
      else {
        // Função para atualizar a temperatura
        temperature = calculateTemperature(i, maxIterations, initialTemp, finalTemp);
        // If para ver se aceita a nova solução ou não
        probability = (double) rand() / RAND_MAX;
        cost = exp((double)(fooSucess - sucess) / temperature);
        
        if (cost > probability) {
          sucess = fooSucess;
          solution = fooSolution;
        }
      }
    }
    return make_pair(solution.solution, sucess);
  }

};

#endif // SIMULATEDANEALLING