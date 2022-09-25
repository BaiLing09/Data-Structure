#include <iostream>
#include "Link.h"

int main() {
    LinkList L;
    for (int i = 1; i < 11; i++) {
        L.creatList_R(i);
    }
//    L.getElement();

//    L.listInsert(12,20);

//    L.listDelete(10);
//    L.listReplace(11,20);
    L.getElement();
    cout << L.listLocate(3)->data.id << endl;
//    L.getLength();

    return 0;

}