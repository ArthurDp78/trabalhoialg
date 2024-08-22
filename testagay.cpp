#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstring>

using namespace std;

struct animais{
	int identificador;
	string nome;
	string pais;
	string classe;
	short vida;	
};

struct animaiss2{
	int identificador;
	char nome[50];
	char pais[50];
	char classe[50];
	short vida;	
};

animais* leitura(ifstream &arquivo, animais* exoticos,int &tamanho){
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
	return exoticos;
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


void saida(animais* exoticos, int &tamanho,bool &erro){
	cout << "Voce deseja mostrar todos os dados?"<< endl;
	cout << "1 - Sim"<< endl;
	cout << "2 - Nao" << endl;
	
	int resposta=0;
	cin >> resposta;
	system("cls||clear");
	if(resposta == 1){
		for(int k = 0; k<tamanho; k++){
			if(exoticos[k].vida != 0){
				cout << "Identificador: "<< exoticos[k].identificador << endl ;
				cout << "Nome: "<< exoticos[k].nome << endl;
				cout << "Pais de origem: "<< exoticos[k].pais << endl;
				cout << "Classe: "<< exoticos[k].classe << endl ;
				cout << "Tempo de vida: "<< exoticos[k].vida << endl;
				cout << "====================================================" << endl;
				cout << endl;
		}
	}
}
	else if(resposta== 2){
		int n=0;
		int j=0;
		cout << "De qual ate qual dado voce quer mostrar?"<< endl;
		cout << endl;
		cout << "Inicio: ";
		cin >> n;
		cout <<"Final: ";
		cin >> j;
		cout << endl;
		
		for(int i=n-1; i<=j-1;i++){
			cout <<"Identificador: "<< exoticos[i].identificador << endl ;
			cout <<"Nome: "<< exoticos[i].nome << endl;
			cout << "Pais de origem: "<< exoticos[i].pais << endl;
			cout << "Classe: "<< exoticos[i].classe << endl ;
			cout << "Tempo de vida: "<< exoticos[i].vida << endl;
			cout << "====================================================" << endl;
			cout << endl;
		}
		cout << endl;
	}
	else{
		erro = true;
		
	}
}
void salvarArquivo(ofstream &saida,animais* exoticos,int &tamanho){
	saida.clear();
	saida << "# identificador; nome; país; classe; tempo de vida" << endl;
	for (int g=0;g<tamanho;g++){
		saida << exoticos[g].identificador << "," << exoticos[g].nome << "," << exoticos[g].pais << "," << exoticos[g].classe << " ," << exoticos[g].vida << endl;
		}
}
int BuscaBinariaIdent(animais* vetor, int inicio, int fim, int procurado) {     
    if (inicio <= fim){
        int meio = (inicio+fim)/2;
        if (procurado > vetor[meio].identificador)
            return BuscaBinariaIdent(vetor,meio+1,fim,procurado);
        else if (procurado < vetor[meio].identificador)
            return BuscaBinariaIdent(vetor,inicio,meio-1,procurado);
        else
            return meio;
    }
    return -1;
}

int BuscaBinariaNome(animais* vetor, int inicio, int fim, string procurado) {     
    if (inicio <= fim){
        int meio = (inicio+fim)/2;
        if (procurado > vetor[meio].nome)
            return BuscaBinariaNome(vetor,meio+1,fim,procurado);
        else if (procurado < vetor[meio].nome)
            return BuscaBinariaNome(vetor,inicio,meio-1,procurado);
        else
            return meio;
    }
    return -1;
}


void Buscar(animais* exoticos,int &tamanho,bool &erro){
	int resposta;
	cout << "Deseja buscar por identificador ou por nome ? " << endl << endl;
	cout << "1 - Identificador" << endl;
	cout << "2 - Nome" << endl;
	cin >> resposta;
	system("cls||clear");
	if (resposta == 1){
		quicksortIdent(exoticos,0,tamanho-1);
		cout << "Qual identificador deseja buscar ? ";
		int num;
		cin >> num;
		cout << endl;
		int position;
		position = BuscaBinariaIdent(exoticos,0,tamanho-1,num);
		if ( position != -1){
			cout << "Identificador: "<< exoticos[position].identificador << endl ;
			cout << "Nome: "<< exoticos[position].nome << endl;
			cout << "Pais de origem: "<< exoticos[position].pais << endl;
			cout << "Classe: "<< exoticos[position].classe << endl ;
			cout << "Tempo de vida: "<< exoticos[position].vida << endl;
			cout << endl;
			}
		else {
			cout << "Nao existe esse identificador no arquivo!" << endl << endl;
			erro = true;
			}
	}
	else if (resposta == 2){
		quicksortNome(exoticos,0,tamanho-1);
		cout << "Qual nome deseja buscar ? ";
		string name;
		cin.ignore();
		
		getline(cin,name);
		cout << endl;
		int positionNome;
		positionNome = BuscaBinariaNome(exoticos,0,tamanho-1,name);
		if (positionNome != -1){
			cout << exoticos[positionNome].identificador << ",";
			cout << exoticos[positionNome].nome << "," ;
			cout << exoticos[positionNome].pais << "," ;
			cout << exoticos[positionNome].classe << ",";
			cout << exoticos[positionNome].vida << endl << endl;
		}
		else {
			cout << "Nao existe esse animal no arquivo!" << endl << endl;
			erro = true;
			}
		}
	else {
		erro = true;
		}
	}

animais* adcionar(animais* exoticos,int &tamanho,bool &erro){
	int quantidade;
	cout << "Quantos animais voce quer adicionar ? ";
	cin >> quantidade;
	system("cls||clear");
	animais* array = new animais[tamanho+quantidade];
	for(int j=0; j < tamanho; j++){
				array[j].identificador = exoticos[j].identificador;
				array[j].nome = exoticos[j].nome;
				array[j].pais = exoticos[j].pais;
				array[j].classe = exoticos[j].classe;
				array[j].vida = exoticos[j].vida;
			}
	
	delete[] exoticos;
	exoticos = array;
	
	for (int i=tamanho;i<tamanho+quantidade;i++){
		cout << "Adicionar identificador(inteiro): ";
		cin >> exoticos[i].identificador;
		cin.ignore();
		cout << "Adicionar nome(String): ";
		getline(cin,exoticos[i].nome);
		cout << "Adicionar pais de origem(String): ";
		getline(cin,exoticos[i].pais);
		cout << "Adicionar classe(String): ";
		cin >> exoticos[i].classe;
		cout << "Adicionar tempo de vida(short): ";
		cin >> exoticos[i].vida;
		}	
	tamanho = tamanho+quantidade;
	system("cls||clear");
	int resposta;
	cout << "Dados adicionados com sucesso!" << endl << endl;
	cout << "Deseja ordenar os animais adcionados? "<< endl;
	cout << "1 - Sim" << endl;
	cout << "2 - Nao" << endl;
	cin >> resposta;
	system("cls||clear");
	if (resposta == 1){
		resposta = 0;
		cout <<"Deseja ordenar por identificador ou por nome do animal?"<< endl << endl;
		cout << "1 - Identificador" << endl;
		cout << "2 - Nome"<< endl;
		cin >> resposta;
		if (resposta == 1){
			resposta = 0;
			quicksortIdent(exoticos,0,tamanho-1);
			}
		else if(resposta == 2){
			resposta = 0;
			quicksortNome(exoticos,0,tamanho-1);
			}
		else {
			resposta = 0;
			erro = true;
			}
		}
	return exoticos;
}

animais* Delete(animais* exoticos,int &tamanho,bool &erro){
	int n;
	cout << "Qual identificador deseja deletar ? ";
	cin >> n;
	int posicao;
	for(int i=0; i< tamanho; i++){
		if(n == exoticos[i].identificador){
			posicao = i;
			}
		}
		tamanho--;
		animais* novo = new animais[tamanho];
		for(int k=0; k<posicao;k++){
				novo[k].identificador = exoticos[k].identificador;
				novo[k].nome = exoticos[k].nome;
				novo[k].classe = exoticos[k].classe;
				novo[k].pais = exoticos[k].pais;
				novo[k].vida = exoticos[k].vida;
		}
		for(int k=posicao+1;k<tamanho+1;k++){
				int j= k-1;
				novo[j].identificador = exoticos[k].identificador;
				novo[j].nome = exoticos[k].nome;
				novo[j].classe = exoticos[k].classe;
				novo[j].pais = exoticos[k].pais;
				novo[j].vida = exoticos[k].vida;
			}
		delete[] exoticos;
		exoticos = novo;
		return exoticos;
	}


void menu(animais* exoticos, int tamanho,bool &erro){
	system("cls||clear");
	int n;
	int resposta=0;
	cout << "O que deseja fazer?" << endl << endl;
	cout << "1 - Mostrar os dados do existentes no programa" << endl;
	cout << "2 - Adicionar dados ao programa" << endl;
	cout << "3 - Ordenar os dados" << endl;
	cout << "4 - Salvar dados no arquivo" << endl;
	cout << "5 - Buscar dados" << endl;
	cout << "6 - Deletar dados" << endl;
	cout << "7 - Importar e Exportar um arquivo binario" << endl;
	cout << "8 - Importar e Exportar um arquivo CSV" << endl;
	cout << "0 - Sair do programa" << endl;
	cin >> n;
	
	
	
	system("cls||clear");
	if(n == 1){    //caso de saida
		saida(exoticos,tamanho,erro);
		if (erro == false){
			cout << endl;
			cout << "Deseja voltar ao menu principal?"<< endl;
			cout << "1 - Sim" << endl;
			cout << "2 - Nao" << endl;
			
			cin >> resposta;
			
			if(resposta ==1){
			system("cls||clear");
			menu(exoticos,tamanho,erro);
			}
		}
	}
	else if(n == 2){	   //caso de adição de animais
		resposta = 0;
		exoticos = adcionar(exoticos,tamanho,erro);
		system("cls||clear");
		cout << "Dados atualizados com sucesso!" << endl << endl;
		cout << "Deseja voltar ao menu ? " << endl;
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
			resposta = 0;
			erro = true;
			}
		}	
	else if(n==3){ // ordenar o vetor 
		cout <<"Deseja ordenar por identificador ou por nome do animal?" << endl << endl;
		cout << "1 - Identificador" << endl;
		cout << "2 - Nome"<< endl;
		cin >> resposta;
		
		if(resposta == 1){//ordenar por identificador
			resposta = 0;
			quicksortIdent(exoticos,0,tamanho-1);
			system("cls||clear");
			cout << "Os dados foram ordenados por identificador!" << endl;
			cout << endl;
			
			cout << "Deseja ver os dados?" << endl;
			cout <<"1- Sim" << endl;
			cout <<"2- Nao" << endl;
			cin >> resposta;
			
			if(resposta ==1){
				system("cls||clear");
				resposta =0;
				saida(exoticos,tamanho,erro);
				cout << endl;
				cout << "Deseja voltar ao menu principal?"<< endl;
				cout << "1 - Sim" << endl;
				cout << "2 - Nao" << endl;
				cin >> resposta;
		
				if(resposta ==1){
					system("cls||clear");
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
				system("cls||clear");
				resposta =0;
				cout << "Deseja voltar ao menu principal?"<< endl;
				cout << "1 - Sim" << endl;
				cout << "2 - Nao" << endl;
				cin >> resposta;
				
					if(resposta ==1){
						system("cls||clear");
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
			system("cls||clear");
			cout << "Os dados foram ordenados por nome!" << endl;
			cout << endl;
			
			cout << "Deseja ver os dados?" << endl;
			cout <<"1 - Sim" << endl;
			cout <<"2 - Nao" << endl;
			cin >> resposta;
			
			if(resposta ==1){
				system("cls||clear");
				resposta =0;
				saida(exoticos,tamanho,erro);
				cout << endl;
				cout << "Deseja voltar ao menu principal?"<< endl;
				cout << "1 - Sim" << endl;
				cout << "2 - Nao" << endl;
				cin >> resposta;
		
				if(resposta ==1){
					system("cls||clear");
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
						resposta = 0;
						system("cls");
						menu(exoticos,tamanho,erro);
					}
					else if(resposta == 2){
						exit(2);
					}
					else{
						resposta = 0;
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
		ofstream saida("animais.csv");
		salvarArquivo(saida,exoticos,tamanho);
		saida.close();
		system("cls||clear");
		cout << "Dados salvos no arquivo com sucesso!"<< endl;
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
	else if(n==5){  //Buscar dados dentro do arquivo
		resposta = 0;
		Buscar(exoticos,tamanho,erro);
		if (erro == false){
			cout << "Deseja voltar ao menu principal?"<< endl;
			cout << "1 - Sim" << endl;
			cout << "2 - Nao" << endl;
			cin >> resposta;
			if(resposta ==1){
				system("cls||clear");
				menu(exoticos,tamanho,erro);
				}
			else if(resposta == 2){
				exit(2);
				}
			else{
				erro = true;
				}
			}
		}
	else if(n==6){ //deletar dados
		resposta  = 0;
		exoticos = Delete(exoticos,tamanho,erro);
		system ("cls||clear");
		cout << "Dado excluido com sucesso!" << endl;
		cout << endl;
		cout << "Deseja voltar ao menu principal?"<< endl;
		cout << "1 - Sim" << endl;
		cout << "2 - Nao" << endl;
		cin >> resposta;
		if (resposta == 1){
			system("cls||clear");
			menu(exoticos,tamanho,erro);
			}
		else if (resposta == 2){
			exit(2);
			}
		else {
			erro = true;
			}
		}
	else if(n==7){ // importar e exportar binario
		resposta = 0;
		system("cls||clear");
		cout << "Deseja importar ou exportar  ? " << endl;
		cout << "1 - Importar" << endl;
		cout << "2 - Exportar" << endl;
		cin >> resposta;
		if (resposta == 1){
			ifstream arquivo("animais");
			
			animaiss2* exoticos2 = new animaiss2[tamanho];
			arquivo.read((char *) (exoticos2), sizeof(animaiss2)*tamanho);
			arquivo.close();
			for(int i=0; i<tamanho; i++){
				exoticos[i].identificador = exoticos2[i].identificador;
				exoticos[i].classe = exoticos2[i].classe;
				exoticos[i].nome = exoticos2[i].nome;
				exoticos[i].vida = exoticos2[i].vida;
				exoticos[i].pais = exoticos2[i].pais;
			}
			delete[] exoticos2;
				
			system("cls||clear");
			
			cout << "Arquivo binario lido com sucesso!" << endl << endl;
			cout << "Deseja voltar ao menu principal?"<< endl;
			cout << "1 - Sim" << endl;
			cout << "2 - Nao" << endl;
			cin >> resposta;
			if (resposta == 1){
				system("cls||clear");
				menu(exoticos,tamanho,erro);
				}
			else if (resposta == 2){
				exit(2);
				}
			else {
				erro = true;
				}
			}
				
		else if(resposta == 2){
			animaiss2 *exoticos2 = new animaiss2[tamanho];
			for (int i =0;i<tamanho;i++){
				exoticos2[i].identificador = exoticos[i].identificador;
				strncpy(exoticos2[i].nome,exoticos[i].nome.c_str(),49);
				strncpy(exoticos2[i].pais,exoticos[i].pais.c_str(),49);
				strncpy(exoticos2[i].classe,exoticos[i].classe.c_str(),49);
				exoticos2[i].vida = exoticos[i].vida;
				}
			ofstream arqBinary("animais");
			arqBinary.write((const char*) (exoticos2), sizeof(animaiss2)*tamanho);
			arqBinary.close();
			
			system("cls||clear");
			cout << "Arquivo binario escrito com sucesso!" << endl << endl;
			cout << "Deseja voltar ao menu principal?"<< endl;
			cout << "1 - Sim" << endl;
			cout << "2 - Nao" << endl;
			cin >> resposta;
			if (resposta == 1){
				system("cls||clear");
				menu(exoticos,tamanho,erro);
				}
			else if (resposta == 2){
				exit(2);
				}
			else {
				erro = true;
				}
			}
			else {
				erro = true;
				}
		}
	else if(n==8){ //importar e exportar csv
		string nome;
		resposta =0;
		cout << "Deseja importar ou exportar um arquivo CSV ?" << endl;
		cout << "1 - Importar"<< endl;
		cout << "2 - Exportar"<<endl;
		cin >> resposta;
		if(resposta == 1){	
			system("cls||clear");
			delete[] exoticos;
			cout <<"Digite o nome do arquivo CSV: ";
			cin >> nome;
			ifstream arquivo(nome);
			string linha;
			getline(arquivo,linha);
			exoticos = leitura(arquivo,exoticos,tamanho);
			
			system("cls||clear");
			cout << "Dados importados com sucesso!";
			cout << endl<< endl;
			cout << "Deseja voltar ao menu principal?"<< endl;
			cout << "1 - Sim" << endl;
			cout << "2 - Nao" << endl;
			cin >> resposta;
			
			if (resposta == 1){
				system("cls||clear");
				menu(exoticos,tamanho,erro);
				}
			else if (resposta == 2){
				exit(2);
				}
			else {
				erro = true;
				}
		}
		
		else if(resposta ==2){
			system("cls||clear");
			cout <<"Digite o nome do arquivo CSV: ";
			cin >> nome;
			ofstream saida(nome);
			salvarArquivo(saida,exoticos,tamanho);
			saida.close();
			system("cls||clear");
			cout <<"Dados exportados com sucesso!";
			cout << endl<< endl;
			cout << "Deseja voltar ao menu principal?"<< endl;
			cout << "1 - Sim" << endl;
			cout << "2 - Nao" << endl;
			cin >> resposta;
			
			if (resposta == 1){
				system("cls||clear");
				menu(exoticos,tamanho,erro);
				}
			else if (resposta == 2){
				exit(2);
				}
			else {
				erro = true;
				}
		}
		else{
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
		
	exoticos = leitura(arquivo,exoticos,tamanho);
	arquivo.close();
	menu(exoticos,tamanho,erro);
	
	int resposta;
	while(erro == true){ //repetiçao do erro
		system("cls||clear");
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
			system("cls||clear");
		}
	}
	return 0;
}
