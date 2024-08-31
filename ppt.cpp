#include <iostream>
#include <ctime>

using namespace std;

char get_user_choice(){
    char player;
      
  cout <<"rock-paper-scissors"<<endl<<endl;
  do{
    cout << "enter your choice (r/p/s): "<<endl;
    cout << "r - rock"<<endl;
    cout <<"p - paper"<<endl;
    cout <<"s - scissors"<<endl<<"enter your answer: "<<endl<<endl;

    cin>>player;

    cout <<"player choice: "<<player<<endl<<endl;
    
  }while(player != 'r' && player != 'p' && player != 's');
  
    
  return player;
}

char get_Computer_choice(){
 int num=(rand()%3)+1;
  switch(num){
    case 1:
      return 'r';
    case 2:
      return 'p';
    case 3:
      return 's';
 
  }

  return 0;
}

void show_choice(char choice){
  switch(choice){
    case 'r':
      cout << "rock"<<endl;
      break;
    case 'p':
      cout << "paper"<<endl;
      break;
    case 's':
      cout << "scissors"<<endl;
      break;
    
  }

}
void choose_winner(char user, char computer){

  switch(user){
    case 'r':
      if(computer == 'r'){
        cout << "tie"<<endl;
      }else if(computer == 'p'){
        cout <<endl<< "YOU LOSE"<<endl<<"computer wins"<<endl;
      }else{
        cout <<endl<< "YOU WIN"<<endl<<"computer lose"<<endl;
      }
      break;
    case 'p':
    if(computer == 'p'){
      cout << "tie"<<endl;
    }else if(computer == 's'){
      cout <<endl<< "YOU LOSE"<<endl<<"computer wins"<<endl;
    }else{
      cout <<endl<< "YOU WIN"<<endl<<"computer lose"<<endl;
    }
    break;

    case 's':
    if(computer == 's'){
      cout << "tie"<<endl;
    }else if(computer == 'r'){
      cout <<endl<< "YOU LOSE"<<endl<<"computer wins"<<endl;
    }else{
      cout <<endl<< "YOU WIN"<<endl<<"computer lose"<<endl;
    }
    break;
    
  }

}

int main (){
  char player;
  char computer;
  srand(time(NULL));
  
  player = get_user_choice();
  
  cout << "Your choice: ";
  
  show_choice(player);
  
  computer = get_Computer_choice();  
  
  cout << "computer's choice: ";
  
  show_choice(computer);
  
  choose_winner(player, computer);
  
  return 0;
}