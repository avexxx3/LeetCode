class Solution {
    struct Node {
        vector<Node*> children;
        char ch;
        int count;

        Node(char c, int count): ch(c), count(count) {}
    };

    struct PrefixTree {
        Node* root;

        PrefixTree() : root(0) {}

        void insert(string word) {
            if(!root)
                root = new Node('\0', 0);

            Node* ptr = root;
            bool flag;
            bool insertedAtAll = false;
            for(char& ch: word) {
                flag = 0;
                for(Node*& child: ptr->children)
                    if(child->ch == ch) {
                        flag = 1;
                        ptr = child;
                        ptr->count++;
                        break;
                    }

                if(!flag) {
                    Node* n = new Node(ch, 1);
                    ptr->children.emplace_back(n);
                    ptr = n;
                    insertedAtAll = true;
                }
            }

        }

        int count(string word) {
            Node* ptr = root;
            bool flag;
            for(char& ch: word) {
                flag = 0;
                for(Node*& child: ptr->children)
                    if(child->ch == ch) {
                        flag = 1;
                        ptr = child;
                        break;
                    }
                
                if(!flag)
                    return 0;
            }

            return ptr->count;
        }
    };

public:
    int prefixCount(vector<string>& words, string pref) {
        PrefixTree tree;
        for(string& word: words)
            tree.insert(word);

        return tree.count(pref);
    }
};