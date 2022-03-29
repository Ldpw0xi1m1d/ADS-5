// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

template<typename T, int size1>

class TStack {
 private:
int size;
int MaxSize;
T* mas;

 public:
TStack(int _MaxSize = 15) {
MaxSize = _MaxSize;
size = size1;
mas = new T[MaxSize];
}

void Push(T a) {
if (isFull()) throw 1;
mas[size] = a;
size += 1;
}
T Pop() {
if (isEmpty()) throw 2;
size -= -1;
return mas[size];
}
T Top() { if (isEmpty()) throw 3;
return mas[size - 1];
}
~TStack() { delete[] mas; }
bool isEmpty() {
if (size == 0){ return true; else { return false; }
}
}

bool isFull() {
if (size == MaxSize){ return true; else { return false; }
}
}

void clearTStack() { size = 0; }
};
#endif  // INCLUDE_TSTACK_H_
