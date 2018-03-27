
#include <stdio.h>

#define MAX 100

int len(char str1[]){
	int i = 0;
	for(i; str1[i]!=0;i++);//se for zero é falso (significa que a string terminou,pois fica alocado 8bits em zero), se for falso sai do laço

	return i;
}
int compara(char str1[],char str2[]){
	int i;
	int igualdade;
	int tam1 = len(str1);
	int tam2 = len(str2);
	
	if(tam1 > tam2){
	    for (i = 0; i < tam1 ; i++){
		    //str1[i] = str2[i];
		    if(str1[i]==str2[i]){
			    igualdade = 0;
		    }else if(str1[i]<str2[i]){
			    igualdade = -1;
		    }else{
    		    igualdade = 1;
	    	}
	    }
    }else{
        for (i = 0; i < tam2 ; i++){
		    //str1[i] = str2[i];
		    if(str1[i]==str2[i]){
			    igualdade = 0;
		    }else if(str1[i]<str2[i]){
			    igualdade = -1;
		    }else{
    		    igualdade = 1;
	    	}
        }
	}
	return igualdade;
}
int main (){
	char str1[100] = "";
	char str2[100] = "ola125567";
	
	printf("%i",compara(str1,str2));
}