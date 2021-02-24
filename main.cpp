#include "lib/lib.hpp"


int main(int argc, char const *argv[])
{
  FileOperator file;
  file.listFiles();
  file.readFile(file.fileName[2]);
  file.printData();
  return 0;
}
