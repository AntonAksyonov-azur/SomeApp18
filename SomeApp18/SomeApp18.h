#pragma once

int main();

void ReadDimensions(int& height, int& width);
void ReadArray(int height, int width, int* grid);

bool IsTarget(int value, int target);
int Analyze(int height, int width, int* grid);

int* CopyWithoutRow(int height, int width, int* grid, int removeIndex);
void PrintResult(int height, int width, int* grid);

int* ReadAllFromFile(int& height, int& width);
