#include <iostream>
#include <vector>

using std::cout;
using std::string;
using std::endl;
using std::vector;



class FileSystemItem{
 protected:
  string name;
  FileSystemItem(const string& n):name(n){}

  void showfile(){
    cout << "name: " << name << endl;
  }
};

class file:protected FileSystemItem{
public:
  file(const string& n):FileSystemItem(n){}

  void showfileinfo(){
    showfile();  
  }

};
class diretorio:protected FileSystemItem{
  vector<FileSystemItem*> items;//array de ponteiros para objetos da classe FileSystemItem
public:
  diretorio(const string& n):FileSystemItem(n){}
void add_item(FileSystemItem* item){
  items.push_back(item);//push_back adiciona um elemento ao final do vetor 
}
void showdirectorioinfo(){
  showfile();
  cout<< "tipo: diretorio"<<endl;
}

};


int main (){
  file myfile("myfile.txt");
  diretorio mydir("meudiretorio");

  myfile.showfileinfo();
  mydir.showdirectorioinfo();
  
  return 0;
}