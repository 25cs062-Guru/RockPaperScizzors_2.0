#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <algorithm>

using namespace std;

int Phealth = 100;
int Chealth = 100;
int Phealcount = 0;
int Chealcount = 0;

string rockRouletteGuess(){
     int RPS = rand() % 3 + 1;
     if(RPS == 1){
        return "ROCK";
     } else if(RPS == 2){
        return "PAPER";
     } else {
        return "SCISSORS";
     }
}

bool rockpaperGame(string guess, string RPS){
    bool win = false;
    bool tied = false;

    if(guess == "ROCK" && RPS == "SCISSORS"){
        cout<<"You won! \n\nRock beats Scissors.\n\n";
        win = true;
    } 
    else if(guess == "PAPER" && RPS == "ROCK"){
        cout<<"You won! \n\nPaper beats Rock.\n\n";
        win = true;
    } 
    else if(guess == "SCISSORS" && RPS == "PAPER"){
        cout<<"You won! \n\nScissors beats Paper.\n\n";
        win = true;
    } 
    else if(guess == RPS){
        tied = true;
    } 
    else {
        cout<<"---- You lost! ---- \n\nComputer wins.\n\n";
    }

    if (tied){
        cout<<"\n---- It's a tie! AGAIN! ----\n\n";
        return true;
    }

    if (win){
        if(Phealth <= 50 && Phealcount < 2){
            cout<<"Heal or Shoot? (heal/shoot): ";
            cin.ignore();
            string choice;
            getline(cin, choice);

            transform(choice.begin(), choice.end(), choice.begin(), ::toupper);

            if(choice == "HEAL"){
                Phealth += 25;
                Phealcount++;
                cout<<"You healed  = +25 HP\n";
            } else {
                Chealth -= 25;
                cout<<"You shot computer!\n";
            }
        } else {
            Chealth -= 25;
            cout<<"You shot computer!\n";
        }
    }
  
    else {
        if(Chealth <= 50 && Chealcount < 2 && rand()%2==0){
            Chealth += 25;
            Chealcount++;
            cout<<"Computer healed  = +25 HP\n";
        } else {
            Phealth -= 25;
            cout<<"Computer shot you!\n";
        }
    }

    cout<<"Your Health: "<<Phealth<<endl;
    cout<<"Computer Health: "<<Chealth<<endl;

    return false;
}

int main(){

    srand(time(0));

    char again;
    cout<<"Welcome to Rock, Paper, Scissors 2.0 \n\n";
    cout<<"Press 1 to see the rules, or any other key to start the game: ";
    char choice;
    cin>>choice;
    if(choice == '1'){
        cout<<"\n---- The Rules of the Cursed Game ----\n\n";
        cout<<"1. Both the Players start with 100 health points.\n";
        cout<<"2. Each round, Choose Rock, Paper, or Scissors to Survive.\n";
        cout<<"4. The winner of the round will shoot the opponent once.\n";
        cout<<"5. Players can Gamble a Heal(25HP) if their health drops to 50 or below (up to 2 times per game).\n\n";
        cout<<" ---- Eliminate the other to Survive! ----\n\n";
    }

    do{

        Phealth = 100;
        Chealth = 100;
        Phealcount = 0;
        Chealcount = 0;

        while(Phealth > 0 && Chealth > 0){

            string guess;
            cout<<"\nEnter (Rock, Paper, Scissors): ";
            cin>>guess;

            transform(guess.begin(), guess.end(), guess.begin(), ::toupper);

            if(guess != "ROCK" && guess != "PAPER" && guess != "SCISSORS"){
                cout<<"Invalid input.\n";
                continue;
            }

            string RPS = rockRouletteGuess();
            cout<<"Computer chose: "<<RPS<<endl;

            rockpaperGame(guess, RPS);
        }

        if(Phealth <= 0)
            cout<<"\nYou lost the game!\n";
        else
            cout<<"\nYou won the game!\n";

        cout<<"Play again? (y/n): ";
        cin>>again;

    } while(again == 'y' || again == 'Y');

    return 0;
}