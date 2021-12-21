#include <iostream>
#include <fstream>

#include "SomeApp18.h"

using namespace std;

const int Target = 18;
const int RequiredTargets = 3;

int main()
{
    int width = 0;
    int height = 0;

    ReadDimensions(height, width);

    int* grid = new int[height * width];

    ReadArray(height, width, grid);

    //int* grid = ReadAllFromFile(height, width);

    int removeIndex = Analyze(height, width, grid);
    int* newGrid = CopyWithoutRow(height, width, grid, removeIndex);

    PrintResult(height - 1, width, newGrid);
}

void ReadDimensions(int& height, int& width)
{
    cin >> height >> width;
}

void ReadArray(int height, int width, int* grid)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            cin >> grid[i * width + j];
        }

        cout << endl;
    }
}

// Для теста
int* ReadAllFromFile(int& height, int& width)
{
    ifstream infile("D:\\Progz\\SomeApp18\\Debug\\file2.txt");

    infile >> height;
    infile >> width;

    int* grid = new int[width * height];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            infile >> grid[i * width + j];
        }
    }

    return grid;
}

int Analyze(int height, int width, int* grid)
{
    int* targetCount = new int[height];

    for (int i = 0; i < height; i++)
    {
        targetCount[i] = 0;

        for (int j = 0; j < width; j++)
        {
            int digit = grid[i * width + j];
            if (IsTarget(digit, Target))
            {
                targetCount[i] += 1;
            }
        }
    }

    for (int i = 0; i < height; i++)
    {
        int countOfTargetsInRow = targetCount[i];
        if (countOfTargetsInRow >= RequiredTargets)
        {
            return i;
        }
    }       

    return -1;
}

bool IsTarget(int value, int target)
{
    int sum = 0;

    while (value > 0)
    {
        int digit = value % 10;
        sum += digit;

        value = value / 10;
    }

    return sum <= target;
}


int* CopyWithoutRow(int height, int width, int* grid, int removeIndex)
{
    int* result = new int[(height - 1) * width];
    int iterator = 0;

    for (int i = 0; i < height; i++)
    {
        if (i == removeIndex)
        {
            continue;
        }

        for (int j = 0; j < width; j++)
        {
            result[iterator] = grid[i * width + j];
            iterator += 1;
        }
    }

    return result;
}

void PrintResult(int height, int width, int* grid)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            cout << grid[i * width + j] << " ";
        }

        cout << endl;
    }
}