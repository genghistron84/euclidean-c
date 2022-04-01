#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <stdio.h>
#include <bitset>

const int MAX_STEPS = 16;

int storedRhythmA[MAX_STEPS];
int storedRhythmB[MAX_STEPS];
int storedRhythmC[MAX_STEPS];

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

void printArr(int arr[16]) {
  for (int i = 0; i <  MAX_STEPS; i++)
    std::cout << arr[i];
  std::cout << std::endl;
}

void euclid(int arr[MAX_STEPS], int tempArr[MAX_STEPS], int steps, int pulses, int rotate) {
  memset(arr, 0, MAX_STEPS);
  memset(tempArr, 0, MAX_STEPS);
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
}

void setup() {
  stepsA = 16;
  pulsesA = 3;
  rotateA = 1;
  curStepA = 0;

  stepsB = 16;
  pulsesB = 8;
  rotateB = 1;
  curStepB = 0;

  stepsC = 16;
  pulsesC = 12;
  rotateC = 1;
  curStepC = 0;

  // set all rhythm arrays to zero
  memset(&storedRhythmA, 0, MAX_STEPS);
  memset(storedRhythmB, 0, MAX_STEPS);
  memset(storedRhythmC, 0, MAX_STEPS);
  euclid(storedRhythmA, tempRhythmA, stepsA, pulsesA, rotateA);
  euclid(storedRhythmB, tempRhythmB, stepsB, pulsesB, rotateB);
  euclid(storedRhythmC, tempRhythmC, stepsC, pulsesC, rotateC);
  printArr(storedRhythmA);
  printArr(storedRhythmB);
  printArr(storedRhythmC);
}

void simulatePulse(int *step) {
  step++;
  std::cout << step << std::endl;
}

void tick() {
  simulatePulse(&curStepA);
}

int main() {
  setup();

  for(int i = 0; i < 8; i++) {
    tick();
    //std::cout << curStepA << std::endl;
  }
  return 0;
}

