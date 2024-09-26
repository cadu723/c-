#include <iostream>

using std::cout;
using std::string;
using std::endl;

class shape{
static int formas;
public:
shape(){
  formas++;
}
virtual double area() const {
  return 0;

}
static void numero_formas(){
  cout<<"foram feitas : "<<formas<<endl;
}

};
int shape::formas = 0;

class circle:public shape{
double radius;
public:

circle(double r):radius(r){}

double area() const override{
  return 3.14*radius*radius;
}

};
class rectangle:public shape{
double height,width;
public:
rectangle(double h,double w):height(h),width(w){}
double area()const override{
  return height*width;
}

};
class animal{
virtual void speak() const = 0;

};
class dog:public animal{
public:
void speak() const override{
  cout<<"auau"<<endl;
}


};
class cat:public animal{
public:
void speak()const override{
  cout << "miau "<<endl;
}

};

int main(){
  circle c1(5);
  rectangle r1(5,5);
  shape::numero_formas();

  dog d1;
  cat gatin;

  d1.speak();
  gatin.speak();
  
}