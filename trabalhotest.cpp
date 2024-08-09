#include <iostream>
#include <fstream>

using namespace std;

struct animais{
	int identificador;
	string nome;
	string pais;
	string classe;
	short vida;
};
void leitura(ifstream &arquivo, animais* exoticos,int &tamanho){
	char lixo;
	int i=0;
	while(arquivo){
		if(i < tamanho){
		arquivo >> exoticos[i].identificador;
		arquivo >> lixo; //lê a virgula
		getline(arquivo, exoticos[i].nome,',');
		getline(arquivo, exoticos[i].pais,',');
		arquivo >> exoticos[i].classe;
		arquivo >> exoticos[i].vida;
		arquivo.ignore(); //pula fim de linha
		
	}
		else{
			
			animais* novo = new animais[tamanho+5];
			
			for(int j=0; j < tamanho; j++){
				novo[j].identificador = exoticos[j].identificador;
				novo[j].nome = exoticos[j].nome;
				novo[j].pais = exoticos[j].pais;
				novo[j].classe = exoticos[j].classe;
				novo[j].vida = exoticos[j].vida;
			}
			
		
			tamanho= tamanho +5;
			delete[] exoticos;
			exoticos = novo;
			
			arquivo >> exoticos[i].identificador;
			arquivo >> lixo; //lê a virgula
			getline(arquivo, exoticos[i].nome,',');
			getline(arquivo, exoticos[i].pais,',');
			arquivo >> exoticos[i].classe;
			arquivo >> exoticos[i].vida;
			arquivo.ignore(); //pula fim de linha
		
		}
		i++;
	}	
	tamanho = i-1;
}

void saida(animais* exoticos, int tamanho){
	for(int k = 0; k<tamanho; k++){
		cout << exoticos[k].identificador << ", ";
		cout << exoticos[k].nome << ", ";
		cout << exoticos[k].pais << ", ";
		cout << exoticos[k].classe<<" " ;
		cout << exoticos[k].vida << endl;
	}
	
	
}

void adcionar(animais* exoticos,int &tamanho){
	for (int i=tamanho;i<tamanho+1;i++){
		cout << "Adcionar identificador: ";
		cin >> exoticos[i].identificador;
		cout << "Adcionar nome: ";
		getline(cin,exoticos[i].nome);
		cout << "Adcionar pais de origem: ";
		getline(cin,exoticos[i].pais);
		cout << "Adcionar classe: ";
		cin >> exoticos[i].classe;
		cout << "Adcionar tempo de vida: ";
		cin >> exoticos[i].vida;
		}
}

int main(){
	ifstream arquivo("test.csv");
	int tamanho=40;
	string linha;
	
	getline(arquivo,linha);//primeira linha
	
	
	animais* exoticos = new animais[40];
	
	leitura(arquivo,exoticos,tamanho);
	
	short n;
	cin >> n;
	
	if(n == 1){    //caso de saida
		saida(exoticos,tamanho);
	}
	if(n == 2){	   //caso de adição de animais
		adcionar(exoticos,tamanho);
		}
	
	
	
	return 0;
}
