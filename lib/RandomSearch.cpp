#include "Solution.cpp"
#include "Clausule.cpp"
#include <utility>

#if !defined(RANDOMSEARCH)
#define RANDOMSEARCH

struct RandomSearch {
  int sucessAmount(Solution solution, vector <Clausule> clausule) {
    int counter = 0;
    for (long unsigned int i = 0; i < clausule.size(); i++) {
      if (clausule[i].isTrue(solution)) counter++;
    }
    return counter;
  }

  pair <vector<bool>, int> run(Solution initialSolution, vector <Clausule> clausule, int maxIterations) {
    Solution fooSolution = initialSolution;
    int fooSolutionAmount = sucessAmount(initialSolution, clausule);
    Solution randomSolution(initialSolution.nVariable);
    int randomSolutionAmount;

    for (int i = 0; i < maxIterations; i++) {
      randomSolution.generate();
      randomSolutionAmount = sucessAmount(randomSolution, clausule);
      if (randomSolutionAmount > fooSolutionAmount) {
        fooSolution = randomSolution;
        fooSolutionAmount = randomSolutionAmount;
      }
    }
    // Return fooSolution, fooSolutionAmount;
    return make_pair(fooSolution.solution, fooSolutionAmount);
  }
};
#endif