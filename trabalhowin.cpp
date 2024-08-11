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
