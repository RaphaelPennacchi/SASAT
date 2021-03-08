#include "lib/lib.hpp"

int main(int argc, char const* argv[]) {
  FileOperator file;
  file.listOptions();
  vector<Clausule> data = file.read(file.options[1]);
  Solution solution(file.nClause);
  solution.generate();

  SimulatedAnealling sa;
  RandomSearch rs;
  pair <vector<bool>, int> saResponse, rsResponse;
  saResponse = sa.run(solution, data, 250000, 3.0, 0.01);
  rsResponse = rs.run(solution, data, 250000);
  for(auto&& v: saResponse.first){
    cout << v;
  }
  cout << "\t" <<  saResponse.second << endl;
  for(auto&& v: rsResponse.first){
    cout << v;
  }
  cout << "\t" << rsResponse.second << endl;


  return 0;
}
