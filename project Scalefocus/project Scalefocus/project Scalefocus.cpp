// project Scalefocus.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

void Digits(int n, int digs[4])
{
    int br = 3;
    while (n != 0)
    {
        digs[br] = n % 10;
        n = n / 10;
        br--;
    }
}
int ReadNumber()
{
    int n;
    cout << "Enter number:";
    cin >> n;
    while (n < 1000 or n>9999)
    {
        cout << "The number has to be 4-digit!\n";
        cout << "Enter number:";
        cin >> n;
    }
    return n;
}

int EnterNumber(bool diff)
{
    int n;
    bool correct = true;

    do {
        n = ReadNumber();
        correct = true;
        int digs[4];
        Digits(n, digs);

        for (int i = 0; i < 4; i++)
            if (digs[i] < 0 or digs[i]>7) {
                correct = false;
                cout << "The digits have to be between 0 and 7!\n";
                break;
            }
        if (diff == true) {

            for (int i = 0; i < 3; i++)
            {
                for (int j = i + 1; j < 4; j++)
                    if (digs[i] == digs[j]) {
                        correct = false;

                        cout << "The digits have to be different\n";
                        break;
                    }
                if (correct == false) break;
            }
        }
    } while (correct == false);

    return n;
}
void CheckGuess(int Coords, int Guess)
{
    int CoordsDigs[4], GuessDigs[4];
    Digits(Coords, CoordsDigs);
    Digits(Guess, GuessDigs);
    int Greens=0, Reds = 0;

    for (int i = 0; i < 4; i++)
        if (CoordsDigs[i] == GuessDigs[i]) Greens++;

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (CoordsDigs[i] == GuessDigs[j] and i != j) Reds++;
    cout << "Red=" << Reds << "\nGreen=" << Greens;
}

int main()
{
    int a = EnterNumber(true);
    cout << a;
    int b = EnterNumber(true);
    CheckGuess(a, b);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
