#include <stdio.h> 

#define MAX 20000

int len (char vet[]){
	int i;
	for (i=0;vet[i];i++);
	return (i);
}

int limpa_string(char string[]){//RETIRA CARACTERES INVALIDOS 
	int i,j;

	for(i=0;i<len(string);i++){
		if (((string[i]<65)||(string[i]>90)) && ((string[i]<97)||(string[i]>122))){
			for(j=i;j<len(string);j++){
				string[j]=string[j+1];
			}
			i--;
		} 
	}
	return(1);
}

int upper(char string[]){//TRANSFORMA EM MAIUSCULA
	int i;

	for(i=0;i<len(string);i++){
		if((string[i]>=97)&&(string[i]<=122)) {
			string[i]=string[i]-32;
		}
	} 
	return(1);
}

int lower(char string[]){//TRANSFORMA EM MINUSCULA
	int i;

	for(i=0;i<len(string);i++){
		if((string[i]>=65)&&(string[i]<=90)) {
			string[i]=string[i]+32;
		}
	} 
	return(1);
}
int cifrar(char fFrase[]){
	int cars_dig,i;
	
	cars_dig=len(fFrase)-1; //Variavel armazena numero de caracteres antes das alterações :), -1 para tirar enter
	limpa_string(fFrase);
	
	upper(fFrase);
	
	printf("# modo cifragem ativado\n");
	for(i=0;fFrase[i]!=0;i++){
		if(fFrase[i]+3 > 90){
			fFrase[i]= fFrase[i]-26;
		}
		fFrase[i]=fFrase[i]+3;
		
		if(i==0){
			printf("$%c",fFrase[i]);	
		}else{
			printf("%c",fFrase[i]);
		}	
	}
	printf("\n%i CARS DIGITADOS",cars_dig);
	
	return(1);
}

int decifrar(char fFrase[]){
	int cars_dig;
	int i= 0;
	cars_dig = len(fFrase)-1;
	lower(fFrase);
	
	printf("# modo decifragem ativado\n");
	
	for(i=0;fFrase[i]!=0;i++){
		if(fFrase[i]-3 < 65){
			fFrase[i]= fFrase[i]+25;
		}
		fFrase[i]=fFrase[i]-3;
		if(i==0){
			printf("$%c",fFrase[i]);	
		}else{
			printf("%c",fFrase[i]);
		}	
	}
	printf("\n %i CARS DIGITADOS",cars_dig);
	
}
	

int main( int argc, char *argv[ ] ){

	int Qtd_strings, i;
	char frases[1][MAX];
	
	if(1==1) { // FALTA VALIDAR OQUE CHEGA NO MAIN
		printf("# Quantas frases voce quer digitar?\n");
		scanf("%i",&Qtd_strings);
		
		while(!(Qtd_strings > 0)){
			printf("# Quantas frases voce quer digitar?\n");
		}
	} else{
		Qtd_strings= *argv[1];
	}

	printf("# Digite %i frases com ate 20000 cars para cifrar ou decifrar.\n# Insira '$' no inicio se for para decifrar:\n",Qtd_strings); //VERIFICA EM QUAL ESTADO A STRING ESTÁ E DIRECIONA PARA A FUNÇÃO CORRESPONDENTE 
	for(i=0;i<Qtd_strings;i++){
		do{
			fgets(frases[i],MAX,stdin);
		}while(len(frases[i])<2);
		
		if (frases[1][0]!='$'){
			cifrar(frases[i]);//deve ser cifrar
		}else{
			decifrar(frases[i]);
		}
	}
	system("pause");
return(0);
}



