/* Assume you are developing a program to simulate a game where players take turns to guess
a number between 1 and 100. The program generates a random number between 1 and 100 at the
start of the game, and the player who guesses the correct number wins the game. If a player guesses
incorrectly, the program tells them whether their guess was too high or too low, and the turn passes
to the next player. Solve it using Direct Recursion? */
#include<iostream>
using namespace std;
bool guess(int n,int ans)
{
    if(n==ans)return true;
    else if(n>ans)
        cout<<"Wrong guess,too high,next player,enter your guess :"<<endl;
   else
        cout<<"Wrong guess,too low,next player,enter your guess :"<<endl;

    cin>>n;
    return guess(n,ans);
}
int main()
{
cout<<"Player ,enter your guess "<<endl;
int a,ans=rand()%100;
cin>>a;

if(guess(a,ans))cout<<"Congrats,you guessed it right ";

}