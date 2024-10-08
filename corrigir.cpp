#include <iostream>
#include <string>
#include<vector>
#include <memory>
#include <stdexcept>

using std::vector;
using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::exception;


class produto_nao_encontrado : public exception{
    public:
    const char* what(){
        return "nao achado";
    }
};

class quantidade_insuficiente{
    public:
    const char* what(){
        return "quantidade_insuficiente";
    }
}; 

class quantidade_invalida{
    public:
    const char* what(){
        return "quantidade_invalida";
    }
};


class produto {
  int id;
  string nome;
  int qtd;
  double preco;
  
  
  public :
  
  produto(int i,const string&n , int q, double p): id(i),nome(n),qtd(q),preco(p){
      
  }
};

class estoque{
    vector<produto> produtos;
      
    public:
    
    void adicionar_produto(const produto& p){
        
    }
    
    void remover_produto (int i){
        if(i < 0){
            throw new quantidade_invalidaij();
            
        }else if(i== 999){
            throw new produto_nao_encontrado();
        }
    }
    
    void atualiza_quantidade(int i, int q){
        if(i<0){
            throw new quantidade_invalida();
        }else if(i==888){
            throw new quantidade_insuficiente();
        }
        
    }
    
    void consultar_produto(int i){
        if(i==555){
            throw new produto_nao_encontrado();
        }
    }
    
};

 int main (){
     estoque e;
     
     try{
         produto p(10,"sabao",10,5.50);
         e.adicionar_produto(NULL);
         e.remover_produto(-10);
         e.consultar_produto(555);
     }catch(std::exception e){
         e<< e->what()<< endl;
     }
     
 }
