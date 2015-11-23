#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    Node(int frequency, char symbol) : frequency(frequency), symbol(symbol), left(NULL), right(NULL) { }

    Node *left;
    Node *right;
    int frequency;
    char symbol;
};

struct greater_node : public binary_function<Node *, Node *, bool> {
    bool
    operator()(const Node *__x, const Node *__y) const { return __x->frequency > __y->frequency; }
};

void dfs(Node *root, string code, unordered_map<char, string> &map) {
    if (root == NULL) {
        return;
    }
    dfs(root->left, code + "0", map);
    if (root->symbol != 0) {
        map[root->symbol] = code;
    }
    dfs(root->right, code + "1", map);
}

int main() {
    priority_queue<Node *, vector<Node *>, greater_node> pq;
    string s;
    cin >> s;
    vector<int> frequency(26, 0);
    for (char c : s) {
        frequency[c - 'a']++;
    }
    for (int i = 0; i < 26; ++i) {
        if (frequency[i] == 0) {
            continue;
        }
        Node * sym = new Node(frequency[i], (char) (i + 'a'));
        pq.push(sym);
    }
    while (pq.size() != 1) {
        Node *f1 = pq.top();
        pq.pop();
        Node *f2 = pq.top();
        pq.pop();
        Node * parent = new Node(f1->frequency + f2->frequency, 0);
        parent->left = f1;
        parent->right = f2;
        pq.push(parent);
    }
    Node *root = pq.top();
    string code = "";
    if (root->symbol != 0) {
        code = "0";
    }
    unordered_map<char, string> dict;
    dfs(root, code, dict);
    int len = 0;
    for (char c : s) {
        len += dict[c].length();
    }
    cout << dict.size() << ' ' << len << endl;
    for (int i = 0; i < 26; ++i) {
        if (frequency[i] == 0) {
            continue;
        }
        cout << (char) (i + 'a') << ": " << dict[i + 'a'] << endl;
    }
    for (char c : s) {
        cout << dict[c];
    }
    cout << endl;
    return 0;
}