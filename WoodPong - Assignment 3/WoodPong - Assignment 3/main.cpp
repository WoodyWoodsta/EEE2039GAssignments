//==== The main dude! ====

//== Includes
#include "stdafx.h"

//== Definitions
using namespace std;

//== Variables

//== Implicits

void main(int argc, char* argv[]) {
  cout << "This is my first ADT without the overload.  The Mag should be 38.275 and the Arg should be 56.725!";
  cout << endl;
  cmplx myComplexNumberA;
  myComplexNumberA.re(21);
  myComplexNumberA.im(32);
  myComplexNumberA.printCmplx();
  cout << endl;
  myComplexNumberA.printRe();
  cout << endl;
  myComplexNumberA.printIm();
  cout << endl;
  myComplexNumberA.printMag();
  cout << endl;
  cout << "Please specify ARG form: [RAD/DEG] ";
  char argChoice[3];
  cin >> argChoice;
  cout << endl;
  myComplexNumberA.printArg(argChoice);
  cout << endl;

  cout << "This is my second ADT with the overloaded parametrised constructor.  The Mag should be 223.607 and thhe Arg should be 63.435!";
  cout << endl;
  cmplx myComplexNumberB(100, 200);
  myComplexNumberB.printCmplx();
  cout << endl;
  myComplexNumberB.printRe();
  cout << endl;
  myComplexNumberB.printIm();
  cout << endl;
  myComplexNumberB.printMag();
  cout << endl;
  cout << "Please specify ARG form: [RAD/DEG] ";
  cin >> argChoice;
  cout << endl;
  myComplexNumberB.printArg(argChoice);
  cout << endl;
  system("PAUSE");
}
