#ifndef WYM_H
#define WYM_H

#include<cassert>
#include <iostream>
class Rational{
    int nominator;
    int denominator;
 // liczby wzglednie pierwsze
 //   denominator!=0
  // denominator >0;

    // funkcje inline

    // konstruktor jednoargumentowy konwertuj

    Rational operator + (const Rational& r ) const;
    Rational (int a, int b) : nominator(a), denominator(b)
      //
    {/*
        if (b==0);
        {
           // throw  dobre rozwiazani
           assert(b!=0);
        }
        else if (b<0)
        {
            b=-b;
            a=-a;
        }
       // nwd=gcd(a,b);

        b=b/mwd;
        a=a/nwd;

        nominator=a;
        denominator=b;
        */
    }
    Rational (int n) : Rational (n,1){}

    int num ()const {return nominator;}
    int denum ()const {return denominator;}

      //explisit niejawna zabroniona


};

int gcd(int a, int b)
{
    int wynik;
    if (a>b)
    {
       // gcd(a-b,b);
    }
    else if(){}

    return 0;


}
inline bool operator == (Rational a, Rational b);
// operatry na zaewnatrz// alemodyfiukjace w kllasie

std::ostream& operator <<(std::ostream& os, Rational a)
{
         return os<<a.num()<<"/"<<a.denum();
         // dlaczego tak
}

//Rational operator + (Rational a, Rational b);

#endif // WYM_H
