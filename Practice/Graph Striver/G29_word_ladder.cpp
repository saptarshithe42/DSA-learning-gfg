// https : //leetcode.com/problems/word-ladder/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /*
        - Basically a shortest path question, from startWord to endWord
        - using simple BFS
        - For each word consider all the 26 possible character 'a' to 'z' for
          each position and check if it exists in given wordList, if so then
          we can traverse to this word (transformation)

        - TC : O(N * word.length * 26 * logN) [N = wordList.size()]
    */

    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {

        queue<pair<string, int>> q; // {word, no_of_words_in_current_sequence}

        int n = beginWord.size();

        unordered_set<string> s(wordList.begin(), wordList.end());

        if (s.find(beginWord) != s.end())
        {
            s.erase(beginWord);
        }

        q.push({beginWord, 1});

        while (!q.empty())
        {

            string word = q.front().first;
            int len = q.front().second;
            q.pop();

            for (int i = 0; i < n; i++)
            {

                string temp = word;
                for (int j = 0; j < 26; j++)
                {

                    temp[i] = 'a' + j;

                    if (s.find(temp) != s.end())
                    {

                        if (temp == endWord)
                            return (len + 1);

                        q.push({temp, len + 1});
                        s.erase(temp);
                    }
                }
            }
        }

        return 0;
    }
};