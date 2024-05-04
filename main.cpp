#include <iostream>
#include <string>
#include <unistd.h>
using namespace std;

float amount, bet, s_amount=0;
int number;

void start(){
    string name;
    cout<<"===Guessing Casino===\n";
    cout<<"Enter your name: ";
    cin>>name;
    cout<<"\nWelcome to the casino "<<name;
    cout<<"\nEnter how much money do you want to play with: $";
    cin>>amount;
    while(cin.fail()){
        cin.clear();
        cin.ignore(256,'\n');
        cout<<"\nYour input has to be a number.\nPlease try again: ";
        cin>>amount;
    }
    s_amount += amount;
}

float bet_am(){
    cout<<"\nYour account balance: $"<<amount;
    cout<<"\nWrite the amount you want to bet: $";
    cin>>bet;
    while(cin.fail()){
        cin.clear();
        cin.ignore(256,'\n');
        cout<<"\nYour bet has to be a number.\nPlease try again: ";
        cin>>bet;
    }
    while(bet>amount){
        cout<<"\nNot enough money on your account!";
        cout<<"\nYour current balance: $"<<amount;
        cout<<"\nPlease enter your bet again: $";
        cin>>bet;
    }
    cout<<"\nYour new balance: $"<<amount<<" - $"<<bet<<" = $";
    amount = amount-bet;
    cout<<amount;
    return bet;
}

int guess(){
    const int num_list[6]={1,2,3,4,5,6};
    cout<<"\nNow guess the number from 1 to 6: ";
    cin>>number;
    while(cin.fail()){
        cin.clear();
        cin.ignore(256, '\n');
        cout<<"\nYour input has to be a number.\nTry again: ";
        cin>>number;
    }
    while(number!=num_list[number-1]){
        cout<<"\nNumber has to be in range from 1 to 6 and it has to be int type.\nPlease pick a number again: ";
        cin>>number;
    }

    return number;
}

void game(){
    int roll = (rand()%6) +1;
    cout<<"\nThe number on the dice is...";
    usleep(3);
    cout<<roll;
    if(roll==number) {
        cout << "\nCongratulations you picked a correct number!";
        cout << "\nYour new balance is: $" << amount << " + $" << bet << " * 10 = $";
        amount = amount + (bet * 10);
        cout << amount;
    }else{
        cout<<"\nOuch...You have lost. Better luck next time!\nYour balance is: $"<<amount;
    }

    if(amount==0){
        cout<<"\nYour account balance is $0. That means it's end of the game.";
        cout<<"\nIf you want to play again, you will have to recharge your account.";
    }

    char newgame;
    cout<<"\nDo you want to play again? (Y/N)";
    cin >> newgame;
    newgame = toupper(newgame);

    while((newgame!='Y')&&(newgame!='N')){
        cout<<"\nWrong input. You have to type Y or N.";
        cout<<"\nPlease type again: ";
        cin>>newgame;
        newgame = toupper(newgame);
    }

    if(newgame=='Y'){
        if(amount==0) {
            cout << "\nCharge your account: $";
            cin >> amount;
        }
        system("cls");
        bet_am();
        guess();
        game();
    }else{
        system("cls");
        if(s_amount<amount) {
            cout<<"\nCongratulations you have ended the game with $"<<amount;
            cout<<" which is $"<<amount-s_amount<<" more than what you stared with!";
        }else if(s_amount==amount){
            cout<<"\nCongratulations you have ended the game with $"<<amount;
            cout<<".\nThat's nothing lost but nothing won either.";
            cout<<"\nBetter luck nex time!";
        }else{
            cout<<"\nUnfortunately you have lost some money...";
            cout<<"\nBetter luck next time!";
        }
        exit(0);
    }
}

int main() {
        srand(time(0));
        start();
        bet_am();
        guess();
        game();

    return 0;
}