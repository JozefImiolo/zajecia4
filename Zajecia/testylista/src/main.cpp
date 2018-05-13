#include<iostream>
#include "lista.h"
#include <memory>

using namespace std;

int main(int argc, char *argv[])

{
    cout << "*** Testing l1 = [1,2,3,4,5,6,7,8,9] ***" << endl;

    constexpr int arr1[] = {1,2,3,4,5,6,7,8,9};
    std::unique_ptr<List> pL1(List::fromArray(arr1, 9));
    cout << "L1 = " << pL1->toString() << endl;

    cout << "L1.contains(3) = " << pL1->contains(3) << endl;
    cout << "L1.contains(10) = " << pL1->contains(10) << endl;

    cout << "*** Reversing L1... " << endl;
    pL1->reverse();
    cout << "L1 = " << pL1->toString() << endl;
    cout << endl;

    cout << "*** Testing list L2 = [] ***" << endl;

    unique_ptr<List> pL2(new List);
    cout << "L2 = " << pL2->toString() << endl;

    cout << "L2.contains(1) = " << pL2->contains(1) << endl;

    cout << "*** Reversing L2... " << endl;
    pL2->reverse();
    cout << "L2 = " << pL2->toString() << endl;
    return 0;

}
