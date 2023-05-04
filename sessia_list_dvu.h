//sessia_list_dvu.h
/*Я отказался от идеи двунаправленного списка в пользу своих "списков" из за удобства, но решил не выкидивать данный материал насовсем. Может даже ещё пригодиться.*/
#pragma once
#include "sessia.h"
using namespace std;


struct Nods {
    sessia data;
    Nods* next;
    Nods* prev;
};
class sessiaList : public sessia {
private:
    Nods* head;
    Nods* tail;
    unsigned short count;
    const unsigned short MAX_COUNT = 10;
public:
    sessiaList() {
        head = NULL;
        tail = NULL;
        count = 0;
    }

    void add(sessia s) {
        if (count >= MAX_COUNT) {
            cout << "Невозможно добавить больше сессий, достигнут предел их количества!" << endl;
            return;
        }

        Nods* newNods = new Nods();
        newNods->data = s;
        newNods->next = NULL;
        newNods->prev = NULL;

        if (head == NULL) {
            head = newNods;
            tail = newNods;
        }
        else {
            tail->next = newNods;
            newNods->prev = tail;
            tail = newNods;
        }
        count++;
    }

    Nods* searchK(const int& k, const int& s) {
        Nods* current = head;
        while (current != NULL) {
            if (current->data.kurs == k && current->data.semestr == s) {
                return current;
            }
            current = current->next;
        }
        cout << "Такой сессии нет!" << endl;
        return NULL;
    }

    void insertAfter(Nods* n, const sessia& s) {
        if (n == NULL) {
            cout << "Некорректная позиция!" << endl;
            return;
        }

        Nods* newNods = new Nods();
        newNods->data = s;

        newNods->next = n->next;

        n->next = newNods;

        newNods->prev = n;

        if (newNods->next != NULL)
            newNods->next->prev = newNods;
    }

    void deleteNods(Nods* n) {
        if (head == NULL || n == NULL)
        {
            cout << "Такой сессии нет!" << endl;
            return;
        }
        if (head == n)
            head = n->next;

        if (n->next != NULL)
            n->next->prev = n->prev;

        if (n->prev != NULL)
            n->prev->next = n->next;

        delete n;
    }
};