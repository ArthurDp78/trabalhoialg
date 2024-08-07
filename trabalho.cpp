#include <iostream>
#include <fstream>

using namespace std;

struct animais{
	int identificador;
	string nome;
	string país;
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
		getline(arquivo, exoticos[i].país,',');
		arquivo >> exoticos[i].classe;
		arquivo >> exoticos[i].vida;
		arquivo.ignore(); //pula fim de linha
		
	}
		else{
			
			animais* novo = new animais[tamanho+5];
			
			for(int j=0; j < tamanho; j++){
				novo[j].identificador = exoticos[j].identificador;
				novo[j].nome = exoticos[j].nome;
				novo[j].país = exoticos[j].país;
				novo[j].classe = exoticos[j].classe;
				novo[j].vida = exoticos[j].vida;
			}
			
		
			tamanho= tamanho +5;
			delete[] exoticos;
			exoticos = novo;
			
			arquivo >> exoticos[i].identificador;
			arquivo >> lixo; //lê a virgula
			getline(arquivo, exoticos[i].nome,',');
			getline(arquivo, exoticos[i].país,',');
			arquivo >> exoticos[i].classe;
			arquivo >> exoticos[i].vida;
			arquivo.ignore(); //pula fim de linha
		
		}
		i++;
	}	
	tamanho = i-1;
}

void saida(animais* exoticos, int tamanho){
	for(int k = 0; k <tamanho; k++){
		cout << exoticos[k].identificador << ", ";
		cout << exoticos[k].nome << ", ";
		cout << exoticos[k].país << ", ";
		cout << exoticos[k].classe<<" " ;
		cout << exoticos[k].vida << endl;
	}
}

int main(){
	ifstream arquivo("trabalho.csv");
	int tamanho=40;
	string linha;
	
	getline(arquivo,linha);//primeira linha
	
	
	animais* exoticos = new animais[40];
	
	leitura(arquivo,exoticos,tamanho);
	
	arquivo.close();
	

	short n;
	cin >> n;
	
	if(n == 1){    //caso de saida
		saida(exoticos,tamanho);
	}
	
	
	else cout << "fon";
	
	
	return 0;
}
