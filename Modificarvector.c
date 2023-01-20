#include <stdio.h>

int main(){

    FILE *archivo=NULL;
    FILE *archivo1=NULL;
    int a;

    archivo=fopen("vector.txt","r");
    archivo1=fopen("vectorNUEVO.txt","w");

    if (archivo==NULL){
        printf("No se puede abrir el archivo");
        return -1;
    }
    if (archivo1==NULL){
        printf("No se puede abrir el archivo");
        return -1;
    }

    while (!feof(archivo)){
        fscanf(archivo,"%d",&a);
        if(a%10==0){
            fprintf(archivo1,"Es multiplo de 10\n");
        }else{
            fprintf(archivo1,"%d\n",a);
        }
    
    
    }
    

     fclose(archivo);
     fclose(archivo1);
     return 0;
}