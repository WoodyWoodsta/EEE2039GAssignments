#pragma once
#include <string>

#define PI 3.14159265358979323846

class cmplx
{
public:       // Public access
  enum argType {DEG, RAD};
  cmplx();
  ~cmplx();
  cmplx(double reNumber, double imNumeber);      // Defualt constrcutor
  void re(double number);
  void im(double number);
  void printCmplx();
  void printRe();
  void printIm();
  void printMag();
  void printArg(char argTypeInArr[3]);

private:        // Private access
  double reVal;
  double imVal;
};

