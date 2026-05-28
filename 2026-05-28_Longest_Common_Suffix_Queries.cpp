#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e9;

class Node {
public:
    // Node* links[26];
    int links[26];
    pair<int, int> p; // size, ind

    Node() {
        for (int i = 0; i < 26; i++)
            links[i] = -1;
        p = {MAX, -1};
    }
    bool isContained(char ch) { return links[ch - 'a'] != -1; }
    int getNext(char ch) { return links[ch - 'a']; }
    void put(char ch, int node) { links[ch - 'a'] = node; }
    void updatedMini(int len, int ind) {
        if (p.second == -1)
            p = {len, ind};
        else if (p.first > len)
            p = {len, ind};
        else if (len == p.first && ind < p.second)
            p = {len, ind};
    }
    int getIndex() { return p.second; }
};

class Solution {
public:
    // Node* root = new Node();
    vector<Node> Trie;
    int miniInd;

    void putInTries(string& word, int ind) {
        // Node* node = root;
        int node = 0;
        int n = word.size();
        Trie[node].updatedMini(n, ind);

        for (int i = n - 1; i >= 0; i--) {
            char ch = word[i];
            if (!Trie[node].isContained(ch)) {
                Trie[node].put(ch, Trie.size());
                Trie.push_back(Node());
            }
            node = Trie[node].getNext(ch);
            Trie[node].updatedMini(n, ind);
        }
    }

    int getSuffixIndex(string& word) {
        // Node* node = root;
        int node = 0;
        int ans = Trie[0].getIndex();
        int n = word.size();
        for (int i = n - 1; i >= 0; i--) {
            char ch = word[i];
            if (Trie[node].isContained(ch)) {
                node = Trie[node].getNext(ch);
                ans = Trie[node].getIndex();
            } else
                return ans;
        }
        return ans;
    }

    vector<int> stringIndices(vector<string>& wordsContainer,
                              vector<string>& wordsQuery) {

        Trie.clear();
        Trie.push_back(Node());

        int n = wordsQuery.size();
        int size = wordsContainer[0].size();
        int minIndex = 0;

        for (int i = 0; i < wordsContainer.size(); i++) {
            putInTries(wordsContainer[i], i);
            if (size > (int)wordsContainer[i].size()) {
                size = (int)wordsContainer[i].size();
                minIndex = i;
            }
        }

        vector<int> ans;

        for (auto& query : wordsQuery) {
            int index = getSuffixIndex(query);
            ans.push_back((index == -1 ? minIndex : index));
        }

        return ans;
    }
};