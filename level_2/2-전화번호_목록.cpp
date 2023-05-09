#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>

using namespace std;

bool solution(vector<string> phone_book) {
    set<string> dic;
    for(int i = 0; i < phone_book.size(); i++){
        auto iter = dic.lower_bound(phone_book[i]);
        if(iter != dic.end())   cout << *iter << endl;
        dic.insert(phone_book[i]);
    }
}