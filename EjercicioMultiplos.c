#include <stdio.h>

int main(){

//APERTURA DEL ARCHIVO
    FILE *fp=NULL;
    FILE *fp1=NULL;
    int x;

    fp=fopen("vector.txt","r");
    fp1=fopen("Sustitucion.txt","w");

//SI NO ENCUENTRA EL ARCHIVO
    if (fp==NULL){
        printf("No se puede abrir el archivo");
        return -1;
    }
    if (fp1==NULL){
        printf("No se puede abrir el archivo");
        return -1;
    }

//PROCESO
    while (!feof(fp)){
        fscanf(fp,"%d",&x);
        if(x%10==0){
            fprintf(fp1,"%d \tEs multiplo de 10\n",x);
        }else{
            fprintf(fp1,"%d\n",x);
        }
    }
    
//CERRAR ARCHIVO
     fclose(fp);
     fclose(fp1);
     return 0;
}