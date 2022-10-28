#include <stdio.h>

int main(){
    const int PUERTO_LOG_DEFECTO = 0, PUERTO_SALIDA_DEFECTO = 0;
    int salir = 0, entrada, pila[32], topePila = -1, bitacora[200], topeBitacora = -1, puertoBitacora = PUERTO_LOG_DEFECTO, puertoSalida = PUERTO_SALIDA_DEFECTO;
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
            topePila++;
            pila[topePila] = entrada;
            topeBitacora++;
            bitacora[topeBitacora] = entrada;
            topeBitacora++;
            bitacora[topeBitacora] = 0x10;
            break;

        case 0x02:
            /* code */
            break;

        case 0x03:
            /* code */
            break;

        case 0x04:
            /* code */
            break;

        case 0x05:
            /* code */
            break;

        case 0x06:
            /* code */
            break;

        case 0x07:
            /* code */
            break;

        case 0x08:
            /* code */
            break;

        case 0x09:
            /* code */
            break;

        case 0x0A:
            /* code */
            break;

        case 0x0B:
            /* code */
            break;

        case 0x0C:
            /* code */
            break;

        case 0x0D:
            /* code */
            break;

        case 0x0E:
            /* code */
            break;

        case 0x0F:
            /* code */
            break;

        case 0x11:
            /* code */
            break;

        case 0x12:
            /* code */
            break;

        case 0x13:
            /* code */
            break;

        case 0x14:
            /* code */
            break;

        case 0x15:
            /* code */
            break;

        case 0xFE:
            /* code */
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