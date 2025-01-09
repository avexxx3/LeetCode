class Solution {

struct Node {
  vector<Node *> children;
  char chL;
  char chR;
  int count;

  Node(char cL, char cR, int count) : chL(cL), chR(cR), count(count) {}
};

struct PrefixTree {
  Node *root;
  PrefixTree() { root = new Node('\0', '\0', 0); }

  int insert(string word) {
    Node *ptr = root;
    bool flag;
    int l = word.length();
    bool insertedFlag = false;
    for (int i=0; i<l; i++) {
      flag = 0;
      for (Node *&child : ptr->children)
        if (child->chL == word[i] && child->chR == word[l - i - 1]) {
          flag = 1;
          ptr = child;
          ptr->count++;
          break;
        }

      if (!flag) {
        Node *n = new Node(word[i], word[l-i-1], 1);
        ptr->children.emplace_back(n);
        ptr = n;
        insertedFlag = true;
      }
    }

    if(!insertedFlag)
        return ptr->count - 1;
    return 0;
  }

  int count(string word) {
    Node *ptr = root;
    bool flag;
    int l = word.length();
    for (int i=0; i<l; i++) {
      flag = 0;
      for (Node *&child : ptr->children)
        if (child->chL == word[i] && child->chR == word[l - i - 1]) {
          flag = 1;
          ptr = child;
          break;
        }

      if (!flag)
        return 0;
    }

    return ptr->count;
  }
};

public:
    int countPrefixSuffixPairs(vector<string>& words) {
        PrefixTree trie;
        int count = 0;

        reverse(words.begin(), words.end());

        for(string& word: words)
            count += trie.insert(word);

        return count;
    }
};