// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

template <typename T, int size1>
class TStack {

private:

int Size;
int MaxSize;
T* mas;

public:

TStack(int _MaxSize = 15) {
MaxSize = _MaxSize;
Size = 0;
mas = new T[MaxSize];
}

TStack(const TStack& ts) {
MaxSize = ts.MaxSize;
Size = ts.Size;
mas = new T[ts.MaxSize];
for (int i = 0; i < Size; i++) {
mas[i] = ts.mas[i];
}
}

~TStack() {
delete[] mas;
}

bool isEmpty() {
if (Size == 0)
return true;
else
return false;
}

void Push(T a) {
mas[Size] = a;
Size++;
}

T Pop() {
if (isEmpty())  throw  2;
Size--;
return mas[Size];
}

T Top() {
if (isEmpty())  throw 3;
return mas[Size - 1];
}
};
#endif  // INCLUDE_TSTACK_H_
