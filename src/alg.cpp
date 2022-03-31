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
    int i = 0;
     TStack <char, 10> stack1;
  for (i; i < inf.length(); i++) {
    if (inf[i] >= '0' && inf[i] <= '9') {
      pstfx += inf[i];
     } else if (inf[i] == '+' || inf[i] == '-' || inf[i] == '*' ||
        inf[i] == '/') {
                 if (stack1.isEmpty()) {
                          stack1.Push(inf[i]);
                                 pstfx += " ";
                        } else if (stack1.Top() == '(') {
                                  stack1.Push(inf[i]);
                                  pstfx += " ";
                        } else if (priority(inf[i]) > priority(stack1.Top())) {
                                stack1.Push(inf[i]);
                                pstfx += " ";
                        } else if (priority(inf[i]) <= priority(stack1.Top())) {
                                pstfx += " ";
                                pstfx += stack1.Pop();
                                pstfx += " ";
                           while ((priority(inf[i]) <= priority(stack1.Top()) ||
                              stack1.Top() != '(') && !stack1.isEmpty()) {
                                pstfx += " ";
                                pstfx += stack1.Pop();
                                pstfx += " ";
                                }
                                stack1.Push(inf[i]);
                         }
                } else if (inf[i] == '(') {
                         stack1.Push(inf[i]);
                } else if (inf[i] == ')') {
                        while (stack1.Top() != '(') {
                                pstfx += " ";
                                pstfx += stack1.Pop();
                           }
                          stack1.Pop();
                }
         }
          while (!stack1.isEmpty()) {
                pstfx += " ";
                pstfx += stack1.Pop();
        }
        return pstfx;
}

int result(int first, int second, char ch) {
     int res;
       switch (ch) {
        case '+':return res = first + second;
        case'-':return res = first - second;
        case '*': return res = first * second;
        case'/': return res = first / second;
     }
     return 0;
}
int stoyamba(std::string first) {
       return stoi(first);
}
int eval(std::string pref) {
 TStack <int, 10> stack;
     int i = 0;
     std::string num;
     int first1;
     int second1;
       for (i; i < pref.length(); i++) {
            if (priority(pref[i]) == -1 && pref[i] != ' ') {
                        num = pref[i];
                        stack.Push(stoyamba(num));
                } else if (pref[i] == '-' || pref[i] == '+' || pref[i] == '*' ||
                 pref[i] == '/') {
                        second1 = stack.Pop();
                        first1 = stack.Pop();
                        stack.Push(result(first1, second1, pref[i]));
               }
        }
         return stack.Pop();
}
