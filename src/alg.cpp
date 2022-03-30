// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

int priority(char ch) {
switch (ch) {
case '(': return 0; break;
case ')': return 1; break;
case '+': return 2; break;
case '-': return 2; break;
case '*': return 3; break;
case '/': return 3; break;
}
return -1;
}

std::string infx2pstfx(std::string inf) {
std::string pstfx = "";
std::string str = '(' + inf + ')';
TStack <char, 5> stack1;
stack1.clearTStack();
for (int i = 0; i < str.size(); i++) {
if (priority(str[i]) == -1) {
pstfx += str[i];
} else if (str[i] >= '0' && str[i] <= '9') { pstfx += str[i];
} else if (str[i] == '(') { stack1.Push(str[i]);
} else if (str[i] == ')') {
while (stack1.Top() != '(') {
pstfx += stack1.Pop();
}
stack1.Pop();
} else {
if((str[i] == '+') || (str[i] == '-') || (str[i] == '*') || (str[i] == '/')) {
pstfx += ' ';
if (priority(stack1.Top()) < priority(str[i])) {
stack1.Push(str[i]);
} else {
while (priority(stack1.Top()) >= priority(str[i]))
pstfx += stack1.Pop();
stack1.Push(str[i]);
}
}
}
} return pstfx; }

int eval(std::string pstfx) {
TStack<int, 5> stack2;
int first;
int second;
int result;
stack2.clearTStack();
for (size_t i = 0; i < pstfx.size(); i++) {
if((pstfx[i] =='+') || (pstfx[i] =='-') || (pstfx[i] == '/') ||
(pstfx[i] == '*')) {
if (stack2.isEmpty()) throw 4;
second = stack2.Pop();
if (stack2.isEmpty()) throw 4;
first = stack2.Pop();
switch (pstfx[i]) {
case '+': result = first + second; break;
case '-': result = first - second; break;
case '*': result = first * second; break;
case '/': result = first / second; break;
}
stack2.Push(result);
}
if (stack2.isEmpty()) { throw 6;
} else { result = stack2.Pop(); }
if (!(stack2.isEmpty())) throw 7;
}
return result;
}
