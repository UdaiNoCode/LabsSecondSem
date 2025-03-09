#ifndef ACCERMAN_H
#define ACCERMAN_H

class Accerman {
 public:
  Accerman();

 private:
  int firstArgument{0};
  int secondArgument{0};

 public:
  void setFirstArg(int first);
  void setSecondArg(int second);
  int getFirstArg();
  int getSecondArg();

  int accermanFunction(int first, int second);
};

#endif  // ACCERMAN_H
