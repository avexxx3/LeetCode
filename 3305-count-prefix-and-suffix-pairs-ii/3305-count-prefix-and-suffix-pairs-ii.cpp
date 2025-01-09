class Solution {

struct Node {
  vector<Node *> children;
  char chL;
  char chR;
  long long count;

  Node(char cL, char cR, long long count) : chL(cL), chR(cR), count(count) {}
};

struct PrefixSuffixTrie {
  Node *root;
  PrefixSuffixTrie() { root = new Node('\0', '\0', 0); }

  long long insert(string word) {
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


};

public:
    long long countPrefixSuffixPairs(vector<string>& words) {
        PrefixSuffixTrie trie;
        reverse(words.begin(), words.end());
        long long res = 0;
        for(string& word: words)
            res += trie.insert(word);

        return res;
    }
};