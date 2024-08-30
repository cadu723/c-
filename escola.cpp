#include <iostream>
#include <memory>
#include <string>
#include<vector>

using namespace std;


// **************************************************************************************************
class pessoa{
    string nome;
    int idade;
    
public:

    pessoa(const string& n,int i):nome(n),idade(i){
        
        cout<< "pessoa: "<< nome <<" criada"<< endl;
        
    }
    
    ~pessoa(){
        cout<< "pessoa " << nome << " destruida" << endl;
    }
    
    void set_name(string& nn){
        nome= nn;
        
    }
    
    string get_nome(){
        return nome;
        
    }
    
    
     void set_name(int& j){
        idade= j;
        
    }
    
    int get_idade(){
        return idade;
        
    }

    void set_idade(int i){
        idade= i;
        
    }
    
    
    void print_info() {
        cout<<"nome: "<< nome<<endl;
        cout<<"idade: "<<idade<<endl;
        
    }
    
};



//****************************************************************************************************************



class professor : public pessoa{ 
    string titulacao;
    int ano_titu;
    
public:
    professor(const string& n, int i,const string& t, int a):pessoa(n,i),titulacao(t),ano_titu(a){
        cout << "professor: "<< get_nome() <<" feito" << endl;
        
    }
    
    void set_titu(string& t){
        titulacao= t;
    }
    
    string get_titu(){
    return titulacao;
    }
    
    void set_anot(int i){
        ano_titu=i;
    }
    
    int get_anot(){
        return ano_titu;   
    }
    
    void print_info(){
        cout<<"professor: " << get_nome() << endl;
        cout<<"idade: " << get_idade() << endl;
        cout<<"titulacao: " << titulacao<<endl;
        cout <<"ano de titulacao: " <<ano_titu<< endl;
        
    }
};


//*********************************************************************************

class aluno:public pessoa{
    int cra;
    int matricula;
    
public :
    aluno(const string& n,int i,int c,int ma):pessoa(n,i),cra(c),matricula(ma){
        cout<<"aluno: "<<get_nome()<< "feito"<< endl;        
        
    }
    
    void set_cra(int cr){
        cra=cr;
    }
    
    int get_cra(){
        return cra;
    }
    
    int get_matricula(){
        return matricula;
    }
    
    
    void set_matricula(int maa){
        matricula= maa;
    }
    void print_info(){
        cout<<"aluno:  "<<get_nome();
        cout<<"idade: "<<get_idade();
        cout<<"," << get_cra();
        cout <<"," <<get_matricula();
        
    }
    
};

class tecnico: public pessoa{ 
    string departamento;
    string funcao;
    
    public:
    
    tecnico(const string&n,int i,const string& de,const string& f):pessoa(n,i),departamento(de),funcao(f){
        
        cout<< "tec: "<<get_nome()<<" pronto"<<endl;
    }
    
    
    void set_departamento(string& dep){
        departamento = dep;
    }
    
    string get_departamento(){
        return departamento;
        
    }
     void set_funcao(string& fx){
        funcao = fx;
    }
    
    string get_funcao(){
        return funcao;
        
    }
     void print_info(){
        cout<<"tecnico:  "<<get_nome();
        cout<<"idade: " << get_idade();
        cout<<"," << get_departamento();
        cout <<"," << get_funcao();
        
    }

};


class turma {
    professor *prof;
    vector <aluno *> lista_alunos;
    
public:
    turma(professor* p): prof(p){
        cout<<"turma"<<endl;
        
        
    }
    
    professor* get_professor()const {
        return prof;
    }
    
    void set_professor(professor* p){
        prof = p;
    }
    void add_aluno(aluno* a){
        lista_alunos.push_back(a);
    }
    void print_info(){
        cout<<"turma: "<< endl;
        cout << " professor:"<< endl;
        prof-> print_info();
        cout << " alunos: "<< endl;
        
        for(auto i = lista_alunos.begin(); i!=lista_alunos.end(); i++){
                (*i)->print_info();
            
        }
        
    }
    
    
    
};

class rh{
    vector<pessoa*> pessoal;
    
    public:
    
    void add_pessoa(pessoa* p){
        pessoal.push_back(p);
    }
    

    
};

//**********************************************************************************

int main(){
    pessoa p1("ana silva",38);
    professor pr1("joao",44,"doutor",2008);
    aluno al1("maria",18,9,1001232123);
    tecnico te1("juju",35,"dsc","assessor");
    turma tu1(&pr1);
    
    rh rh1;
    rh1.add_pessoa(&p1);
    rh1.add_pessoa(&pr1);
    rh1.add_pessoa(&al1);
    rh1.add_pessoa(&te1);
    
    pr1.set_idade(41);
    
    p1.print_info();
    pr1.print_info();
    
    tu1.add_aluno(&al1);

    return 0;
}