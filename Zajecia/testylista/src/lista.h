#ifndef LISTA_H
#define LISTA_H



using namespace std;


struct Node;

class List {
    Node *m_pHead {nullptr};
    int m_elemCount {0};
    void deleteElems(Node *pList);

public:
    static List* fromArray(int const arr[], int size); //factory method
    //List(int const arr[], int size);
    List() {}
    ~List();
    void insert(int value);
    void reverse();
    std::string toString() const;
    bool contains(int elem) const;
    int elemCount() const { return m_elemCount; }


    // ...
};

void runListMethods();


struct Node {
    int value;
    Node *pNext;
    ~Node() { /*std::cout << "destruction of " << value << std::endl;*/ }
};

#endif // LISTA_H
