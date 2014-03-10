#include<iostream>
#include<algorithm>
#include<deque>
#include<math.h>
#include<vector>

using namespace std;
class Node {
public:
    const int data;
    Node* L;
    Node* R;
    Node(int d, Node* l = NULL, Node* r = NULL):L(l), R(r), data(d){}
};

Node* build_tree(const vector<int>& post, const vector<int>& in, int ps, int pe, int is, int ie) {
    if (ps>pe) {
        return NULL;
    }
    int rdata = post[pe];
    int div = is;
    while(in[div] != rdata) div++;
    Node* root = new Node(rdata);
    root->L = build_tree(post, in, ps, ps + div - is - 1, is, div - 1);
    root->R = build_tree(post, in, ps + div - is, pe - 1, div + 1, ie);
    return root;
}

void level_traverse(Node* root) {
    if (root == NULL) return;
    deque<Node*> que;
    Node* tmp = NULL;
    que.push_back(root);
    bool is_first = true;
    while (que.size() != 0) {
        tmp = que.front();
        if (is_first) {
            is_first = false;
            cout<<tmp->data;
        } else {
            cout<<" "<<tmp->data;
        }
        if (tmp->L != NULL) que.push_back(tmp->L);
        if (tmp->R != NULL) que.push_back(tmp->R);
        que.pop_front();
        delete tmp;
    }
} 

int main()
{
	freopen("D:/treetraversal.txt","r",stdin);
    int n;
    cin>>n;
    vector<int> postorder(n);
    vector<int> inorder(n);

    for (int i=0; i<n; i++) {
        cin>>postorder[i];
    }

    for (int i=0; i<n; i++) {
        cin>>inorder[i];
    }

    Node* tree = build_tree(postorder, inorder, 0, n - 1, 0, n - 1);
    level_traverse(tree);
	while(true){}
    return 0;
}
