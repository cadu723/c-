#include <iostream>
#include <memory>
#include <vector>
#include <string>

using std::cout;
using std::string;
using std::endl;
using std::ostream;
using std::istream;
using std::cin;
using std::unique_ptr;
using std::make_unique;
using std::shared_ptr;
using std::vector;



class pessoa{
protected:
   string nome;
   int idade;
   static int contador;

public:
   pessoa(string n, int i):nome(n), idade(i){
      contador++;
   }

  virtual ~pessoa() {
      contador--; 
  }

  void set_Nome(string n){
    nome = n;
  }
  void set_Idade(int i){
    idade = i;
  }
  string get_Nome(){
    return nome;
  }
  int get_Idade(){
    return idade;
  }
  
  static int get_contador(){
    return contador;
  }

  bool operator== (const pessoa& outra) const{
    return nome == outra.nome && idade == outra.idade;
  } 

  virtual void exibir_informacoes() const = 0;

};//classe 1
  int pessoa::contador = 0;

class membro_club:public pessoa{
protected:
 double salario;

public:
  membro_club(string n, int i, double s):pessoa(n,i), salario(s){}

  void set_salario(double s){
    salario = s;
  }
  double get_salario(){
    return salario;
  }

  virtual double calcular_salario() const = 0;

  friend ostream& operator<<(ostream& os,const membro_club& membro){//voltar aqui
    os << "Nome: " << membro.nome << endl;
    os << "Idade: " << membro.idade << endl;
    os << "Salário: " << membro.salario << endl;
    return os;
  }
  
};//classe2

class jogador:virtual public membro_club{
protected:
  string posicao;
  int gols_marcados;

public:

  jogador(string n, int i, double s, string p, int g):membro_club(n,i,s), posicao(p), gols_marcados(g){}
  void set_posicao(string p){
    posicao = p;
  }
  void set_gols_marcados(int g){
    gols_marcados = g;
  }
  string get_posicao(){
    return posicao;
  }
  int get_gols_marcados(){
    return gols_marcados;
  }

 virtual double calcular_salario() const override{
    return salario + (gols_marcados * 100);
 }

auto operator < (const jogador& outro) const{
  return gols_marcados < outro.gols_marcados;
}
    

  };//classe 3

class tecnico:virtual public membro_club{
protected:
  int experiencia;
public:
  tecnico(string n, int i, double s, int e):membro_club(n,i,s), experiencia(e){}

  void set_experiencia(int e){
    experiencia = e;
  }
  int get_experiencia(){
    return experiencia;
  }
  virtual double calcular_salario() const override{
    return salario + (experiencia * 200);
  }

};//classe 4 

class tecnico_jogador:public tecnico, public jogador{
  double bonus_duplo_papel;
public: 
  tecnico_jogador(string n, int i, double s, int e, string p, int g, double b):membro_club(n,i,s), tecnico(n,i,s,e), jogador(n,i,s,p,g), bonus_duplo_papel(b){}

  void set_bonus_duplo_papel(double b){
    bonus_duplo_papel = b;
  }
  double get_bonus_duplo_papel(){
    return bonus_duplo_papel;
  }

  double calcular_salario() const override {
    return jogador::calcular_salario() + tecnico::calcular_salario() + bonus_duplo_papel;
  }//acho que era assim que voce queria ne prof? 

  friend ostream& operator<<(ostream& os, const tecnico_jogador& tecnico_jogador){
    os << "Nome: " << tecnico_jogador.nome << endl;
    os << "Idade: " << tecnico_jogador.idade << endl;
    os << "Salário: " << tecnico_jogador.salario << endl;
    os << "Posição: " << tecnico_jogador.posicao << endl;
    os << "Gols Marcados: " << tecnico_jogador.gols_marcados;
    os << "Experiência: " << tecnico_jogador.experiencia << endl;
    os << "Bonus Duplo Papel: " << tecnico_jogador.bonus_duplo_papel;
    return os;
  }


};//classe 5 pegou de tec e jog

class juiz:virtual public pessoa{
  int partidas_arbitradas;
public:
  juiz(string n, int i, int p):pessoa(n,i), partidas_arbitradas(p){}
  void set_partidas_arbitradas(int p){
    partidas_arbitradas = p;
  }
  int get_partidas_arbitradas(){
    return partidas_arbitradas;
  }

  void incrementar_partidas_arbitradas(){
    partidas_arbitradas++;
  }

  void exibir_informacoes() const override{
    cout << "Nome: " << nome << endl;
    cout << "Idade: " << idade << endl;
    cout << "Partidas Arbitradas: " << partidas_arbitradas << endl;
    }
  

};//classe 6

class time_fut{
  string nome;
  unique_ptr<tecnico> tecnico ;
  vector<std::unique_ptr<jogador>> jogadores;
  int pontos;

public:
   time_fut(const string& nome, unique_ptr<tecnico> t)
       : nome(nome), tecnico(std::move(t)), pontos(0) {//erro aqui , voltar aqui !!
   }

  void adicionar_jogador(unique_ptr<jogador> jogador) {
    jogadores.push_back(std::move(jogador));
}

int get_pontos() const {
    return pontos;
}
string get_nome() const {
    return nome;
} 


void registrar_resultado(char resultado){
  if(resultado == 'V'){
    pontos += 3;
  }else if(resultado =='E' ){
    pontos += 1;
  }else{
    pontos += 0;
  }
  
}
  void exibir_informacoes() const {
    cout << "Nome do Time: " << nome << endl;
    cout << "Técnico:" << endl;
    tecnico->exibir_informacoes();
    cout << "Jogadores:" << endl;
    for (const auto& jogador : jogadores) {
      jogador->exibir_informacoes();
    }
    cout << "Pontos: " << pontos << endl;
  }

  
  bool operator<(const time_fut& outro) const {
    return pontos < outro.pontos;
  }

};//class 7 , voltar aqui erro de comp

class jogo{
  shared_ptr<time_fut> time_casa;
  shared_ptr<time_fut> time_visitante;
  shared_ptr<juiz> juiz_principal;
  int gols_time_casa;
  int gols_time_visitante;

public:
  jogo(shared_ptr<time_fut> tc, shared_ptr<time_fut> tv, shared_ptr<juiz> jp, int gc, int gv):time_casa(tc), time_visitante(tv), juiz_principal(jp), gols_time_casa(gc), gols_time_visitante(gv){}

  void set_time_casa(shared_ptr<time_fut> tc){
    time_casa = tc;
  }

  void set_time_visitante(shared_ptr<time_fut> tv){
    time_visitante = tv;
  }

  void set_juiz_principal(shared_ptr<juiz> jp){
    juiz_principal = jp;
  }

  void set_gols_time_casa(int gc){
    gols_time_casa = gc;
  }

  void set_gols_time_visitante(int gv){
    gols_time_visitante = gv;
  }
  
  shared_ptr<time_fut> get_time_casa(){
    return time_casa;
  }

  shared_ptr<time_fut> get_time_visitante(){
    return time_visitante;
  }

  shared_ptr<juiz> get_juiz_principal(){
    return juiz_principal;
  }

  int get_gols_time_casa(){
    return gols_time_casa;
  }

  int get_gols_time_visitante(){
    return gols_time_visitante;
  }
  
  void registrar_resultado(int gols_casa, int gols_visitante) {
    gols_time_casa = gols_casa;
    gols_time_visitante = gols_visitante;

    if (gols_casa > gols_visitante) {
      time_casa->registrar_resultado('V');
      time_visitante->registrar_resultado('D');
    } else if (gols_casa < gols_visitante) {
      time_casa->registrar_resultado('D');
      time_visitante->registrar_resultado('V');
    } else {
      time_casa->registrar_resultado('E');
      time_visitante->registrar_resultado('E');
    }
  }

  void exibir_informacoes() const {
    cout << "Time da Casa: " << time_casa->get_nome() << endl;
    cout << "Time Visitante: " << time_visitante->get_nome() << endl;
    cout << "Gols do Time da Casa: " << gols_time_casa << endl;
    cout << "Gols do Time Visitante: " << gols_time_visitante << endl;
    cout << "Juiz: " << juiz_principal->get_Nome() << endl;
  }

};
class campeonato{
  string nome_campeonato;
  vector<shared_ptr<time_fut>> times;
  vector<shared_ptr<jogo>> jogos;

public:
  campeonato(string n):nome_campeonato(n){}

  void set_nome_campeonato(string n){
    nome_campeonato = n;
  }
  string get_nome_campeonato(){
    return nome_campeonato;
  }
  void set_times(vector<shared_ptr<time_fut>> t){
    times = t;
  }
  vector<shared_ptr<time_fut>> get_times(){
    return times;
  }
  void set_jogos(vector<shared_ptr<jogo>> j){
    jogos = j;
  }
  vector<shared_ptr<jogo>> get_jogos(){
    return jogos;
  }

  void adicionar_time(shared_ptr<time_fut> t){
    times.push_back(t);
  }

  void adicionar_jogo(shared_ptr<jogo> j){
    jogos.push_back(j);
  }

  void exibir_classificacao() const {
    cout << "Classificação do Campeonato: " << nome_campeonato << endl;
    // Ordenar os times por pontos
    std::sort(times.begin(), times.end(), [](const auto& t1, const auto& t2) {//erro aqui , vou mudar
      return *t1 < *t2;
    });

    // Exibir a classificação
    for (const auto& time : times) {
      cout << time->get_nome() << ": " << time->get_pontos() << " pontos" << endl;
    }
  }


};


int main(){

  
  return 0;
} 
