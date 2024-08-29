#include <iostream>
#include <string>

using namespace std;
//**********************************************************************
class pessoa{
  string nome;
  string cpf;// e bom usar string pois aqui nao representa um numero como um todo , mas cada numero conta !

protected:
  double salario;

public:
  pessoa(string n, string c, double s):nome(n),cpf(c),salario(s){
    cout<< "pessoa criada"<< endl;
    
  }
  ~pessoa(){
    cout<< "pessoa destruida"<< endl;
  }
  void set_nome(string n){
    nome = n;
  }

  string get_nome(){
    return nome;
  }

  void set_cpf(string c){
    cpf = c;
  }

  string get_cpf(){
    return cpf;
  }
  void set_salario(double s){
    salario = s;
  }

  double get_salario(){
    return salario;
  }

    void print_info(){
        cout << "nome: " << nome << endl;
        cout << "cpf: " << cpf << endl;
        cout << "salario: " << salario << endl;
      
    }

};

//**************************************************************************************
class funcionario: public pessoa{
  int carga_horaria;
  string departamento;

public:
  funcionario(string n, string c, double s, int ch, string d):pessoa(n,c,s),carga_horaria(ch),departamento(d){
    cout << " funcionario feito"<< endl;
  }
  ~funcionario(){
    cout << "funcionario destruido"<< endl;
  }

  void modifica_salario(){
    salario = salario*1.3;
  }

  void set_carga_horaria(int ch){
    carga_horaria = ch;
  }

  int get_carga_horaria(){
    return carga_horaria;
  }

  void set_departamento(string d){
    departamento = d;
  }

  string get_departamento(){
    return departamento;
  }
  void print_info(){
        cout << "nome: " << get_nome() << endl;
        cout << "cpf: " << get_cpf() << endl;
        cout << "salario: " << salario << endl;
        cout << "carga horaria: " << carga_horaria << endl;
        cout << "departamento: " << departamento << endl;
        
    }

  

};

//****************************************************************

class gerente:pessoa {
  double bonus;
  string projeto;
public:
  gerente(string n, string c, double s, double b, string p):pessoa(n,c,s),bonus(b),projeto(p){
  cout<<"gerente feito"<<endl;
    
  }  

  ~gerente(){
    cout<<"gerente destruido"<<endl;
  }

  void set_bonus(double b){
    bonus = b;
  }

  double get_bonus(){
    return bonus;
  }

  void set_projeto(string p){
    projeto = p;
  }

  string get_projeto(){
    return projeto;
  }

  void modifica_salario(){
    salario = (salario*2)+bonus;
  }

  void print_info(){
        cout << "nome: " << get_nome() << endl;
        cout << "cpf: " << get_cpf() << endl;
        cout << "salario: " << salario << endl;
        cout<< "bonus: "<<bonus<<endl;
        cout<< "projeto: "<<projeto<<endl;
  }

};


//*****************************************************************
int main (){
pessoa p1("ana","123",1000); 
funcionario f1("lulu","456",2000,40,"aleatorio");
gerente g1("joao","789",3000,500,"projeto x");  

  f1.modifica_salario();
  f1.print_info();

  g1.modifica_salario();
  g1.print_info();
  

  // criar um funcionario,calcular salario e exibir salario
  //criar gerente ,calcular salario e exibir salario.
  return 0;
  
}