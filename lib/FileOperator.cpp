#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include "Clausule.cpp"

using namespace std;

#if !defined(FILEOPERATOR)
#define FILEOPERATOR

struct FileOperator {
  vector<string> options = {"uf20-01.cnf", "uf100-01.cnf", "uf250-01.cnf"};
  ifstream myFile;
  string holder;
  int clausule, counter, nClause, nStatement;

  void listOptions(void) {
    for (int i = 0; i < 3; i++) {
      cout << options[i] << endl;
    }
  };


  // vector<Clausule> 

  vector<Clausule> read(string fileName) {
    vector<Clausule> data;
    int values[3], discard;

    myFile.open(fileName);
    if (!myFile.is_open())
      exit(1);

    while (!myFile.eof()) {
      myFile >> holder;
      if (holder == "c") {
        getline(myFile, holder);
      }
      else if (holder == "p") {
        myFile >> holder >> nClause >> nStatement;
        break;
      }
    }
    for (int j = 0; j < nStatement; j++) {
      myFile >> values[0] >> values[1] >> values[2] >> discard;
      Clausule clausules(values[0], values[1], values[2]);
      data.push_back(clausules);
      // clausules.print();
    }
    myFile.close();
    return data;
  };
};

#endif // FILEOPERATOR