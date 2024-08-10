#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>

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
		arquivo >> lixo;
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
			arquivo >> lixo;
			arquivo >> exoticos[i].vida;
			arquivo.ignore(); //pula fim de linha
		
		}
		i++;
	}	
	tamanho = i-1;
}
	

void saida(animais* exoticos, int tamanho,bool &erro){
	cout << "Voce deseja mostrar todos os dados?"<< endl;
	cout << "1 - Sim"<< endl;
	cout << "2- Nao" << endl;
	
	int resposta=0;
	cin >> resposta;
	if(resposta == 1){
		for(int k = 0; k<tamanho; k++){
			cout << exoticos[k].identificador << ",";
			cout << exoticos[k].nome << "," ;
			cout << exoticos[k].pais << "," ;
			cout << exoticos[k].classe << ",";
			cout << exoticos[k].vida << endl;
	}
}
	else if(resposta== 2){
		int n=0;
		int j=0;
		system("clear");
		cout << "De qual ate qual dado voce quer mostrar?"<< endl;
		cout << endl;
		cout << "Comeco: ";
		cin >> n;
		cout <<"Fim: ";
		cin >> j;
		cout << endl;
		
		for(int i=n-1; i<=j-1;i++){
			cout << exoticos[i].identificador << ",";
			cout << exoticos[i].nome << "," ;
			cout << exoticos[i].pais << "," ;
			cout << exoticos[i].classe << ",";
			cout << exoticos[i].vida << endl;
		}
		cout << endl;
	}
	else{
		erro = true;
		
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
		cin >> exoticos[i].pais;
		cout << "Adcionar classe: ";
		cin >> exoticos[i].classe;
		cout << "Adcionar tempo de vida: ";
		cin >> exoticos[i].vida;
		}
		 
		
}
void menu(animais*exoticos, int tamanho,bool erro){
	system("clear");
	int n;
	int resposta=0;
	cout << "O que deseja fazer?" << endl;
	cout << "1- Mostrar os dados do existentes no programa" << endl;
	cout << "2- Adicionar dados no programa" << endl;
	cout <<"5- Sair do programa" << endl;
	cin >> n;
	
	
	
	system("clear");
	if(n == 1){    //caso de saida
		saida(exoticos,tamanho,erro);
		cout << endl;
		cout << "Deseja voltar ao menu principal?"<< endl;
		cout << "1 - Sim" << endl;
		cout << "2 - Nao" << endl;
		
		cin >> resposta;
		
		if(resposta ==1){
		system("clear");
		menu(exoticos,tamanho,erro);
	}
}
	if(n == 2){	   //caso de adição de animais
		adcionar(exoticos,tamanho);
		system("clear");
		menu(exoticos,tamanho,erro);
		
		}
	if(n==5){ //caso de encerramento do programa
		exit(5);
	}
	else{ //caso de erro
		erro = true;
		
	}
		
}


int main(){
	ifstream arquivo("animais.csv");
	int tamanho=40;
	string linha;
	bool erro = false;
	getline(arquivo,linha);//primeira linha
	
	
	animais* exoticos = new animais[40];
	
	leitura(arquivo,exoticos,tamanho);
	
	menu(exoticos,tamanho,erro);
	
	int resposta;
	while(erro == 0){ //repetiçao do erro
		cout << "Nao existe essa opcao no programa" << endl;
		cout << endl;
		cout << "Deseja voltar ao menu principal?"<< endl;
		cout << "1 - Sim" << endl;
		cout << "2 - Nao" << endl;
		cin >> resposta;
		
		if(resposta == 1){
			erro = false;
			menu(exoticos,tamanho,erro);
		}
		else if(resposta == 2){
			exit(2);
		}
		else{
			system("clear");
		}
	}
	return 0;
}
