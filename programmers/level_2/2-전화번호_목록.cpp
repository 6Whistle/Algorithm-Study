#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());
    for(int i = 0; i < phone_book.size() - 1; i++)  
        if(!phone_book[i].compare(0, min(phone_book[i].size(), phone_book[i+1].size()), phone_book[i+1]
                                , 0, min(phone_book[i].size(), phone_book[i+1].size())))   return false;
    return true;
}