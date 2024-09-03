#include <iostream>
#include <string>
#define PI 3.1415

using std::cout;
using std::string;
using std::endl;

class poligono{
protected:
 string cor;
  
public:
 poligono(const string c):cor(c){}

virtual double get_area(){//metodo virtual aplicado para utilizacao de ponteiros, senao ele vai usar somente o da classe poligono
 return 0;

}
void set_cor(string& c){
cor=c;
}

string get_cor(){
  return cor;
}

};
//**********************************************************retangulo
class retangulos:public poligono{
 double base;
 double altura;

public:
 retangulos(const string c,double b,double a):poligono(c),base(b),altura(a){}

double get_area(){
  return base*altura;
}

void set_base(double b){
  base=b;
}

void set_altura(double a){
  altura=a;
}

double get_base(){
  return base;
}


double get_altura(){
  return altura;
}

};

//***********************************************circulo

class circulo:public poligono{
  double raio;

public: 
circulo(double r,const string c):poligono(c),raio(r){}

double get_area(){
  return PI*(raio*raio);
}

void set_raio(double r){
  raio=r;
}

double get_raio(){
  return raio;
}

};
//********************************************************triangulo
class triangulo:public poligono{
  double base;
  double altura;
public:
triangulo(double b,double a,const string c):poligono(c),base(b),altura(a){}

double get_area(){
  return (base*altura)/2;
}
void set_base(double b){
 base=b ;
}
void set_altura(double a){
  altura=a;
}

double get_base(){
  return base;
}
double get_altura(){
  return altura;
}



};

class trapezio:public poligono{
 double base_maior;
 double base_menor;
double altura;
public:
trapezio(double b_m,double b_mn,double a,const string c):poligono(c),base_maior(b_m),base_menor(b_mn),altura(a){
  
}
void set_base_maior(double b_m){
  base_maior=b_m;
}
void set_base_menor(double b_mn){
  base_menor=b_mn;
  
}
void set_altura(double a){
  altura=a;
}
double get_base_maior(){
  return base_maior;
}
double get_base_menor(){
  return base_menor;
}
double get_altura(){
  return altura;

}

double get_area(){
  return ((base_maior+base_menor)*altura)/2;
}
};


int main() {
  circulo cir1(10.5,"azul");
  retangulos ret1("amarelo",5.6,9.8);
  triangulo tri1(10,8.5,"vermelho");
  trapezio tra1(10,20,7,"verde");

  
  poligono* p1= &cir1;
  poligono* p2= &ret1;
  poligono* p3= &tri1;
  poligono* p4= &tra1;

  
  double soma_area=0;
  soma_area+=cir1.get_area()+ret1.get_area()+tri1.get_area()+tra1.get_area();
  cout << "soma das areas: "<< soma_area<<endl;

  soma_area =p1->get_area()+p2->get_area()+p3->get_area()+p4->get_area();
  cout << "soma das areas: "<< soma_area<<endl;
  
  return 0;
}