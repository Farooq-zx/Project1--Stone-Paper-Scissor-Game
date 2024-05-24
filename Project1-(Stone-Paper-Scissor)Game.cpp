#include <iostream>
#include <cstdlib>
using namespace std;

enum enOptions
{
    Stone = 1, Paper = 2, Scissor = 3
};

short RandomNumbersfrom1to3(short From, short To) {

    short randNum = rand() % (To - From + 1) + From;

    return randNum;
}

enOptions TheChoice(short Number) {
    
    switch (Number)
    {
    case 1: return enOptions::Paper;
    case 2: return enOptions::Scissor;
    case 3: return enOptions::Stone;
    }

}
//string TheChoice(short Number) {
//    
//    switch (Number)
//    {
//    case 1: return "Paper";
//    case 2: return "Scissor";
//    case 3: return "Stone";
//    }
//
//}

string WhoWin(enOptions UserChoose, enOptions CPUChoose) {


    if (UserChoose == enOptions::Stone){

        switch (CPUChoose)
        {
        case Scissor:
            return "User win";
        case Paper:
            return "CPU win";
        default:
            return "No winner";
        }
    }
    else if (UserChoose == enOptions::Paper) {

        switch (CPUChoose)
        {
        case Stone:
            return "User win";
        case Scissor:
            return "CPU win";
        default:
            return "No winner";
        }

    }
    else if (UserChoose == enOptions::Scissor) {

        switch (CPUChoose)
        {
        case Paper:
            return "User win";
        case Stone:
            return "CPU win";
        default:
            return "No winner";
        }

    }

}

short HowManyRounds() {
    short NumofRounds;
    
    cout << "How many rounds 1 to 10 : ";
    cin >> NumofRounds;

    return NumofRounds;
}

void PrintFirstScreen(short i) {
    cout << "\n";
    cout << "\nRound [" << i << "] begins: \n";
    cout << "\nYour choice: [1]:Stone, [2]:Paper, [3]:Scissor ? ";

}

void RoundResult(short UserNum, short CPUNum, short i) {
    cout << "\n----------------Round [" << i << "] ----------------\n";
    cout << "\nPlayer 1 Choice: " << TheChoice(UserNum);
    cout << "\nCumputer Choice: " << TheChoice(CPUNum);
    cout << "\nRound Winner   : " << WhoWin(TheChoice(UserNum), TheChoice(CPUNum));
    cout << "\n-----------------------------------------------------\n";
}

void TheGame(){

    short NumofRounds = HowManyRounds();

    for (short i = 1; i <= NumofRounds; i++)
    {

        short CPUNum = RandomNumbersfrom1to3(1, 3);
        short UserNum;

        PrintFirstScreen(i);
        cin >> UserNum;


        RoundResult(UserNum, CPUNum, i);



    }


}

int main()
{
    // to generate random numbers
    srand((unsigned)time(NULL));


    TheGame();








    return 0;
}