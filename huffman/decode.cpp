#include <bits/stdc++.h>

using namespace std;

int main() {
    int k;
    int l;
    cin >> k >> l;
    unordered_map<string, char> dict;
    for (int i = 0; i < k; ++i) {
        string sym;
        string code;
        cin >> sym >> code;
        dict[code] = sym[0];
    }
    string encoded;
    cin >> encoded;
    string part = "";
    for (int i = 0; i < l; ++i) {
        part += encoded[i];
        if (dict[part] != 0) {
            cout << dict[part];
            part = "";
        }
    }
    cout << endl;
    return 0;
}