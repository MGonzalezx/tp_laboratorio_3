#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"



/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    ultimoIdEmployee = 0;
    FILE* data;
    data = fopen (path, "r");
    if(data == NULL)
    {
        printf("No se pudo leer el archivo\n");

    }
    else
    {
        parser_EmployeeFromText(data,pArrayListEmployee);
        fclose(data);
        printf("|-----------------------------------------|\n"
               "   Su archivo a sido cargado exitosamente!\n"
               "|-----------------------------------------|\n\n");
    }
    return 1;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{

    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    if(pArrayListEmployee != NULL)
    {


        char buffer[1024];
        Employee* miEmpleado = employee_new();
        printf("\nIngrese Nombre: ");
        fflush(stdin);
        gets(buffer);
        while(strlen(buffer)>128 ||!esSoloLetras(buffer))
        {
            printf("-----------------------------------------------------------\n"
                   "                   Reingrese Nombre: "
                   "-----------------------------------------------------------\n\n");
            fflush(stdin);
            gets(buffer);
        }
        strcpy(miEmpleado->nombre, buffer);

        printf("\nIngrese Horas trabajadas: ");
        scanf("%d", &miEmpleado->horasTrabajadas);

        while(miEmpleado->horasTrabajadas < 50 || miEmpleado->horasTrabajadas > 200)
        {
            printf("-----------------------------------------------------------\n"
                   "        Error! Ingrese horas entre 50 y 200: "
                   "-----------------------------------------------------------\n\n");
            scanf("%d", &miEmpleado->horasTrabajadas);
        }
        printf("\nIngrese sueldo: ");
        scanf("%d", &miEmpleado->sueldo);
        while(miEmpleado->sueldo < 8000 || miEmpleado->sueldo > 1000000)
        {
            printf("-----------------------------------------------------------\n"
                   "       Error! Ingrese sueldo entre 8000 y 1000000: "
                   "-----------------------------------------------------------\n\n");
            scanf("%d", &miEmpleado->sueldo);
        }
        miEmpleado->id = ultimoID();
        ll_add(pArrayListEmployee, miEmpleado);


    }
    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee,char* path)
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
    char opcion;
    int index;
    int flag=0;
    int idBuscar;
    Employee* employee = NULL;

    if(pArrayListEmployee != NULL)
    {
        printf("Ingrese ID del empleado que desea modificar: ");
        scanf("%d",&idBuscar);
        for(index=0; index<ll_len(pArrayListEmployee); index++)
        {
            employee = ll_get(pArrayListEmployee,index);

            employee_getId(employee, &id);


            if(id == idBuscar)
            {
                printf("-----------------------------------------------------------\n"
                       "ID del empleado encontrado presione enter para continuar!!\n"
                       "-----------------------------------------------------------\n\n");

                opcion=getche();

                do
                {
                    printf("\n¿Que cambios desea hacer?");
                    printf("\na. Cambiar nombre");
                    printf("\nb. Cambiar horas trabajadas ");
                    printf("\nc. Cambiar sueldo");
                    printf("\nz. Ninguno, salir");
                    printf("\nIngrese una opcion: \n");
                    scanf("%s", &opcion);
                    switch(opcion)
                    {
                    case 'a':
                        printf("\nIngrese el nuevo nombre: ");
                        scanf("%s", nombre);
                        printf("¿Esta seguro que desea modificar el nombre? s=si n=no\n ");
                        opcion=getche();
                        if(opcion=='s')
                        {
                            employee_setNombre(employee, nombre);
                            printf("-----------------------------------------------------------\n"
                                   "                 Nombre modificado!!\n"
                                   "-----------------------------------------------------------\n\n");
                        }
                        else if(opcion=='n')
                        {
                            printf("-----------------------------------------------------------\n"
                                   "              El nombre no fue modificado!!\n"
                                   "-----------------------------------------------------------\n\n");
                        }
                        else
                        {
                            printf("-----------------------------------------------------------\n"
                                   "           Opcion incorrecta, usted volvera al menu!!\n"
                                   "-----------------------------------------------------------\n\n");
                        }
                        break;
                    case 'b':
                        printf("\nIngrese las nuevas horas trabajadas: ");
                        scanf("%d", &horasTrabajadas);

                        printf("¿Esta seguro que desea modificar las horas trabajadas? s=si n=no\n ");
                        opcion=getche();
                        if(opcion=='s')
                        {
                            employee_setHorasTrabajadas(employee, horasTrabajadas);
                            printf("-----------------------------------------------------------\n"
                                   "          Las horas trabajadas fueron modificadas!!\n"
                                   "-----------------------------------------------------------\n\n");
                        }
                        else if(opcion=='n')
                        {
                            printf("-----------------------------------------------------------\n"
                                   "       Las horas trabajadas no fueron modificadas!!\n"
                                   "-----------------------------------------------------------\n\n");
                        }
                        else
                        {
                            printf("-----------------------------------------------------------\n"
                                   "           Opcion incorrecta, usted volvera al menu!!\n"
                                   "-----------------------------------------------------------\n\n");
                        }
                        break;
                    case 'c':
                        printf("\nIngrese el nuevo sueldo: ");
                        scanf("%d", &sueldo);

                        printf("¿Esta seguro que desea modificar el sueldo? s=si n=no\n ");
                        opcion=getche();
                        if(opcion=='s')
                        {
                            employee_setSueldo(employee, sueldo);
                            printf("-----------------------------------------------------------\n"
                                   "                   Sueldo modificado!!\n"
                                   "-----------------------------------------------------------\n\n");
                        }
                        else if(opcion=='n')
                        {
                            printf("-----------------------------------------------------------\n"
                                   "              El sueldo no fue modificado!!\n"
                                   "-----------------------------------------------------------\n\n");
                        }
                        else
                        {
                            printf("-----------------------------------------------------------\n"
                                   "           Opcion incorrecta, usted volvera al menu!!\n"
                                   "-----------------------------------------------------------\n\n");
                        }
                        break;
                    case 'z':
                        break;
                    default:
                        printf("-----------------------------------------------------------\n"
                               "                     Opcion incorrecta!!\n"
                               "-----------------------------------------------------------\n\n");
                    }
                }
                while(opcion !='z');

                flag=1;
                break;


            }
        }
    }

    if(flag==0)
    {
        printf("-----------------------------------------------------------\n"
               "  ID inexistente, usted sera devuelto al menu principal\n"
               "-----------------------------------------------------------\n\n");
        getch();
    }

    FILE* pFile = fopen(path, "w");
    if(pFile != NULL)
    {
        int i;
        for(i=0 ; i < ll_len(pArrayListEmployee); i++)
        {
            Employee* employee =(Employee*)ll_get(pArrayListEmployee,i);
            fprintf(pFile,"%d--%c--%d--%d",employee_getId(employee, &id),employee_getNombre(employee, nombre),
                    employee_getHorasTrabajadas(employee, &horasTrabajadas),employee_getSueldo(employee, &sueldo));
        }

        fclose(pFile);

    }


    return 1;
}




/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int id;
    char opcion;
    int index;
    int flag=0;
    int idBuscar;
    Employee* employee = NULL;

    if(pArrayListEmployee != NULL)
    {
        printf("Ingrese ID del empleado que desea eliminar: ");
        scanf("%d",&idBuscar);
        for(index=0; index<ll_len(pArrayListEmployee); index++)
        {
            employee = ll_get(pArrayListEmployee,index);

            employee_getId(employee, &id);

            if(id == idBuscar)
            {
                printf("ID del employee encontrado!!. ¨Seguro desea dar de baja? s=si n=no\n ");
                opcion=getche();
                if(opcion=='s')
                {
                    employee_delete(employee);
                    ll_remove(pArrayListEmployee, index);
                    printf("-----------------------------------------------------------\n"
                           "                  Employee eliminado!!\n"
                           "-----------------------------------------------------------\n\n");
                }
                else if(opcion=='n')
                {
                    printf("-----------------------------------------------------------\n"
                           "            El employee no fue eliminado!!\n"
                           "-----------------------------------------------------------\n\n");
                }
                else
                {
                    printf("-----------------------------------------------------------\n"
                           "           Opcion incorrecta, usted volvera al menu!!\n"
                           "-----------------------------------------------------------\n\n");
                }
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            printf("-----------------------------------------------------------\n"
                   "  ID inexistente, usted sera devuelto al menu principal\n"
                   "-----------------------------------------------------------\n\n");
            getch();
        }





    }
    return 1;

}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    if(pArrayListEmployee != NULL)
    {
        int i;

        for(i=0; i<ll_len(pArrayListEmployee); i++)
        {printf("%s  %14s  %16s  %6s\n", "Id", "Nombre", "Horas trabajadas", "Sueldo");
            Employee* empleado = (Employee*)ll_get(pArrayListEmployee, i);
            printf("%d         %s        %d         %d\n", empleado->id, empleado->nombre, empleado->horasTrabajadas, empleado->sueldo);

        }
    }
    else
    {
        printf("Error al abrir el archivo\n");
    }

    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int opcion;
    if(pArrayListEmployee != NULL)
    {
        printf("\n¿De que forma desea ordenar la lista?");
        printf("\nPresione ENTER para continuar");


        do
        {
            LinkedList* clonLinkendist = ll_clone(pArrayListEmployee);

            printf("\n1. Por ID (mayor a menor)");
            printf("\n2. Nombre (alfabeticamente)");
            printf("\n3. Sueldo (mayor a menor)");
            printf("\n4. Sueldo (menor a mayor)");
            printf("\n5. Horas trabajadas (mayor a menor)");
            printf("\n6. Horas trabajadas (menor a mayor)");
            printf("\n7. Ninguna, salir");
            printf("\nIngrese una opcion: \n");
            scanf("%d", &opcion);
            switch(opcion)
            {
            case 1:
                printf("---¡Cargando!---");
                ll_sort(clonLinkendist, comparar_ID, 0);
                printf("\nSu lista fue ordenada de mayor a menor segun los ID!!\n\n");
                controller_ListEmployee(clonLinkendist);
                break;
            case 2:
                printf("---¡Cargando!---");
                ll_sort(clonLinkendist, comparar_Nombre, 1);
                printf("\nSu lista fue ordenada alfabeticamente!!\n\n");
                controller_ListEmployee(clonLinkendist);
                break;
            case 3:
                printf("---¡Cargando!---");
                ll_sort(clonLinkendist, comparar_Sueldo, 0);
                printf("\nSu lista fue ordenada de mayor a menor segun los sueldos!!\n\n");
                controller_ListEmployee(clonLinkendist);
                break;
            case 4:
                printf("---¡Cargando!---");
                ll_sort(clonLinkendist, comparar_Sueldo, 1);
                printf("\nSu lista fue ordenada de menor a mayor segun los sueldos!!\n\n");
                controller_ListEmployee(clonLinkendist);
                break;
            case 5:
                printf("---¡Cargando!---");
                ll_sort(clonLinkendist, comparar_HorasTrabajadas, 0);
                printf("\nSu lista fue ordenada de mayor a menor segun las horas trabajadas!!\n\n");
                controller_ListEmployee(clonLinkendist);
                break;
            case 6:
                printf("---¡Cargando!---");
                ll_sort(clonLinkendist, comparar_HorasTrabajadas, 1);
                printf("\nSu lista fue ordenada de menor a mayor segun las horas trabajadas!!\n\n");
                controller_ListEmployee(clonLinkendist);
                break;
            case 7:

                break;
            default:
                printf("\nOpcion incorrecta!!\n\n");
            }
            ll_deleteLinkedList(clonLinkendist);
        }
        while(opcion != 7);


    }

    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    if(path != NULL && pArrayListEmployee != NULL)
    {

        FILE* pFile = fopen(path, "w");
        Employee* employee = NULL;
        int index;
        if(pFile != NULL)
        {
            for(index = 0; index < ll_len(pArrayListEmployee); index++)
            {
                employee = (Employee *)ll_get(pArrayListEmployee, index);
                fprintf(pFile,"%d--%s--%d--%d\n", employee->id, employee->nombre, employee->horasTrabajadas, employee->sueldo);
            }
        }
        fclose(pFile);
        printf("-----------------------------------------------------------\n"
                   "      El archivo fue guardado exitosamente\n"
                   "-----------------------------------------------------------\n\n");
    }
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    if(path != NULL && pArrayListEmployee != NULL)
    {

        FILE* pFile = fopen(path, "wb");
        Employee* employee = NULL;
        int index;
        if(pFile != NULL)
        {
            for(index = 0; index < ll_len(pArrayListEmployee); index++)
            {
                employee = (Employee *)ll_get(pArrayListEmployee, index);
                fwrite(employee, sizeof(Employee), 1, pFile);
            }
        }
        fclose(pFile);
        printf("-----------------------------------------------------------\n"
                   "      El archivo fue guardado exitosamente\n"
                   "-----------------------------------------------------------\n\n");
    }


    return 1;
}
