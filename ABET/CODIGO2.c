#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
   char nombre[30];
   char apellido[30];
   int edad;
   int telefono;
   char fecha[11];
   char hora[6];
   char ciudad[15];
} cita;

void leer_cita(cita *c) {
   printf("Primer Nombre: ");
   scanf("%s", c->nombre);
   printf("Primer Apellido: ");
   scanf("%s", c->apellido);
   printf("Edad: ");
   scanf("%d", &c->edad);
   printf("Teléfono: ");
   scanf("%d", &c->telefono);
   printf("Fecha (AAAA-MM-DD): ");
   scanf("%s", c->fecha);
   printf("Hora (HH:MM): ");
   scanf("%s", c->hora);
   printf("Ciudad: ");
   scanf("%s", c->ciudad);
   
}

void guardar_cita(cita c) {
   FILE *fp;
   fp = fopen("citas.txt", "a");
   fprintf(fp, "Paciente: %s %s\nEdad: %d\nContacto: %d\nFecha agendada: %s\nHora de la cita: %s\nCiudad: %s \n\n", c.apellido, c.nombre, c.edad, c.telefono, c.fecha, c.hora, c.ciudad);
   fclose(fp);
   printf("Cita guardada correctamente\n");
}

int main() {
   cita c;
   leer_cita(&c);
   guardar_cita(c);
   return 0;
}