

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

bool Validar_Letras(char texto[]);
void Cargar_Datos(int cantidad_Choferes, char infochoferes[][9][50]);
bool validar_cuil(char cuil[]);
bool Validar_Letras(char texto[]);
bool validarNumero(char tipo[]);
void calsalario(char choferes[][9][50], int cantidad);
void Ordenamiento(char infochoferes[][9][50],int tipo, int cantidad);
void estadisticas_Choferes(char infochoferes[][9][50],int cantidad_Choferes);
void listaChoferesPromedio(char infochoferes[][9][50],int cantidad_Choferes);
void BuscarChofer(char infochoferes[][9][50],int cantidad_chorferes);
bool existeCuil(char cuil[], int cantidad_Choferes, char infoChoferes[][9][50]);

int main(){
    int cantidadDecimal=0,opcion;
    char cantidadTipoCaracter[50];
    bool hay_letras=false;
    int cantidadChoferes=0;
    printf("Bienvenido a EL CORRECAMINOS \n");
    printf("Ingrese la cantidad de choferes \n");

    do
    {
        
        scanf("%s", cantidadTipoCaracter);
        hay_letras = validarNumero(cantidadTipoCaracter);
        
        if (!hay_letras) {
        cantidadDecimal = atoi(cantidadTipoCaracter);
        
        if (cantidadDecimal <= 1){
            printf("Debe ingresar al menos 2 choferes");
        }  }
        
        
        
    
        } while (hay_letras==true || cantidadDecimal <=1 );
    
    cantidadChoferes= cantidadDecimal;
    char infoChoferes[cantidadChoferes][9][50];
    Cargar_Datos(cantidadChoferes,infoChoferes);
    do
    {
        printf("SELECCIONE:\n1-Ordenar por apellido y nombre.\n2-Ordenar por cuil.\n3-Ordenar por kilometros recorridos.\n");
        printf("4-Choferes con su sueldo.\n5-Buscar choferes.\n6-Promedio kilometros recorridos.\n7-Estadisticas.\n8-Salir.\n");
        scanf("%d",&opcion);

    switch (opcion)
    {
    case 1:
        Ordenamiento(infoChoferes,1,cantidadChoferes);
        break;
    case 2:
        Ordenamiento(infoChoferes,0,cantidadChoferes);
        break;
    case 3:
        Ordenamiento(infoChoferes,8,cantidadChoferes);
        break;
    case 4:
        calsalario(infoChoferes,cantidadChoferes);
        break;
    case 5:
        BuscarChofer(infoChoferes,cantidadChoferes);
        break;
    case 6:
        listaChoferesPromedio(infoChoferes,cantidadChoferes);
        break;
    case 7:
        estadisticas_Choferes(infoChoferes,cantidadChoferes);
        break;
    case 8:
        printf("Gracias por usar nuestro sofware.");
        break;
    default:
        break;
    }



    } while (opcion!=8);
    
}

void Cargar_Datos(int cantidad_Choferes, char infochoferes[][9][50]){
        bool validacion_cuil = false;
        bool Hay_numeros = false;
        bool Hay_Letras = false;
        bool existe_cuil = false;
        int contadorCuils=0;
        int sumakm;


    for (int i = 0; i < cantidad_Choferes; i++){
        sumakm = 0;
        for (int j = 0; j < 9; j++)
        {
            switch (j)
            {
            case 0:
                do
                {
                    printf("Ingrese el cuil del chofer nro %d:\n", i+1);
                    scanf("%s", infochoferes[i][j]);
                    validacion_cuil = validar_cuil(infochoferes[i][j]);

                    if (validacion_cuil==false)
                    {
                        printf("Error al ingresar el cuil. Por favor vuelve a ingresar \n");
                    } else{
                        if (contadorCuils>=1)
                    {
                        existe_cuil = existeCuil(infochoferes[i][j] ,i, infochoferes);
                    } else {
                        existe_cuil=false;
                    }
                    }

                    
                    

                } while (!validacion_cuil || existe_cuil);
                contadorCuils++; 
                break;
            case 1:
                do
                {
                    printf("Ingrese el apellido del chofer nro %d:\n", i+1);
                    scanf("%s",infochoferes[i][j]);
                    Hay_numeros = Validar_Letras(infochoferes[i][j]);
                    
                    
                } while (Hay_numeros==true);                
                break;
            case 2:
                do
                {
                    printf("Ingrese el nombre del chofer nro %d:\n", i+1);
                    scanf("%s",infochoferes[i][j]);
                    Hay_numeros = Validar_Letras(infochoferes[i][j]);
                    
                } while (Hay_numeros==true);
                break;
            case 3:
                do
                    {
                    printf("Ingrese km Dia Lunes:\n");
                    scanf("%s", infochoferes[i][j]);

                    Hay_Letras = validarNumero(infochoferes[i][j]);

                    
                    
                        if (atoi(infochoferes[i][j])>1000 || atoi(infochoferes[i][j])<0) {
                            printf("Error! Cantidad de KM debe ser mayor a 0 y menor a 1000.\n");
                        }   
                    
                } while (Hay_Letras==true || atoi(infochoferes[i][j]) > 1000 || atoi(infochoferes[i][j])<0);
                sumakm += atoi(infochoferes[i][j]);
                break;
                
            case 4:
                do
                    {
                    printf("Ingrese km Dia martes:\n");
                    scanf("%s", infochoferes[i][j]);

                    Hay_Letras = validarNumero(infochoferes[i][j]);


                    
                        if (atoi(infochoferes[i][j])>1000 || atoi(infochoferes[i][j])<0) {
                            printf("Error! Cantidad de KM debe ser mayor a 0 y menor a 1000.\n");
                        }   
                    
                } while (Hay_Letras==true || atoi(infochoferes[i][j]) > 1000 || atoi(infochoferes[i][j])<0);
                sumakm += atoi(infochoferes[i][j]);
                break;
                
            case 5:
                do
                    {
                    printf("Ingrese km Dia miercoles:\n");
                    scanf("%s", infochoferes[i][j]);

                    Hay_Letras = validarNumero(infochoferes[i][j]);

                    
                        if (atoi(infochoferes[i][j])>1000 || atoi(infochoferes[i][j])<0) {
                            printf("Error! Cantidad de KM debe ser mayor a 0 y menor a 1000.\n");
                        }   
                    
                } while (Hay_Letras==true || atoi(infochoferes[i][j]) > 1000 || atoi(infochoferes[i][j])<0);
                sumakm += atoi(infochoferes[i][j]);
                break;
                
            case 6:
                do
                    {
                    printf("Ingrese km Dia jueves:\n");
                    scanf("%s", infochoferes[i][j]);

                    Hay_Letras = validarNumero(infochoferes[i][j]);

                    
                    
                    
                        if (atoi(infochoferes[i][j])>1000 || atoi(infochoferes[i][j])<0) {
                            printf("Error! Cantidad de KM debe ser mayor a 0 y menor a 1000.\n");
                        }   
                    
                } while (Hay_Letras==true || atoi(infochoferes[i][j]) > 1000 || atoi(infochoferes[i][j])<0);
                sumakm += atoi(infochoferes[i][j]);
                break;
                
            case 7:
                do
                    {
                    printf("Ingrese km Dia viernes:\n");
                    scanf("%s", infochoferes[i][j]);

                    Hay_Letras = validarNumero(infochoferes[i][j]);

                    
                        if (atoi(infochoferes[i][j])>1000 || atoi(infochoferes[i][j])<0) {
                            printf("Error! Cantidad de KM debe ser mayor a 0 y menor a 1000.\n");
                        }   
                    
                } while (Hay_Letras==true || atoi(infochoferes[i][j]) > 1000 || atoi(infochoferes[i][j])<0);
                sumakm += atoi(infochoferes[i][j]);
                break;
                
            case 8:
                sprintf(infochoferes[i][j],"%d",sumakm);
                break;
            default:
                    printf("error");
                break;
            }
        }
        
    }
}

bool validar_cuil(char cuil[]) {
    int cantidad = strlen(cuil);
    bool valido = false;
    bool hay_letras = false;

    hay_letras = validarNumero(cuil);


    if (hay_letras) {
        printf("No se pueden ingresar letras.\n");
        valido = false;

    } else {
        // aca tambien deberiamos corregir el metodo de comparacion que no sea de strings, pero es funcional de momento
        if (cantidad >= 10 && cantidad <= 11) {
            if (cuil[0] == '2') {
                if (cuil[1] == '0' || cuil[1] == '3' || cuil[1] == '4' || cuil[1] == '5' || cuil[1] == '6' || cuil[1] == '7') {
                    valido = true;
                }
            }
        }
    }



    

    return valido;
}
bool Validar_Letras(char texto[]){
    int cantidad;
    bool hay_numeros;
    cantidad = strlen(texto);
    

    for(int i = 0; i <cantidad; i ++){ 
        if (texto[i] >= '0' && texto[i] <= '9') // Ahi verifica bien todo es la unica forma que encontre, (Aclaro porque en un comentario decia que miguelo no le gustaba validarlo asi, no se si se refereria solo el de validar numeros)
        {
            hay_numeros=true;
            
        }
        
        
    }
    

    if (hay_numeros)
    {
        printf("No se pueden ingresar numeros \n");
    } 

    return hay_numeros;

}



bool validarNumero(char tipo[]) {
    int cantidad;
    bool hay_letras=false;

    cantidad = strlen(tipo);

    for (int i = 0; i <cantidad ; i++)
    {
        if (tipo[i] < '0' || tipo[i] > '9') // <-- para asi poder comparar con numeros enteros 
        {
            hay_letras= true;
            
        }
        
    }

    if (hay_letras)
    {
        printf("No se pueden ingrear letras y/o numeros negativos, Vuelve a intentarlo\n");
    } 

    return hay_letras;    

    
    
}

void calsalario(char infochoferes[][9][50], int cantidad){
    int Monto_Por_KM;
    char monto[50];
    int Monto_Total_Apagar = 0;
    bool hay_letra = true;

    do
    {
        printf("Ingrese el pago por hora:\n");
        scanf("%s",monto);


        hay_letra = validarNumero(monto);

        if (!hay_letra)
        {
            Monto_Por_KM = atoi(monto);
        if (Monto_Por_KM < 1)
            {
                printf("El pago debe ser mayor a 1 \n");
            }
        }
        
        

    } while (Monto_Por_KM < 1);
    for (int i = 0; i < cantidad; i++)
    {
        printf("Apellido: %s\nNombre: %s\nCuil: %s\nKm Totales: %s\nSalario: $%d \n****************\n",infochoferes[i][1],infochoferes[i][2],infochoferes[i][0],infochoferes[i][8],atoi(infochoferes[i][8]) * Monto_Por_KM);
        Monto_Total_Apagar += atoi(infochoferes[i][8]) * Monto_Por_KM; 
    }
    printf("El monto total a pagar es de: $ %d\n",Monto_Total_Apagar);
    
}

void Ordenamiento(char choferes[][9][50], int tipo, int cantidad) {
    char aux[50];
    int posicion;

    for (int i = 0; i < cantidad - 1; i++) {
        posicion = i; 
        for (int j = i + 1; j < cantidad; j++) {
            if (strcmp(choferes[j][tipo], choferes[posicion][tipo]) < 0) {// esto compara muchachos
                posicion = j;
            }
        }
        for (int k = 0; k < 9; k++) {
                strcpy(aux, choferes[i][k]);// y este asigna
                strcpy(choferes[i][k], choferes[posicion][k]);
                strcpy(choferes[posicion][k], aux);
        }
    }
    for (int i = 0; i < cantidad; i++) {
        printf("Apellido: %s\n", choferes[i][1]);
        printf("Nombre: %s\n", choferes[i][2]);
        printf("Cuil: %s\n", choferes[i][0]);
        printf("Km Totales: %s\n", choferes[i][8]);
        printf("*********\n");
    }
}
void estadisticas_Choferes(char infochoferes[][9][50],int cantidad_Choferes){
    char chofer_mas_km[50], chofer_menos_km[50];
    int mayor_km , menos_km, suma;
    char chofer_mayor_promedio[50], chofer_menor_promedio[50];
    float km_mayor_promedio , km_menor_promedio, promedio_total, promedio_individual;
    mayor_km = 0;
	menos_km = 999999;
	km_mayor_promedio = 0;
	km_menor_promedio = 999;
	suma = 0;
    int acumulador=0;
for (int i = 0; i <cantidad_Choferes ; i++)
{
    if (mayor_km < atoi(infochoferes[i][8]))
    {
        mayor_km=atoi(infochoferes[i][8]);
        strcpy(chofer_mas_km,infochoferes[i][1]);
    }
    if (menos_km>atoi(infochoferes[i][8]))
    {
        menos_km=atoi(infochoferes[i][8]);
        strcpy(chofer_menos_km,infochoferes[i][1]);
    }
    promedio_individual=atoi(infochoferes[i][8])/5;
    if (promedio_individual > km_mayor_promedio)
    {
        km_mayor_promedio = promedio_individual;
        strcpy(chofer_mayor_promedio,infochoferes[i][1]);
    }
    if (promedio_individual< km_menor_promedio)
    {
        km_menor_promedio = promedio_individual;
        strcpy(chofer_menor_promedio, infochoferes[i][1]);
    }
    acumulador++;
    suma+=atoi(infochoferes[i][8]);
}

promedio_total=suma/(acumulador*5);
printf("el promedio total: %.2f\n",promedio_total);
printf("Chofer con mas km: %s, con %i KM \n",chofer_mas_km,mayor_km);
printf("Chofer con menos km: %s con %i KM \n",chofer_menos_km,menos_km);
printf("Chofer con mayor promedio: %s con %.2f KM\n",chofer_mayor_promedio,km_mayor_promedio);
printf("Chofer con menor promedio: %s con %.2f KM\n",chofer_menor_promedio,km_menor_promedio);
}

void listaChoferesPromedio(char infochoferes[][9][50],int cantidad_Choferes){
int suma;
float promedio;
for (int i = 0; i < cantidad_Choferes; i++)
{
    suma=0;
    for (int j = 3; j < 8; j++)
    {
        suma+= atoi(infochoferes[i][j]);
    }
    promedio=suma/5;
    printf("*****************\n");
    printf("Cuil: %s\n",infochoferes[i][0]);
    printf("Apellido: %s\n",infochoferes[i][1]);
    printf("Nombre: %s\n",infochoferes[i][2]);
    printf("Promedio de kilometros recorridos: %.2f\n",promedio);
}
}

void BuscarChofer(char infochoferes[][9][50],int cantidad_chorferes){
char cuil[30];
bool existeChofer;
bool validacion_cuil = false;

int cantidad_cuil;
existeChofer=false;
do
{
    printf("ingrese el cuil: \n");
    scanf("%s",cuil);

    validacion_cuil = validar_cuil(cuil);

    if (!validacion_cuil)
    {
        printf("Error al ingresar el cuil. Por favor vuelve a ingresar \n");
    }
    
    cantidad_cuil=strlen(cuil);
    if (cantidad_cuil < 10 || cantidad_cuil > 11)
    {
        printf("El cuil ingresado no es valido\n");
    }

} while (cantidad_cuil < 10 || cantidad_cuil > 11 || !validacion_cuil);


for (int i = 0; i < cantidad_chorferes ; i++)
{
    if (strcmp(cuil,infochoferes[i][0])==0)
    {
        existeChofer=true;
        printf("Cuil: %s\n",cuil);
        printf("Apellido: %s\n",infochoferes[i][1]);
        printf("Nombre: %s\n",infochoferes[i][2]);
        printf("Dia Lunes: %s KM\nDia Martes: %s KM\nDia Miercoles: %s KM\n",infochoferes[i][3],infochoferes[i][4],infochoferes[i][5]);
        printf("Dia Jueves: %s KM\nDia Viernes: %s KM\n",infochoferes[i][6],infochoferes[i][7]);
        printf("Kilometros totales: %s\n",infochoferes[i][8]);
    }
    }
    if (existeChofer==false)
    {
        printf("El Chofer no fue encontrado.\n");
    }
    
}


bool existeCuil(char cuil[], int cantidad_Choferes, char infoChoferes[][9][50] ) {
    
    bool existe_cuil= false;
        
        for (int i = 0; i < cantidad_Choferes; i++){
            if (strcmp(cuil, infoChoferes[i][0])==0) {
                existe_cuil=true;
            }
        
    }
    
    if (existe_cuil)
    {
        printf("Este cuil ya existe, vuelve a intentarlo\n");
    }

    return existe_cuil;
}
