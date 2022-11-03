#include <stdio.h>

int main(){
    const int PUERTO_LOG_DEFECTO = 0, PUERTO_SALIDA_DEFECTO = 0;
    int salir = 0, entrada, pila[32], topePila = -1, bitacora[200], 
    topeBitacora = -1, puertoBitacora = PUERTO_LOG_DEFECTO, puertoSalida = PUERTO_SALIDA_DEFECTO, auxA, auxB;
    while (!salir)
    {   
        scanf("%X", &entrada);
        topeBitacora++;
        bitacora[topeBitacora] = 0;
        topeBitacora++;
        bitacora[topeBitacora] = entrada;
        
        switch (entrada)
        {
        case 0x01:
            scanf("%X", &entrada);
            topeBitacora++;
            bitacora[topeBitacora] = entrada;
            if (topePila==31)
            {
                topeBitacora++;
                bitacora[topeBitacora] = 0x04;
            }else{
                topePila++;
                pila[topePila] = entrada;
                topeBitacora++;
                bitacora[topeBitacora] = 0x10;
            }
            break;

        case 0x02:
            scanf("%X", &entrada);
            puertoSalida = entrada;
            topeBitacora++;
            bitacora[topeBitacora] = entrada;
            topeBitacora++;
            bitacora[topeBitacora] = 0x10;
            break;

        case 0x03:
            scanf("%X", &entrada);
            puertoBitacora = entrada;
            topeBitacora++;
            bitacora[topeBitacora] = entrada;
            topeBitacora++;
            bitacora[topeBitacora] = 0x10;
            break;

        case 0x04:
            entrada = pila[topePila];
            topeBitacora++;
            bitacora[topeBitacora] = 0x10;
            break;

        case 0x05:
            /* code */
            break;

        case 0x06:
            if (topePila==31)
            {
                topeBitacora++;
                bitacora[topeBitacora] = 0x04;
            }else{
                if (topePila==-1)
                {
                    topeBitacora++;
                    bitacora[topeBitacora] = 0x08;
                }else{
                    pila[topePila+1] = pila[topePila];
                    topePila++;
                    topeBitacora++;
                    bitacora[topeBitacora] = 0x10;
                }
            }
            break;

        case 0x07:
            if (topePila<1)
            {
                topeBitacora++;
                bitacora[topeBitacora] = 0x08;
            }else{
                auxA=pila[topePila];
                pila[topePila]=pila[topePila-1];
                pila[topePila-1]=auxA;
                topeBitacora++;
                bitacora[topeBitacora] = 0x10;
            }
            break;

        case 0x08:
            if (topePila==-1)
            {
                topeBitacora++;
                bitacora[topeBitacora] = 0x08;
            }else{
                pila[topePila]=-pila[topePila];
                topeBitacora++;
                bitacora[topeBitacora] = 0x10;
            }
            break;

        case 0x09:
            if (topePila==-1)
            {
                topeBitacora++;
                bitacora[topeBitacora] = 0x08;
            }else{
                auxA = pila[topePila];
                auxB = 1;
                for (int i = 1; i <= auxA; i++)
                {
                    auxB=auxB*i;
                }
                pila[topePila]=auxB;
                topeBitacora++;
                bitacora[topeBitacora] = 0x10;
            }
            break;

        case 0x0A:
            auxA = 0;
            for (int i = 0; i <= topePila; i++)
            {
                auxA=auxA+pila[i];
            }
            pila[0]=auxA;
            topePila=0;
            topeBitacora++;
            bitacora[topeBitacora] = 0x10;
            break;

        case 0x0B:
            if (topePila<1)
            {
                if (topePila==0){
                    topePila=-1;
                }
                topeBitacora++;
                bitacora[topeBitacora] = 0x08;
            }else{
                pila[topePila-1]=pila[topePila-1]+pila[topePila];
                topePila--;
                topeBitacora++;
                bitacora[topeBitacora] = 0x10;
            }
            break;

        case 0x0C:
            if (topePila<1)
            {
                if (topePila==0){
                    topePila=-1;
                }
                topeBitacora++;
                bitacora[topeBitacora] = 0x08;
            }else{
                pila[topePila-1]=pila[topePila-1]-pila[topePila];
                topePila--;
                topeBitacora++;
                bitacora[topeBitacora] = 0x10;
            }
            break;

        case 0x0D:
            if (topePila<1)
            {
                if (topePila==0){
                    topePila=-1;
                }
                topeBitacora++;
                bitacora[topeBitacora] = 0x08;
            }else{
                pila[topePila-1]=pila[topePila-1]*pila[topePila];
                topePila--;
                topeBitacora++;
                bitacora[topeBitacora] = 0x10;
            }
            break;

        case 0x0E:
            if (topePila<1)
            {
                if (topePila==0){
                    topePila=-1;
                }
                topeBitacora++;
                bitacora[topeBitacora] = 0x08;
            }else{
                pila[topePila-1]=pila[topePila-1]/pila[topePila];
                topePila--;
                topeBitacora++;
                bitacora[topeBitacora] = 0x10;
            }
            break;

        case 0x0F:
            if (topePila<1)
            {
                if (topePila==0){
                    topePila=-1;
                }
                topeBitacora++;
                bitacora[topeBitacora] = 0x08;
            }else{
                pila[topePila-1]=pila[topePila-1]%pila[topePila];
                topePila--;
                topeBitacora++;
                bitacora[topeBitacora] = 0x10;
            }
            break;

        case 0x10:
            if (topePila<1)
            {
                if (topePila==0){
                    topePila=-1;
                }
                topeBitacora++;
                bitacora[topeBitacora] = 0x08;
            }else{
                pila[topePila-1]=pila[topePila-1]&pila[topePila];
                topePila--;
                topeBitacora++;
                bitacora[topeBitacora] = 0x10;
            }
            break;

        case 0x11:
            if (topePila<1)
            {
                if (topePila==0){
                    topePila=-1;
                }
                topeBitacora++;
                bitacora[topeBitacora] = 0x08;
            }else{
                pila[topePila-1]=pila[topePila-1]|pila[topePila];
                topePila--;
                topeBitacora++;
                bitacora[topeBitacora] = 0x10;
            }
            break;

        case 0x12:
            if (topePila<1)
            {
                if (topePila==0){
                    topePila=-1;
                }
                topeBitacora++;
                bitacora[topeBitacora] = 0x08;
            }else{
                pila[topePila-1]=pila[topePila-1]<<pila[topePila];
                topePila--;
                topeBitacora++;
                bitacora[topeBitacora] = 0x10;
            }
            break;

        case 0x13:
            if (topePila<1)
            {
                if (topePila==0){
                    topePila=-1;
                }
                topeBitacora++;
                bitacora[topeBitacora] = 0x08;
            }else{
                pila[topePila-1]=pila[topePila-1]>>pila[topePila];
                topePila--;
                topeBitacora++;
                bitacora[topeBitacora] = 0x10;
            }
            break;

        case 0x14://imprimir pila
            for (int i = topePila; i >= 0; i--)
            {
                printf("0x%X\n",pila[i]);
            }
            break;

        case 0x15://imprimir bitacora
            for (int i = 0; i <= topeBitacora; i++)
            {
                if (bitacora[i]==0)
                {
                    printf("\n");
                }
                printf("0x%X ",bitacora[i]);
            }
            printf("\n");
            break;

        case 0xFE:
            topePila=-1;
            topeBitacora++;
            bitacora[topeBitacora] = 0x10;
            break;

        case 0xFF:
            salir = 1;
            break;
        
        default:
            topeBitacora++;
            bitacora[topeBitacora] = 0x02;
            break;
        }
    }
    

}