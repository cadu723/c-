#include <iostream>
#include <ctime>

using namespace std;

int main(){

  srand(time(NULL));
  int num= (rand()%100)+1;
  int guess;
  int tries = 0; 


  cout<<"******* number guess game ********"<<endl;

  do{
    cout<<"guess a number between 1 and 100: "<<endl;
    cin>>guess;
    tries++;

    if(guess>num){
      cout<<"too high"<<endl;
    }else if(guess < num){
      cout<<"too low"<<endl;
    }else{
      cout<<"correct!!!"<<endl<<"tries: "<<tries<<endl;
    }

  }while(guess!=num);

  cout<<"numero aleatorio: "<<num<<endl;

  return 0;
}