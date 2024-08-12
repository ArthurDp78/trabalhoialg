#include <iostream>
#include <fstream>
#include <stdlib.h>

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
	
	short auxvida;
	string auxclasse;
	string auxpais;
	string auxnome;
	
   while (i <= j) {
       if (exoticos[i].identificador <= pivo) i++;
       else if (pivo <= exoticos[j].identificador) j--; 
       else { 
           swap (exoticos[i].nome,exoticos[j].nome);
           swap (exoticos[i].classe,exoticos[j].classe);
           swap (exoticos[i].identificador,exoticos[j].identificador);
           swap (exoticos[i].pais,exoticos[j].pais);
           swap (exoticos[i].vida,exoticos[j].vida);
           i++;
           j--;
       }
   }                
   exoticos[c].identificador = exoticos[j].identificador;
   exoticos[j].identificador = pivo;
   
   
	auxnome = exoticos[c].nome;
	auxvida = exoticos[c].vida;
	auxclasse = exoticos[c].classe;
	auxpais = exoticos[c].pais;
   
	exoticos[c].nome = exoticos[j].nome;
	exoticos[c].vida = exoticos[j].vida;
	exoticos[c].classe = exoticos[j].classe;
	exoticos[c].pais = exoticos[j].pais;
	
	exoticos[j].nome = auxnome;
	exoticos[j].vida = auxvida;
	exoticos[j].classe = auxclasse;
	exoticos[j].pais = auxpais;
	
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


int particionaNome(animais* exoticos, int c, int f) { 
   int i = c+1, j = f;
   string pivo = exoticos[c].nome;
   
   int auxident;
   short auxvida;
   string auxclasse;
   string auxpais;
   
   while (i <= j) {
       if (exoticos[i].nome <= pivo) i++;
       else if (pivo <= exoticos[j].nome) j--; 
       else { 
           swap (exoticos[i].nome,exoticos[j].nome);
           swap (exoticos[i].classe,exoticos[j].classe);
           swap (exoticos[i].identificador,exoticos[j].identificador);
           swap (exoticos[i].pais,exoticos[j].pais);
           swap (exoticos[i].vida,exoticos[j].vida);
           i++;
           j--;
       }
   }                
	exoticos[c].nome = exoticos[j].nome;
	exoticos[j].nome = pivo;
   
	auxident = exoticos[c].identificador;
	auxvida = exoticos[c].vida;
	auxclasse = exoticos[c].classe;
	auxpais = exoticos[c].pais;
   
	exoticos[c].identificador = exoticos[j].identificador;
	exoticos[c].vida = exoticos[j].vida;
	exoticos[c].classe = exoticos[j].classe;
	exoticos[c].pais = exoticos[j].pais;
	
	exoticos[j].identificador = auxident;
	exoticos[j].vida = auxvida;
	exoticos[j].classe = auxclasse;
	exoticos[j].pais = auxpais;
	
   return j; 
}
void quicksortNome(animais* exoticos, int pos_pivo, int fim) {
   int pos_novo_pivo;         
   if (pos_pivo < fim) {  
      pos_novo_pivo = particionaNome(exoticos, pos_pivo, fim);
      quicksortNome(exoticos, pos_pivo, pos_novo_pivo - 1); 
      quicksortNome(exoticos, pos_novo_pivo + 1, fim); 
   }
}	


void saida(animais* exoticos, int tamanho,bool &erro){
	cout << "Voce deseja mostrar todos os dados?"<< endl;
	cout << "1 - Sim"<< endl;
	cout << "2 - Nao" << endl;
	
	int resposta=0;
	cin >> resposta;
	system("cls");
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
void adcionarArquivo(animais* exoticos,int &tamanho){
	ofstream saida("animais.csv");
	saida << "# identificador; nome; país; classe; tempo de vida" << endl;
	for (int g=0;g<tamanho;g++){
		saida << exoticos[g].identificador << "," << exoticos[g].nome << "," << exoticos[g].pais << "," << exoticos[g].classe << "," << exoticos[g].vida << endl;
		}
		
	
}

void adcionar(animais* exoticos,int &tamanho){
	for (int i=0;i<tamanho+1;i++){
		cout << "Adicionar identificador: ";
		cin >> exoticos[i].identificador;
		cout << "Adicionar nome: ";
		getline(cin,exoticos[i].nome);
		cout << "Adicionar pais de origem: ";
		getline(cin,exoticos[i].pais);
		cin >> exoticos[i].pais;
		cout << "Adicionar classe: ";
		cin >> exoticos[i].classe;
		cout << "Adicionar tempo de vida: ";
		cin >> exoticos[i].vida;
		}	
}
void menu(animais*exoticos, int tamanho,bool &erro){
	system("cls");
	int n;
	int resposta=0;
	cout << "O que deseja fazer?" << endl;
	cout << "1 - Mostrar os dados do existentes no programa" << endl;
	cout << "2 - Adicionar dados no programa" << endl;
	cout << "3 - Ordenar os dados" << endl;
	cout << "4 - Adicionar dados ao arquivo" << endl;
	cout << "0 - Sair do programa" << endl;
	cin >> n;
	
	
	
	system("cls");
	if(n == 1){    //caso de saida
		saida(exoticos,tamanho,erro);
		if (erro == false){
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
	}
	else if(n == 2){	   //caso de adição de animais
		adcionar(exoticos,tamanho);
		system("cls");
		menu(exoticos,tamanho,erro);
		
		}
	else if(n==3){ // ordenar o vetor 
		cout <<"Deseja ordenar por identificador ou por nome do animal?"<< endl;
		cout << "1 - Identificador" << endl;
		cout << "2 - Nome"<< endl;
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
			resposta = 0;
			quicksortNome(exoticos,0,tamanho-1);
			system("cls");
			cout << "Os dados foram ordenados por nome!" << endl;
			cout << endl;
			
			cout << "Deseja ver os dados?" << endl;
			cout <<"1 - Sim" << endl;
			cout <<"2 - Nao" << endl;
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
		else{// caso de erro
			erro = true;
		}
	}
	else if(n==4){ //salvar alterações no arquivo
		resposta=0;
		adcionarArquivo(exoticos,tamanho);
		system("cls");
		cout << "Arquivos adicionados com sucesso!"<< endl;
		cout << endl;
		cout << "Deseja voltar ao menu ?" << endl;
		cout << "1 - Sim" << endl;
		cout << "2 - Nao" << endl;
		cin >> resposta;
		if (resposta == 1){
			resposta=0;
			menu(exoticos,tamanho,erro);
			}
		else if (resposta == 2){
			exit(2);
			}
		else {
			erro = true;
			}
		}
	
	else if(n==0){ //caso de encerramento do programa
		exit(0);
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
