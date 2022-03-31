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
TStack() {
size = size1;
mas = new T[size];
MaxSize = -1;
}
~TStack() {
delete[]mas;
}
void Push(T a) {
if (MaxSize >= size - 1) {
T* temp = mas;
mas = new T[++size];
for (int i = 0; i < size; i++) mas[i] = temp[i];
delete[] temp;
}
mas[++MaxSize] = a;
}
T Pop() {
size--;
return mas[--MaxSize + 1];
}
T Top() {
return mas[MaxSize];
}
bool isEmpty() {
if (MaxSize == -1) return true;
else
return false;
}
};
#endif  // INCLUDE_TSTACK_H_
