#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"


/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int main()
{
    int option = 0;
    int archivoCargado = 0;

    LinkedList* listaEmpleados = ll_newLinkedList();
    printf("                            ---------------------\n"
           "                              ***BIENVENIDO***\n"
           "                            ---------------------\n");

    do
    {


        printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).");
        printf("\n2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).");
        printf("\n3. Alta de empleado");
        printf("\n4. Modificar datos de empleado");
        printf("\n5. Baja de empleado");
        printf("\n6. Listar empleados");
        printf("\n7. Ordenar empleados");
        printf("\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto).");
        printf("\n9. Guardar los datos de los empleados en el archivo data.csv (modo binario).");
        printf("\n10. Salir");
        printf("\nIngrese una opcion: \n");
        scanf("%d", &option);

        switch(option)
        {
        case 1:
            if(archivoCargado == 0)
            {
                controller_loadFromText("data.csv",listaEmpleados);
                archivoCargado = 1;
            }
            else
            {
                printf("|-----------------------------------------|\n"
                       "     Usted ya a cargado el archivo!!\n"
                       "|-----------------------------------------|\n\n");
            }
            break;
        case 2:

            break;
        case 3:
            if(archivoCargado == 1)
            {
                controller_addEmployee(listaEmpleados);
            }
            else
            {
                 printf("|-----------------------------------------|\n"
                       "   Por favor, cargue un archivo primero!!\n"
                       "|-----------------------------------------|\n\n");
            }
            break;
        case 4:
            if(archivoCargado == 1)
            {
                controller_editEmployee(listaEmpleados);
            }
            else
            {
                printf("|-----------------------------------------|\n"
                       "   Por favor, cargue un archivo primero!!\n"
                       "|-----------------------------------------|\n\n");
            }
            break;
        case 5:
            if(archivoCargado == 1)
            {
                controller_removeEmployee(listaEmpleados);
            }
            else
            {
                printf("|-----------------------------------------|\n"
                       "   Por favor, cargue un archivo primero!!\n"
                       "|-----------------------------------------|\n\n");
            }
            break;
        case 6:
            if(archivoCargado == 1)
            {
                controller_ListEmployee(listaEmpleados);
            }
            else
            {
                printf("|-----------------------------------------|\n"
                       "   Por favor, cargue un archivo primero!!\n"
                       "|-----------------------------------------|\n\n");
            }
            break;
        case 7:
            if(archivoCargado == 1)
            {
                controller_sortEmployee(listaEmpleados);
            }
            else
            {
                printf("|-----------------------------------------|\n"
                       "   Por favor, cargue un archivo primero!!\n"
                       "|-----------------------------------------|\n\n");
            }
            break;
        case 8:
            controller_saveAsText("otraData.csv", listaEmpleados);
            break;
        case 9:
            controller_saveAsBinary("otraData.bin", listaEmpleados);
            break;
        case 10:
             printf("                         ---------------------------\n"
           "                           ***TENGA UN BUEN DIA***\n"
           "                         ---------------------------\n");
            break;
        default:
            printf("Opcion incorrecta, por favor elejir teclas del 1 al 9 \n\n");

        }
    }
    while(option != 10);
    return 0;
}
