#include <stdio.h>
#include <string.h>
#define MAX_CITAS 10

struct Cita{
    char nombre[30];
    char apellido[30];
    char lugar[30];
    int hora;
    int minutos;
};

struct Agenda{
    struct Cita cita[MAX_CITAS];
    int num_citas;
};

void inicializar_agenda(struct Agenda * agenda);
void agregar_cita(struct Agenda * agenda);
void buscar_cita(struct Agenda * agenda);
void eliminar_cita(struct Agenda * agenda);
void mostrar_citas(struct Agenda * agenda);


int main(){

    struct Agenda agenda;
    int opcion;
    inicializar_agenda(&agenda);
    
    do{
        printf("\nAgenda de citas\n");
        printf("1.- Agregar cita\n");
        printf("2.- Buscar cita\n");
        printf("3.- Eliminar cita\n");
        printf("4.- Mostrar citas\n");
        printf("5.- Salir\n");
        printf("Introduce una opcion: ");
        scanf("%d", &opcion);

        switch(opcion){
            case 1:
                agregar_cita(&agenda);
                break;
            case 2:
                buscar_cita(&agenda);
                break;
            case 3:
                eliminar_cita(&agenda);
                break;
            case 4:
                mostrar_citas(&agenda);
                break;
            default:
                printf("Opcion no valida\n");
                break;
        }
    }while(opcion != 5);

    
    return 0;
}

void inicializar_agenda(struct Agenda * agenda)
{
    agenda->num_citas = 0;
}

void agregar_cita(struct Agenda * agenda)
{
    FILE *datos;
    datos=fopen("listado.txt","w+");

    int hora, minutos;
    char nombre[30], apellido[30], lugar[30];
    
    if(agenda->num_citas < MAX_CITAS)
    {
        printf("\nNombre: ");
        scanf("%s", nombre);
        printf("Apellido: ");
        scanf("%s", apellido);
        printf("Lugar: ");
        scanf("%s", lugar);
        printf("Hora (formato 24h): ");
        scanf("%d:%d", &hora, &minutos);
        
        strcpy(agenda->cita[agenda->num_citas].nombre, nombre);
        strcpy(agenda->cita[agenda->num_citas].apellido, apellido);
        strcpy(agenda->cita[agenda->num_citas].lugar, lugar);
        agenda->cita[agenda->num_citas].hora = hora;
        agenda->cita[agenda->num_citas].minutos = minutos;
        
        agenda->num_citas++;
    }
    else
    {
        printf("Agenda llena, no se pueden agregar mas citas\n");
    }
    fclose(datos);
}

void buscar_cita(struct Agenda * agenda)
{
    int hora, minutos, i;
    char nombre[30], apellido[30];
    
    printf("\nNombre: ");
    scanf("%s", nombre);
    printf("Apellido: ");
    scanf("%s", apellido);
    printf("Hora (formato 24h): ");
    scanf("%d:%d", &hora, &minutos);
    
    for(i=0; i<agenda->num_citas; i++)
    {
        if(strcmp(nombre, agenda->cita[i].nombre) == 0 &&
           strcmp(apellido, agenda->cita[i].apellido) == 0 &&
           agenda->cita[i].hora == hora &&
           agenda->cita[i].minutos == minutos)
        {
            printf("\nCita encontrada\n");
            printf("Nombre: %s\n", agenda->cita[i].nombre);
            printf("Apellido: %s\n", agenda->cita[i].apellido);
            printf("Lugar: %s\n", agenda->cita[i].lugar);
            printf("Hora: %02d:%02d\n", agenda->cita[i].hora, agenda->cita[i].minutos);
            return;
        }
    }
    
    printf("\nNo se encontro la cita\n");
}

void eliminar_cita(struct Agenda * agenda)
{
    int hora, minutos, i, j;
    char nombre[30], apellido[30];
    
    printf("\nNombre: ");
    scanf("%s", nombre);
    printf("Apellido: ");
    scanf("%s", apellido);
    printf("Hora (formato 24h): ");
    scanf("%d:%d", &hora, &minutos);
    
    for(i=0; i<agenda->num_citas; i++)
    {
        if(strcmp(nombre, agenda->cita[i].nombre) == 0 &&
           strcmp(apellido, agenda->cita[i].apellido) == 0 &&
           agenda->cita[i].hora == hora &&
           agenda->cita[i].minutos == minutos)
        {
            for(j=i; j<agenda->num_citas-1; j++)
            {
                agenda->cita[j] = agenda->cita[j+1];
            }
            
            agenda->num_citas--;
            printf("\nCita eliminada\n");
            return;
        }
    }
    
    printf("\nNo se encontro la cita\n");
}

void mostrar_citas(struct Agenda * agenda)
{
    int i;
    printf("\n");
    for(i=0; i<agenda->num_citas; i++)
    {
        printf("Nombre: %s\n", agenda->cita[i].nombre);
        printf("Apellido: %s\n", agenda->cita[i].apellido);
        printf("Lugar: %s\n", agenda->cita[i].lugar);
        printf("Hora: %02d:%02d\n", agenda->cita[i].hora, agenda->cita[i].minutos);
        printf("\n");
    }
}