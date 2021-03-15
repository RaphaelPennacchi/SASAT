#include "lib/lib.hpp"
#include <ctime>
#include <sys/time.h>

double wtime() {
  struct timeval t;
  gettimeofday(&t, NULL);
  return t.tv_sec + (double) t.tv_usec / 1000000;
}

int main(int argc, char const* argv[]) {
  FileOperator file;
  file.listOptions();
  vector<Clausule> data = file.read(file.options[atoi(argv[2])]);
  Solution solution(file.nClause);
  solution.generate();
  double initialTime, finalTime;

  SimulatedAnealling sa;
  RandomSearch rs;
  pair <vector<bool>, int> saResponse, rsResponse;
  cout << "***** Argumentos entrado ***** " << endl;
  cout << "Função temperatura: " << atoi(argv[1]) << endl;
  cout << "Arquivo: " << file.options[atoi(argv[2])] << endl;
  cout << "******************************" << endl;
  initialTime = wtime();
  saResponse = sa.run(solution, data, 250000, 3.0, 0.0000000001, atoi(argv[1]));
  finalTime = wtime();
  for (auto&& v : saResponse.first) {
    cout << v;
  }
  cout << "\t" << saResponse.second << endl << "Time: " << finalTime - initialTime << endl;
  initialTime = wtime();
  rsResponse = rs.run(solution, data, 250000);
  finalTime = wtime();
  for (auto&& v : rsResponse.first) {
    cout << v;
  }
  cout << "\t" << rsResponse.second << endl << "Time: " << finalTime - initialTime << endl;


  return 0;
}
