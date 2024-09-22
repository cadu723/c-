#include <iostream>

//codigo usando heranca protected
using std::cout;
using std::string;
using std::endl;

class veiculo{
protected:
  float fuel;

  veiculo(float f):fuel(f){}

  void consumo(float quantia){
    if(quantia<=fuel){
      fuel-=quantia;
      cout<< "consumo: "<< quantia <<"litros"<<endl;
    }else{
      cout<<"combuivel insuficiente"<<endl;
    }
  }
};

class car:protected veiculo{
public:
  car(float f):veiculo(f){}

  void drive(float distancia){
    consumo(distancia * 0.1);
    cout << "distancia percorrida: "<< distancia <<"km. comustivel restante"<< fuel <<"litros"<<endl;
    
  }
};

class truck:protected veiculo{
public:
  truck(float f):veiculo(f){}

  void haul(float peso){
    consumo(peso*0.2);
    cout<< "peso transportado: "<<peso<<"kg. combustivel restante: "<<fuel<<"litros"<<endl;
  }

};



int main(){
  car mycar(10);
  mycar.drive(100);
  
  truck mytruck(20);
  mytruck.haul(10);
  
  return 0;
}