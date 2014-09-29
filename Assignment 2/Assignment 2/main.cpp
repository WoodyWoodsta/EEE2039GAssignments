//==== The main dude! ====
// The filename is data

//== Includes
#include "stdafx.h"

//== Defines
#define WINDOW_X 1000
#define WINDOW_Y 600
#define PI 3.14159265358979323846

using namespace std;

//== Variables
fstream inFile; // Creating an instance of fstream
string lineBuffer; // Use this to buffer a line for use
string opTypeStr; // Use this to store the current op type
string dataBuffer; // Use this to buffer a portion of data for use
float numData[20]; // Use this to store the current numbers

float average;
float maximum;
float minimum;
float variance;

int checker = 0; // Data segment counter
float numDataSize;

enum opTypeNum { NOTHING, AVERAGE, MINIMUM, MAXIMUM, VARIANCE };

//== Declarations
void greeting(void);
void doFile(string filename);
void fetchLine(void);
void calculate(int type);
void createWindow(int windowX, int windowY);
void createLine(int x1, int y1, int x2, int y2);
float calcAverage(float numElements);
float calcMinimum(float numElements);
float calcMaximum(float numElements);
float calcVariance(float numElements);

int main(int argc, char* argv[]) {
  string fname;
  greeting();
  cout << "Enter the name of the text file: ";
  cin >> fname;
  cout << endl << endl << "Working... please wait!" << endl;
  doFile(fname);
  
  cout << endl << "The average is: " << float(average) << endl;
  cout << "The minimum is: " << float(minimum) << endl;
  cout << "The maximum is: " << float(maximum) << endl;
  cout << "The variance is: " << float(variance) << endl;
  cout << endl << "All done!!! Launching GUI..." << endl;
  cout << "Get ready for some real shit!  ";

  system("PAUSE");

  createWindow(WINDOW_X, WINDOW_Y);

  while (!kbhit());
  return 0;
}

void doFile(string filename) { // Opens the file for use
  inFile.open(filename);
  if (inFile.is_open()) {
    cout << "Opened " << filename << " successfully!" << endl;
    cout << "Processing file... please wait!" << endl;
    while (!inFile.eof()) {
      int opType = NOTHING;
      fetchLine();
      if (opTypeStr == "AVERAGE") { opType = AVERAGE; }
      else if (opTypeStr == "MINIMUM") { opType = MINIMUM; }
      else if (opTypeStr == "MAXIMUM") { opType = MAXIMUM; }
      else if (opTypeStr == "VARIANCE") { opType = VARIANCE; }
      else { cout << "Data read error!" << endl; }
      calculate(opType);
    }
  }
  else {
    cout << "The file could not be opened!" << endl << endl;
    system("PAUSE");
  }
  
  inFile.close(); // Close the file when done

}

void greeting(void) { // Just the DOS greeting
  cout << endl << "Welcome to my version of Operators and Numbers" << endl;
  cout << "Developed by:" << endl;
  cout << "Sean Wood | WDXSEA003" << endl << endl;
}

void fetchLine(void) {
  getline(inFile, lineBuffer);

  int lineLength = lineBuffer.length();
  string c = "";
  int numDataPos = 0;

  opTypeStr = "";
  dataBuffer = "";
  memset(numData, 0, sizeof(numData));

  for (int i = 0; i <= lineLength; i++) {
    c = lineBuffer[i];
    if (c == ":") {
      opTypeStr = dataBuffer;
      dataBuffer = "";
    }
    else if (c == "," || c == "\r") {
      numData[numDataPos] = stof(dataBuffer.c_str());
      numDataPos++;
      dataBuffer = "";
    } 
    else {
      dataBuffer.append(c);
    }
    
    c = "";
  }
  if (dataBuffer != "") {
    numData[numDataPos] = stof(dataBuffer.c_str());
    numDataPos++;
    dataBuffer = "";
  numDataSize = float(numDataPos);
  }
  
}

void calculate(int type) {
  switch (type) {
  case AVERAGE:
    average = calcAverage(numDataSize);
    
    break;
  case MINIMUM:
    minimum = calcMinimum(numDataSize);
    break;
  case MAXIMUM:
    maximum = calcMaximum(numDataSize);
    break;
  case VARIANCE:
    variance = calcVariance(numDataSize);
    break;
  case NOTHING:
    cout << "Internal Error!" << endl;
    break;
  }

}

float calcAverage(float numElements) {
  float result = 0;
  for (int i = 0; i < numElements; i++) {
    result += numData[i];
  }
  result = float(result)/float(numElements);
  return result;
}

float calcMinimum(float numElements) {
  float min = numData[0];
  for (int i = 0; i < numElements; i++) {
    if (numData[i] < min) {
      min = numData[i];
    }
  }
  return min;
}

float calcMaximum(float numElements) {
  float max = numData[0];
  for (int i = 0; i < numElements; i++) {
    if (numData[i] > max) {
      max = numData[i];
    }
  }
  return max;
}

float calcVariance(float numElements) {
  float var = 0;
  float mean = calcAverage(numElements);
  float presum = 0;
  float sum = 0;
  for (int i = 0; i < numElements; i++) {
    presum = numData[i] - mean;
    sum = sum + (presum*presum);
  }
  var = sum / numElements;
  return var;
}

void createWindow(int windowX, int windowY) {
  initwindow(windowX, windowY, "Assignment 2 Cruncher 2000");
  int xPos;
  int yPos;
  int xMax = getmaxx();
  int yMax = getmaxy();
  int center[2] = { xMax / 2, yMax / 2 };

  setlinestyle(0, 0, 3);
  double rotIteration = 0;
  double rotSpeed = 360;
  while (!kbhit()) {
    rotSpeed = 180 - (160 * cos(rotIteration));
    rotIteration = rotIteration + ((2 * PI) / (rotSpeed + (rotIteration*0.5)));
    yPos = 30*cos(rotIteration);
    xPos = 30*sin(rotIteration);
    clearviewport();
    createLine(center[0] + xPos, center[1] - yPos, center[0] - xPos, center[1] + yPos);
    delay(5);
  }
}

void createLine(int x1, int y1, int x2, int y2) {
  moveto(x1, y1);
  lineto(x2, y2);
}