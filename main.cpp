#include <iostream>
#include <cstring>

const int maxSteps = 16;

int storedRhythmA[16];
int storedRhythmB[16];
int storedRhythmC[16];

int tempRhythmA[16];
int tempRhythmB[16];
int tempRhythmC[16];

int stepsA, pulsesA, rotateA, curStepA;
int stepsB, pulsesB, rotateB, curStepB;
int stepsC, pulsesC, rotateC, curStepC;

void rotateSeq(int arr[16], int tempArr[16], int steps, int rotate) {
  int val = steps - rotate;
  for (int i = 0; i < steps; i++) {
    arr[i] = tempArr[ abs( (i+val) % steps) ];
  }
}

int bin2dec(int arr[16]) {
  int output = 0;
  int power = 1;

  for (int i = 0; i < 16; i++)
  {
    output += arr[(16 - 1) - i] * power;
    power *= 2;
  }
  return output;
}

int euclid(int arr[maxSteps], int tempArr[maxSteps], int steps, int pulses, int rotate) {
  //rotate += 1;
  //rotate % steps;
  memset(arr, 0, maxSteps);
  memset(tempArr, 0, maxSteps);
  int bucket = 0;

  for (int i = 0; i < steps; i++) {
    bucket += pulses;
    if (bucket >= steps) {
      bucket -= steps;
      arr[i] = 1;
      tempArr[i] = 1;
    } else {
      arr[i] = 0;
      tempArr[i] = 0;
    }
  }
  if (rotate > 0) rotateSeq(arr, tempArr, steps, rotate);
  int x = bin2dec(arr);
  std::cout << x << std::endl;
  return x;
}

void setup() {
  stepsA = 16;
  pulsesA = 4;
  rotateA = 0;
  curStepA = 0;

  stepsB = 16;
  pulsesB = 2;
  rotateB = 0;
  curStepB = 0;

  stepsC = 16;
  pulsesC = 8;
  rotateC = 0;
  curStepC = 0;

  // set all rhythm arrays to zero
  memset(storedRhythmA, 0, maxSteps);
  memset(storedRhythmB, 0, maxSteps);
  memset(storedRhythmC, 0, maxSteps);
}

int main() {
  setup();
  //for (int i = 1; i <= 16; i++) {
    euclid(storedRhythmA, tempRhythmA, stepsA, pulsesA, rotateA);
    euclid(storedRhythmB, tempRhythmB, stepsB, pulsesB, rotateB);
    euclid(storedRhythmC, tempRhythmC, stepsC, pulsesC, rotateC);
  //}
  return 0;
}
