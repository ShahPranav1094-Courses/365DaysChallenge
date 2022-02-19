// https://leetcode.com/problems/word-ladder/discuss/1764371/A-very-highly-detailed-EXPLANATION
// Time Complexity :- BigO(M^2 * N), where M is size of dequeued word & N is size of our word list
// Space Complexity :- BigO(M * N) where M is no. of character that we had in our string & N is the size of our wordList.
int ladderLength(string beginWord, string endWord, vector<string> &wordList)
{
    bool isPresent = false;
    unordered_set<string> s;
    for (auto &word : wordList)
    {
        if (word == endWord)
        {
            isPresent = true;
        }
        s.insert(word);
    }
    if (!isPresent)
        return 0;

    queue<string> q;
    q.push(beginWord);
    int depth = 0;
    while (!q.empty())
    {
        int sz = q.size();
        depth++;

        while (sz--)
        {
            string curr = q.front();
            q.pop();

            for (int i = 0; i < curr.size(); ++i)
            {
                string temp = curr;

                for (char c = 'a'; c <= 'z'; ++c)
                {
                    temp[i] = c;

                    if (temp.compare(curr) == 0)
                        continue;

                    if (temp.compare(endWord) == 0)
                        return depth + 1;

                    if (s.find(temp) != s.end())
                    {
                        q.push(temp);
                        s.erase(temp);
                    }
                }
            }
        }
    }
    return 0;
}

public
int ladderLength(String beginWord, String endWord, List<String> wordList)
{
    Set<String> set = new HashSet<>(wordList);
    if (!set.contains(endWord))
        return 0;

    Queue<String> queue = new LinkedList<>();
    queue.add(beginWord);

    Set<String> visited = new HashSet<>();
    queue.add(beginWord);

    int changes = 1;

    while (!queue.isEmpty())
    {
        int size = queue.size();
        for (int i = 0; i < size; i++)
        {
            String word = queue.poll();
            if (word.equals(endWord))
                return changes;

            for (int j = 0; j < word.length(); j++)
            {
                for (int k = 'a'; k <= 'z'; k++)
                {
                    char arr[] = word.toCharArray();
                    arr[j] = (char)k;

                    String str = new String(arr);
                    if (set.contains(str) && !visited.contains(str))
                    {
                        queue.add(str);
                        visited.add(str);
                    }
                }
            }
        }
        ++changes;
    }
    return 0;
}