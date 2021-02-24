#include <vector>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

typedef struct fileOperator
{
  vector<vector<int>> data;
  vector<string> fileName = {"uf20-01.cnf", "uf100-01.cnf", "uf250-01.cnf"};
  ifstream myFile;
  string holder;
  int clausule, counter;
  int nClause, nStatement;

  void listFiles(void)
  {
    for (int i = 0; i < 3; i++)
    {
      cout << fileName[i] << endl;
    }
  };

  void readFile(string fileName)
  {
    resetData();
    myFile.open(fileName);
    if (!myFile.is_open())
      exit(1);

    while (!myFile.eof())
    {
      myFile >> holder;
      if (holder == "c")
      {
        getline(myFile, holder);
      }
      else if (holder == "p")
      {
        myFile >> holder >> nClause >> nStatement;
        for (int i = 0; i < nStatement; i++)
        {
          data.push_back(vector<int>(nClause, 0));
        }
        break;
      }
    }
    counter = 0;
    while (!myFile.eof())
    {
      if (counter == nStatement)
        break;
      myFile >> clausule;

      if (clausule > 0)
      {
        data[counter][clausule - 1]++;
      }
      else if (clausule < 0)
      {
        data[counter][(clausule * - 1) - 1]--;
      }
      else{
        counter++;
      }
    }

    myFile.close();
  };

  void resetData(void)
  {
    if (!data.empty())
    {
      data.clear();
    }
  };

  void printData(void){
    for (auto & array: data){
      for (auto & element: array){
        cout << element;
      }
      cout << endl;
    }
  }

} FileOperator;
