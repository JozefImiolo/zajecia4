#include <iostream>
#include <memory>
#include<string>
#include<ctime>
using namespace std;

class Visitor;

class Expression{
 public:
 // destruktor wirtualny !!!!
    virtual ~Expression()=0;
    virtual double eval() const =0;
      virtual void accept(Visitor&v) const =0;

// ovveride dopisanie oznacza ze ta metoda nadpisuje ta metode kompilator sprawdza czy nie klamiemy zpomnienie consta
  //  dobry program usuwamy ovveride jest ok

};
inline  Expression::~Expression()=default;
inline double  Expression::eval() const{
    return 0;
}
class Literal : public Expression{

    double value;
    public:
  explicit  Literal(double n): value{n} {}
double eval() const override {
    return value;
}
  void accept(Visitor& v) {

    v.visit(*this);
}
};


class Add:public Expression {
    public:
    // zle Expression *left, right;
    // w protected binary operator nadkasa
    //wolanie kkostrukrota z klasy zbaowej
    //Binaryop{left, right} {}
    //lub using BinaryOp::BinaryOP to to samo c++11
    //dzieczenie konstruktorw
    unique_ptr<Expression> left;
    unique_ptr<Expression> right;

   Add(unique_ptr<Expression> left, unique_ptr<Expression> right): left{std::move(left)}, right{move(right)}{}
 double eval() const override {
   return left->eval()+right->eval();
    }
// ~Add(){
     //delete left;
    // delete right;
 //}

};

class mult:public Expression {
    public:
    // zle Expression *left, right;
    // w protected binary operator nadkasa
    //wolanie kkostrukrota z klasy zbaowej
    //Binaryop{left, right} {}
    //lub using BinaryOp::BinaryOP to to samo c++11
    //dzieczenie konstruktorw
    Expression *left;
    Expression *right;

   mult(Expression* l, Expression* r): left{l}, right{r}{}
 double eval() const override {
   return left->eval()+right->eval();
    }

};
string f() {return "dsfsd";}

//Expression * mozna wskaznik ale wywolanie
// nie zwolnimy
// Exprezzion * e - new randmom_expression()
// zwracanie uniwue_pptr jest ok
// uniq randmom_expression()ok samo sie wypierdoli



unique_ptr<Expression> random_expressions(){

     std::srand(std::time(nullptr));
     int a =std::rand()%3;


    switch (a) {
    case 0:{
        //return new unique_ptr<Expression>p=move( new Literal{3});
       // return unique_ptr<Expression>{new Literal{rand()%10}};
        break;
    }
    case 1:{

        unique_ptr<Expression> e1=random_expressions();
        //zmienna przez funkcje zmienna tymczzasowa
         unique_ptr<Expression> e2=random_expressions();
    //    return  unique_ptr<Expression>{new Add{move(e1), move(e2)}};
//

        break;
}
    default:
        return nullptr;

        break;
    }
      return nullptr;
}

class Visitor{

public:
    virtual ~Visitor=default;
    void visit(const Literal& e)=0;
    void visit(const Add& e)=0;
   // void visit(const Mult& e)=0;
}
class Printer: public Visitor{
public:
    void visit(const Literal& v )override{
        cout<<v.eval();
    }
    void visit(const Add& v )override{
        cout<<v.eval();
    }

unique_ptr<Expression> f2() {return unique_ptr<Expression>{new Literal{2}};}

int main(int , char **)
{
    string s=f(); // konstuktory przenoszace
    string s3=s; //kopiowanie zasob kons kopiujacy

                 unique_ptr<Expression> h=f2();

                 unique_ptr<Expression> p2=std::move(h);
                 //p==nullptr;

                 //p2=p z uto by przeszlo z unique nie przecgodzi


   Expression * l;
    Expression * p;
   l=new Literal(4);
   p=new Literal(6);

  // Expression *a= new Add(l,p);
  // cout<<a->eval();

   //delete a;
//
  // unique_ptr<Expression>pw =new Literal{5};

   unique_ptr<Expression>pw{l};
   //pw release reset


   //std::unique_ptr<Expression>p2=p;

     Literal l1{7};
       Literal l2{7};
    //     unique_ptr<Expression>pw1{new Literal{3};
    //    unique_ptr<Expression>pw1{new Literal{3};
           //  Add s4(move(pw1), move(pw2));

         //  wskauzja one na nullptr bo add to zmieni;                                Mult s4(move(pw1), move(pw2));  ;
       //zwalniamy to co na stosir
    //   Add s1(&l1, &l2);
      // cout<<s1.eval()<<endl;
    //std::cout << "Hello World!\n";
  //  Rational a(2,3),b (5,6);
 //   a+b;
    // argument za tym aby je implementowac poza klasa Rational c= 6+a;
   //
   //std::cout<<c<<endl;
/*for(int i =0; i<5;i++)
{
    auto e=random_expressions();

 e->eval()

}
*/
    return 0;
}




};
