#include <iostream>
#include <cstdio>
using namespace std;

/* 
Int ("%d"): 32 Bit integer
Long ("%ld"): 64 bit integer
Char ("%c"): Character type
Float ("%f"): 32 bit real value
Double ("%lf"): 64 bit real value
String ("%s"): String (o array de caracteres)
*/

int main() {
    int int_entero;
    long lng_enteroLargo;
    char chr_caracter;
    float flt_decimal;
    double dbl_decimalLargo;

    scanf("%d %ld %c %f %lf", &int_entero, &lng_enteroLargo, &chr_caracter, &flt_decimal, &dbl_decimalLargo);
    printf("%d\n%ld\n%c\n%f\n%.9lf\n", int_entero, lng_enteroLargo, chr_caracter, flt_decimal, dbl_decimalLargo);

    return 0;
}