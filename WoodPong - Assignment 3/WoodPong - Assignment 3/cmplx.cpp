#include "cmplx.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <math.h>

using namespace std;

cmplx::cmplx()        // Defualt contructor
{
  reVal = 0;
  imVal = 0;
}

cmplx::cmplx(double reNumber, double imNumber)        // Defualt contructor
{
  reVal = reNumber;
  imVal = imNumber;
}


cmplx::~cmplx()
{
}

void cmplx::re(double number) {
  reVal = number;
}

void cmplx::im(double number) {
  imVal = number;
}

void cmplx::printCmplx() {
  cout << "(" << reVal << "," << imVal << "i)";
}

void cmplx::printRe() {
  cout << reVal;
}

void cmplx::printIm() {
  cout << imVal;
}

void cmplx::printMag() {
  double mag = 0;
  mag = sqrt((reVal*reVal) + (imVal*imVal));
  cout << mag;
}

void cmplx::printArg(char argTypeInArr[3]) {
  int argTypeVal;
  string argTypeIn = "";
  string c;
  for (int i = 0; i < sizeof(argTypeInArr); i++) {
    c = argTypeInArr[i];
    argTypeIn.append(c);
  }
  if (argTypeIn == "DEG") {
    argTypeVal = DEG;
  }
  else if (argTypeIn == "RAD") {
    argTypeVal = RAD;
  }
  else { 
    cout << "Not a valid selection! Using RAD (default)";
  }
  double arg = 0;
  arg = atan2(imVal, reVal);
  switch (argTypeVal) {
  case DEG:
    arg = (arg / (2 * PI)) * 360;
    break;
  case RAD:
    break;
  }
  cout << arg << "°";
}