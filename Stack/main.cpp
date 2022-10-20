#include <iostream>
#include "Stack.h"

int main() {
    Stack s;
    for (int i = 0; i < 10; i++) {
        s.Push(i);
    }
    cout << s.Pop() << endl;
    cout << "**************" << endl;
    cout << s.getTop() << endl;
    cout << "**************" << endl;
    return 0;
}