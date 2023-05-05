#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> files) {
    stable_sort(files.begin(), files.end(), [](string a, string b){
        int i = 0, j = 0;
        for(;!(isdigit(a[i]) || isdigit(b[j])); i++, j++)
            if(tolower(a[i]) != tolower(b[j]))  return tolower(a[i]) < tolower(b[j]);
        if(!isdigit(a[i]))  return false;
        else if(!isdigit(b[j]))  return true;

        int int_a = a[i++] - '0', int_b = b[j++] - '0';
        for(; i < a.size() && isdigit(a[i]); i++)   int_a = int_a * 10 + a[i] - '0';
        for(; j < b.size() && isdigit(b[j]); j++)   int_b = int_b * 10 + b[j] - '0';
        return int_a < int_b;
    });
    return files;
}