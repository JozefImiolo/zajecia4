#ifndef IROWKWA_H
#define IROWKWA_H

#include<cmath>

/*
class kwadrat
{
    int a;
    int b;
    int c;

    resutl roots()
    {

    }

};
*/
struct result
{
    double x1;
    double x2;
    int count;
    bool identity;
};

inline result solution(double a, double b,double c)
{
    double delta;
    delta= b*b -4*a*c;
       result wynik;
     if(a==0 && b==0 && c==0)
     {

         wynik.identity=true;
     else if( )
     else if (delta>0 )
    {

        wynik.x1=(-b+sqrt(delta))/(2*a);
        wynik.x2=(-b-sqrt(delta))/(2*a);
        wynik.count=2;
        wynik.identity=false;

    }
     else if (delta==0 )
 {

     wynik.x1=-b/(2*a);
     wynik.count=1;
     wynik.identity=false;

 }
     else if (delta <0)
     {
            wynik.count=0;
           wynik.identity=false;

     }

    return wynik;
}

// lista vector
// referencjaroots ( a b c , #wynik1, #wynik 2)

//diff array val arrray

#endif // IROWKWA_H
