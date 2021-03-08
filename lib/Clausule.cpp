#include "Solution.cpp"

#if !defined(CLAUSULE)
#define CLAUSULE

struct Clausule {
  int s1, s2, s3;

  Clausule(int rcvS1, int rcvS2, int rcvS3) {
    s1 = rcvS1;
    s2 = rcvS2;
    s3 = rcvS3;
  };
  bool isTrue(Solution solution) {
    return
      (s1 > 0 ? (solution.solution[s1 - 1]) : (not solution.solution[-(s1 + 1)]))
      or (s2 > 0 ? (solution.solution[s2 - 1]) : (not solution.solution[-(s2 + 1)]))
      or (s3 > 0 ? (solution.solution[s3 - 1]) : (not solution.solution[-(s3 + 1)]));
  };

  void print() {
      cout << s1 << " " << s2 << " " << s3 << endl;
  }
};
#endif
