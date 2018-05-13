#include<iostream>
#include<memory>
#include "lista.h"
using namespace std;


List* List::fromArray(int const arr[], int size)
{
    List* pL = new List;

    for (int i = size - 1; i >= 0; --i) {
        pL->insert(arr[i]);
    }

    return pL;
}

List::~List()
{
    deleteElems(m_pHead);
    this->m_elemCount = 0; //?
}

void List::insert(int elem)
{
    Node *pCurrHead = this->m_pHead;

    Node *pCurrNode = new Node;
    pCurrNode->value = elem;
    pCurrNode->pNext = pCurrHead;

    this->m_pHead = pCurrNode;
    this->m_elemCount++;
}

std::string List::toString() const
{
    using std::string; using std::to_string; // vs. using namespace
    string result {"["};

    for (Node *pNode = this->m_pHead; pNode != nullptr; pNode = pNode->pNext) {
        result += to_string(pNode->value);
        if (pNode->pNext != nullptr) {
            result += ',';
        }
    }

    result += "]";
    return result;
}

bool List::contains(int elem) const
{
    for (Node *pNode = this->m_pHead; pNode != nullptr; pNode = pNode->pNext) {
        if (pNode->value == elem) {
            return true;
        }
    }

    return false;
}

void List::reverse()
{
    Node *pPrevNode = nullptr, *pNode = this->m_pHead, *pNextNode;

    while (pNode != nullptr) {
        // swap/reconnect
        pNextNode = pNode->pNext;
        pNode->pNext = pPrevNode;

        // move to the next node
        pPrevNode = pNode;
        pNode = pNextNode;
    }

    this->m_pHead = pPrevNode;
}

void List::deleteElems(Node *pList)
{
    Node *pCurrHead = pList;

    if (pCurrHead != nullptr) {
        deleteElems(pCurrHead->pNext);
        delete pCurrHead;
    }
}
