#include <iostream>
using namespace std;

void generateSquare(int n) {
int magicSquare[n][n];
for (int i = 0; i < n; i++)
{
for (int j = 0; j < n; j++)
magicSquare[i][j] = 0;
}
int row = n/2;
int column = n-1;
for (int num=1; num <= n*n; )
{
if (row==-1 && column==n) //in in top right corner
{
column = n-2;
row = 0;
}
else
{
if (column == n) // if column goes out of bounds
column = 0;
if (row < 0) //if row goes out of bounds
row=n-1;
}
if (magicSquare[row][column]) //if a number already exists in the spot
{
column -= 2;
row++;
continue;
}
else
magicSquare[row][column] = num++; //add in number to magic square

column++; row--; // adds one to column, subtracts one from row
}

for (int i = 1; i < 5; i++) //prints the magic square
{
cout << "Magic Square #" << i << " is: " << "\n";
for (int y = 0; y < n; y++)
{
for (int z = 0; z < n; z++)
cout << magicSquare[y][z] << " ";
cout << "\n";
}
cout << "\n";
cout << "Checking the sums of every row: ";
int rowTotal = 0;
for (int d = 0; d < n; d++)
{
for (int e = 0; e < n; e++)
{
rowTotal += magicSquare[d][e];
}
cout << rowTotal << " ";
rowTotal = 0;
}
cout << "\n";
cout << "Checking the sums of every column: ";
int colTotal = 0;
for (int f = 0; f < n; f++)
{
for (int g = 0; g < n; g++)
{
colTotal += magicSquare[g][f];
}
cout << colTotal << " ";
colTotal = 0;
}
cout << "\n";
cout << "Checking the sums of every diagonal: ";
int diagTotal = 0;
for (int a = 0, b = 0; a < n && b < n; a++, b++)
diagTotal += magicSquare[a][b];
cout << diagTotal << " ";
diagTotal = 0;
for (int c = n-1, d = n-1; c >= 0 && d >= 0; c--, d--)
diagTotal += magicSquare[c][d];
cout << diagTotal << "\n";
cout << "\n";

if (i == 1 || i == 3)
{
for (int z = 0; z < n; z++)
{
int holder = magicSquare[z][0];
magicSquare[z][0] = magicSquare[z][n-1];
magicSquare[z][n-1] = holder;
}
}

if (i == 2)
{
for (int k = 0; k < n; k++)
{
int holder = magicSquare[0][k];
magicSquare[0][k] = magicSquare[n-1][k];
magicSquare[n-1][k] = holder;
}
}

if (i == 4)
{
int newMagicSquare [n][n];
for (int i = 0; i < n; i++)
{
for (int j = 0; j < n; j++)
newMagicSquare[i][j] = 0;
}

for (int m = 0; m < n; m++)
{
int counter = n-1;
for (int s = 0; s < n; s++)
{
newMagicSquare[m][s] = magicSquare[counter][m];
counter--;
}
}
cout << "Magic Square #" << i+1 << " is: " << "\n";
for (int y = 0; y < n; y++)
{
for (int z = 0; z < n; z++)
cout << newMagicSquare[y][z] << " ";
cout << "\n";
}

cout << "\n";
cout << "Checking the sums of every row: ";
int rowTotal = 0;
for (int d = 0; d < n; d++)
{
for (int e = 0; e < n; e++)
{
rowTotal += newMagicSquare[d][e];
}
cout << rowTotal << " ";
rowTotal = 0;
}
cout << "\n";
cout << "Checking the sums of every column: ";
int colTotal = 0;
for (int f = 0; f < n; f++)
{
for (int g = 0; g < n; g++)
{
colTotal += newMagicSquare[g][f];
}
cout << colTotal << " ";
colTotal = 0;
}
cout << "\n";
cout << "Checking the sums of every diagonal: ";
int diagTotal = 0;
for (int a = 0, b = 0; a < n && b < n; a++, b++)
diagTotal += newMagicSquare[a][b];
cout << diagTotal << " ";
diagTotal = 0;
for (int c = n-1, d = n-1; c >= 0 && d >= 0; c--, d--)
diagTotal += magicSquare[c][d];
cout << diagTotal << "\n";
cout << "\n";
}

}
}

int main() {
int size = 0;
cout << "Enter the size of the magic square: " << endl;
cin >> size;
generateSquare(size);
}