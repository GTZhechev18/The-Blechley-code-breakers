#include <iostream>
#include <vector>
#include <conio.h>
#include <time.h>

using namespace std;

vector<int> history;

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
int GenerateNumber()
{
    srand(time(NULL));
    int n;
    bool correct = true;
    do {
        n = rand() % 9000 + 1000;
        correct = true;
        int digs[4];
        Digits(n, digs);

        for (int i = 0; i < 4; i++)
            if (digs[i] < 0 or digs[i]>7) {
                correct = false;
                // cout << "The digits have to be between 0 and 7!\n";
                break;
            }
        for (int i = 0; i < 3; i++)
        {
            for (int j = i + 1; j < 4; j++)
                if (digs[i] == digs[j]) {
                    correct = false;
                    break;
                }
            if (correct == false) break;
        }
    } while (correct == false);
    return n;
}
int ReadNumber()
{
    int n;

    cin >> n;

    while (n < 1000 or n>9999 or cin.fail())
    {
        cout << "The number has to be 4-digit!\n";
        cin.clear();
        cin.sync();
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

                        cout << "The digits have to be different!\n";
                        break;
                    }
                if (correct == false) break;
            }
        }
    } while (correct == false);

    return n;
}
void CheckGuess(int Coords, int Guess, int &Reds, int&Greens)
{
    int CoordsDigs[4], GuessDigs[4];
    Digits(Coords, CoordsDigs);
    Digits(Guess, GuessDigs);
    Greens = 0;
    Reds = 0;

    for (int i = 0; i < 4; i++)
        if (CoordsDigs[i] == GuessDigs[i]) Greens++;

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            if (CoordsDigs[i] == GuessDigs[j] and i != j) Reds++;
  //  call GuessResult(Reds,Greens) ;
  //  cout << "Red=" << Reds << "\nGreen=" << Greens;
}
void ShowHistory(int Coords)
{
    for (unsigned int i = 0; i < history.size(); i++)
    {
        int R, G;
        CheckGuess(Coords, history[i], R, G);
        cout << "Guess " << i + 1 <<" : "<<history[i]<< " Reds=" << R << " Greens=" << G << endl;
    }

}
void Level1()
{
    int number1;
    cout << "Player 1, enter your combination! ";
    number1 = EnterNumber(true);

    int GuessNum = 0;
    bool Guessed = false;
    int Reds, Greens;
    while (GuessNum < 13 and Guessed == false)
    {
        system("CLS");
        GuessNum++;
        int number2;
        cout << "Guess number "<< GuessNum <<"!\nPlayer 2 enter your guess! ";
        number2 = EnterNumber(true);
        history.push_back(number2);
        CheckGuess(number1, number2, Reds, Greens);
        ShowHistory(number1);
      //  cout << "Red=" << Reds << "\nGreen=" << Greens<<endl;
      //  GuessResult(Reds, Greens);
        if (Greens < 4) {
            cout << "Ready for the next guess? Press any key to continue! ";
            _getch();
        }
        if (Greens == 4) {
                         cout << "Congratulations! You have broken the code!";
                         Guessed = true;
                        }
    }
    if (Guessed == false) cout << "Sorry! You failed trying to break the code! The code is " << number1 << endl;
}
void Level2()
{
    int number1 = GenerateNumber();
    int GuessNum = 0;
    bool Guessed = false;
    int Reds, Greens;
    while (GuessNum < 13 and Guessed == false)
    {
            system("CLS");
            GuessNum++;
            int number2;
            cout << "Guess number " << GuessNum << "!\nPlayer, enter your guess:";
            number2 = EnterNumber(true);
            history.push_back(number2);
            CheckGuess(number1, number2, Reds, Greens);
            ShowHistory(number1);
            //  cout << "Red=" << Reds << "\nGreen=" << Greens<<endl;
            //  GuessResult(Reds, Greens);
            if (Greens < 4) {
                cout << "Ready for the next guess? Press any key to continue! ";
                _getch();
            }
            if (Greens == 4) {
                cout << "Congratulations! You have broken the code!";
                Guessed = true;
            }
        }
        if (Guessed == false) cout << "Sorry! You failed trying to break the code!" << number1 << endl;

}
void MainMenu()
{
    cout << "Welcome to Bletchley"<<endl;
    cout << "Please select level of difficulty\n";
    cout << "1 for Player vs Player \n2 for Player vs Computer\n";
    int level;
    cin >> level;

    while (level != 1 and level != 2 || cin.fail())
    {
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "Invalid input! You haven't entered a number or the number isn't 1 or 2\n";
        cout << "Please select either Player vs Player(1) or Player vs Computer(2):";
        cin >> level;
    }
    if (level == 1) Level1();
      else Level2();
}
int main()
{
  //  cout << GenerateNumber();
    MainMenu();
   /* int a = EnterNumber(true);
    cout << a;
    int b = EnterNumber(true);
    CheckGuess(a, b);*/
}
