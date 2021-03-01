#include "lib/lib.hpp"


int main(int argc, char const *argv[])
{
  FileOperator file;
  file.listFiles();
  file.readFile(file.fileName[0]);
  file.printData();
  OperadorSolucao solution(file.nClause);
  solution.gerar();
  solution.printSolution();

  return 0;
}
