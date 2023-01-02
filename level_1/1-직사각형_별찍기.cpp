#include <iostream>
#include <string>
using namespace std;

int main(void) {
    int a, b;
    cin >> a >> b;
    string s(a, '*');
    for(int i = 0; i < b; i++)  cout << s << endl;
    return 0;
}