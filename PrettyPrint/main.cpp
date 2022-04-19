#include <iomanip> 
#include <iostream>
using namespace std;

int main()
{
    int T;
    cin >> T;
    cout << setiosflags(ios::uppercase);
    cout << setw(0xf) << internal;
    while(T--)
    {
        double A;
        double B;
        double C;
        cin >> A >> B >> C;
        printf("%#lx\n",(long int)A);
        printf("%.*s%+.2f\n",15 - to_string((int)B).length() - 4,"_______________",B);
        printf("%.9E\n",C);
    }
    return 0;
} 