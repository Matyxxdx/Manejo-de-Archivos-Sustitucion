#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
   char nombre[30];
   char apellido[30];
   int edad;
   int telefono;
   char motivo[100];
   char fecha[11];
   char hora[6];
   char ciudad[15];
} cita;

int cont_citas=0;

void leer_cita(cita *c) {
    printf("\nA continuacion por favor llene los datos del paciente:\n");
   printf("Nombre: ");
   scanf("%s", c->nombre);
   printf("Apellido: ");
   scanf("%s", c->apellido);
   printf("Edad: ");
   scanf("%d", &c->edad);
   printf("Teléfono: ");
   scanf("%d", &c->telefono);
   printf("Motivo de la cita\n(consulta, rehabilitación o cirujía): ");
   scanf("%s", c->motivo);
   printf("Fecha (AAAA-MM-DD): ");
   scanf("%s", c->fecha);
   printf("Hora (HH:MM): ");
   scanf("%s", c->hora);
   printf("Ciudad: ");
   scanf("%s", c->ciudad);
   cont_citas++;
   
}

void guardar_cita(cita c) {
   FILE *fp;
   fp = fopen("agendamientocitas.txt", "a");
   fprintf(fp, "Paciente: %s %s\nEdad: %d\nContacto: %d\nMotivo de la cita: %s\nFecha agendada: %s\nHora de la cita: %s\nCiudad: %s \n\n", c.apellido, c.nombre, c.edad, c.telefono, c.motivo, c.fecha, c.hora, c.ciudad);
   fclose(fp);
   printf("\nCita guardada correctamente\n");
}

int main() {
    cita c;
    int opcion;
    
    do{
        printf("****BIENVENIDO Usuario****\nFundacion Salud para Todos\n");
        printf("\nSistema de agendamiento de citas\nA continuacion escoja la opcion a ejecutar\n");
        printf("Hay %d citas registradas\n", cont_citas);
        printf("1.- Agregar cita\n");
        printf("2.- Mostrar citas\n");
        printf("3.- Salir\n");
        printf("Introduce una opcion: ");
        scanf("%d", &opcion);

        switch(opcion){
            case 1:
                leer_cita(&c);
                guardar_cita(c);
                break;
            case 2:
                if (cont_citas>0){
                char buffer[100];
                FILE *fp;
                fp = fopen("agendamientocitas.txt", "r");
                printf("\n");

                while(!feof(fp)){
                    fgets(buffer,100,fp);
                    printf("%s",buffer);
                }
                fclose(fp);
                break;
                }
                else{
                    printf("\nNo hay citas registradas.\t\n");
                }
                break;
            default:
                printf("Opcion no valida\n");
                break;
        }
    }while(opcion != 3);

    return 0;
