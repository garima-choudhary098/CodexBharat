#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(){
    srand(time(0));//random number generator
    const int min=1;
    const int max=100;
   int random = min + (rand()% max);

int userGuess;
int attempts=0;
const int maxpoints=100;

cout<<"WELCOME TO THE NUMBER GUESSING GAME!\n";
cout<<"You have to guess a number between 1 and 100. GOOD LUCK!! ";

do
{
    cout<<"Enter your guess :";
    cin>>userGuess;
    attempts++;

    if(userGuess < random){
        cout<<"Too Low! Try again.\n";
    }
    else if(userGuess > random){
        cout<<"Too High! Try again.\n";
    }
    else{
        cout<<"Congratulations! You've gussed the correct number!\n";
    }
    }while(userGuess != random);

    int score = maxpoints - attempts * 10;
    if(score<0){
        //score=0;
    }

  cout<<"You guessed the number in"<< attempts<<"attempts.\n";
  cout<<"Your score: "<<score <<" / "<<maxpoints<<"\n";

  return 0;

    
    }










