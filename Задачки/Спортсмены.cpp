/*
Условие
У каждого спортсмена на футболке написан уникальный номер. Спортсмены по очереди выходят из раздевалки и должны построиться на стадионе. Тренер каждому выходящему спортсмену называет номер того спортсмена, перед которым нужно встать. Если спортсмена с названным номером на поле нет, то нужно встать в конец шеренги.

В стандартном вводе сначала задано натуральное число n, не превосходящее 100000, — количество спортсменов. Далее идут n пар неотрицательных целых чисел, не превосходящих 100000. Первое число в паре — номер очередного выходящего спортсмена. Второе число в паре — номер того спортсмена, перед которым должен встать текущий.

Напечатайте в стандартный вывод номера спортсменов в порядке построения на поле.

Ограничение по времени — 0,8 с.

*/

#include<iostream>
#include <string>
#include <string_view>
#include<vector>
#include <algorithm>
#include "profile.h" 
#include <list>
#include <optional>
using namespace std;


int main() {
    vector<optional<list<size_t>::iterator>> Check(100000);    
    list<size_t> result;
    int N;
    cin >> N;
    for(int i = 0; i < N; ++i) {
        int Number, Next; 
        cin >> Number >> Next; 
        if(Check[Next]) {
            result.insert(*Check[Next], Number); 
            Check[Number] = prev(*Check[Next]);
        } else {
            result.push_back(Number);
            Check[Number] = prev(result.end());
        }
        
    }
  
    for (auto x : result) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
