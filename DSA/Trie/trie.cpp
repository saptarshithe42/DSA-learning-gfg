#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *links[26];
    bool flag = false;

    bool containsKey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }

    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }

    Node *get(char ch)
    {
        return links[ch - 'a'];
    }

    void setEnd()
    {
        flag = true;
    }

    void unsetEnd()
    {
        flag = false;
    }

    bool isEnd()
    {
        return flag;
    }

    bool isEmpty()
    {
        for (int i = 0; i < 26; i++)
        {
            if (links[i])
            {
                return false;
            }
        }

        return true;
    }
};

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    // O(len(word))
    void insert(string word)
    {
        Node *node = root;

        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    // O(len(word))
    bool search(string word)
    {
        Node *node = root;

        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                return false;
            }
            node = node->get(word[i]);
        }

        return node->isEnd();
    }

    // O(len(prefix))
    bool startsWith(string prefix)
    {
        Node *node = root;

        for (int i = 0; i < prefix.size(); i++)
        {
            if (!node->containsKey(prefix[i]))
            {
                return false;
            }
            node = node->get(prefix[i]);
        }

        return true;
    }

    void erase(string word)
    {
        root = eraseRec(root, 0, word);
    }

    Node *eraseRec(Node *node, int i, string word)
    {
        if (!node)
        {
            return NULL;
        }

        if (i == word.size())
        {
            node->unsetEnd();

            if (node->isEmpty())
            {
                delete node;
                node = NULL;
            }
            return node;
        }

        node->links[word[i] - 'a'] = eraseRec(node->get(word[i]), i + 1, word);

        if (node->isEmpty() && !node->isEnd())
        {
            delete node;
            node = NULL;
        }

        return node;
    }
};

int main()
{

    vector<string> v = {"an", "and", "ant", "antennae",
                        "bad",
                        "bat", "zoo"};

    Trie trie = Trie();

    for (int i = 0; i < v.size(); i++)
    {
        trie.insert(v[i]);
    }

    cout << std::boolalpha;

    cout << trie.search("and") << endl;
    cout << trie.search("hello") << endl;
    cout << trie.search("ba") << endl;
    cout << trie.startsWith("ba") << endl;
    cout << trie.startsWith("and") << endl;
    cout << trie.startsWith("a") << endl;
    cout << trie.startsWith("ta") << endl;
    cout << "=================" << endl;

    trie.erase("and");
    cout << trie.search("and") << endl;
    cout << trie.search("ant") << endl;
    cout << trie.startsWith("an") << endl;
    cout << trie.search("zoo") << endl;
    trie.erase("zoo");
    cout << trie.search("zoo") << endl;
    cout << trie.search("antennae") << endl;
    trie.erase("antennae");
    cout << trie.search("ant") << endl;
    cout << trie.search("antennae") << endl;

    return 0;
}
