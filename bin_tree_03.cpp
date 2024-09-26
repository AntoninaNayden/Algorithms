#include <iostream>
#include <cstdio>
#include<vector>
#include <limits>
using namespace std;
class Node {
public:
    long long leftParent;
    long long rightParent;
    long long node;
    Node() {
        node = 0;
        leftParent = INT64_MIN;
        rightParent = INT64_MAX;
    }
};

int main()
{
    freopen("bst.in", "r", stdin);
    freopen("bst.out", "w", stdout);
    int n;
    scanf("%d", &n);
    Node * nodes = new Node [n];
    long long str_of_parent;
    char left_right;
    scanf("%lld", &nodes[0].node);
    bool res = true;
    for (int i = 1; i < n; i++) {
        scanf("%lld%lld %c", &nodes[i].node, &str_of_parent, &left_right);
        int j;
        if (left_right == 'L') {
            j = str_of_parent;
            nodes[i].leftParent = nodes[j - 1].leftParent;
            nodes[i].rightParent = nodes[j - 1].node - 1;
        }
        if (left_right == 'R') {
            j = str_of_parent;
            nodes[i].rightParent = nodes[j - 1].rightParent;
            nodes[i].leftParent = nodes[j - 1].node;
        }
        if (nodes[i].node > nodes[i].rightParent || nodes[i].node < nodes[i].leftParent) {
            res = false;
            break;
        }
    }

    if (res) {
        printf("%s", "YES");
    }
    else {
        printf("%s", "NO");
    }


}
