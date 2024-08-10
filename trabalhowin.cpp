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
int particionaIdent(animais* exoticos, int c, int f) { 
   int pivo = exoticos[c].identificador, i = c+1, j = f;
   while (i <= j) {
       if (exoticos[i].identificador <= pivo) i++;
       else if (pivo <= exoticos[j].identificador) j--; 
       else { 
           swap (exoticos[i],exoticos[j]);
           i++;
           j--;
       }
   }                
   exoticos[c].identificador = exoticos[j].identificador;
   exoticos[j].identificador = pivo;
   return j; 
}
void quicksortIdent(animais* exoticos, int pos_pivo, int fim) {
   int pos_novo_pivo;         
   if (pos_pivo < fim) {  
      pos_novo_pivo = particionaIdent(exoticos, pos_pivo, fim);
      quicksortIdent(exoticos, pos_pivo, pos_novo_pivo - 1); 
      quicksortIdent(exoticos, pos_novo_pivo + 1, fim); 
   }
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
		system("cls");
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
void menu(animais*exoticos, int tamanho,bool &erro){
	system("cls");
	int n;
	int resposta=0;
	cout << "O que deseja fazer?" << endl;
	cout << "1- Mostrar os dados do existentes no programa" << endl;
	cout << "2- Adicionar dados no programa" << endl;
	cout << "3- Ordenar os dados" << endl;
	cout <<"5- Sair do programa" << endl;
	cin >> n;
	
	
	
	system("cls");
	if(n == 1){    //caso de saida
		saida(exoticos,tamanho,erro);
		cout << endl;
		cout << "Deseja voltar ao menu principal?"<< endl;
		cout << "1 - Sim" << endl;
		cout << "2 - Nao" << endl;
		
		cin >> resposta;
		
		if(resposta ==1){
		system("cls");
		menu(exoticos,tamanho,erro);
	}
}
	else if(n == 2){	   //caso de adição de animais
		adcionar(exoticos,tamanho);
		system("cls");
		menu(exoticos,tamanho,erro);
		
		}
	else if(n==3){ // ordenar o vetor 
		cout <<"Deseja ordenar por identificador ou por nome do animal?"<< endl;
		cout << "1- Identificador" << endl;
		cout << "2 - Nome do Animal"<< endl;
		cin >> resposta;
		
		if(resposta == 1){//ordenar por identificador
			resposta = 0;
			quicksortIdent(exoticos,0,tamanho-1);
			system("cls");
			cout << "Os dados foram ordenados por identificador!" << endl;
			cout << endl;
			cout << "Deseja ver os dados?" << endl;
			cout <<"1- Sim" << endl;
			cout <<"2- Nao" << endl;
			cin >> resposta;
			
			if(resposta ==1){
				system("cls");
				resposta =0;
				saida(exoticos,tamanho,erro);
				cout << endl;
				cout << "Deseja voltar ao menu principal?"<< endl;
				cout << "1 - Sim" << endl;
				cout << "2 - Nao" << endl;
				cin >> resposta;
		
				if(resposta ==1){
					system("cls");
					menu(exoticos,tamanho,erro);
				}
				else if(resposta == 2){
				exit(2);
				}
				else{
				erro = true;
				}
			}
			else if(resposta == 2){
				system("cls");
				resposta =0;
				cout << "Deseja voltar ao menu principal?"<< endl;
				cout << "1 - Sim" << endl;
				cout << "2 - Nao" << endl;
				cin >> resposta;
				
					if(resposta ==1){
						system("cls");
						menu(exoticos,tamanho,erro);
					}
					else if(resposta == 2){
						exit(2);
					}
					else{
						erro = true;
					}
			}
			else{// caso de erro
				erro = true;
			}
			
				
		}
		else if(resposta == 2){//ordenar por nome do animal
		}
		else{// caso de erro
			erro = true;
		}
	}
	else if(n==5){ //caso de encerramento do programa
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
	while(erro == true){ //repetiçao do erro
		system("cls");
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
			system("cls");
		}
	}
	return 0;
}
