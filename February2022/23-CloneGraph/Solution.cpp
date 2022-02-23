// O(N) Time & O(N) Space
// Iterative
Node *cloneGraph(Node *node)
{

    if (node == nullptr)
        return node;

    queue<Node *> q;
    q.push(node);
    Node *start = nullptr;
    unordered_set<Node *> s;
    unordered_map<Node *, Node *> m;
    s.insert(node);

    Node *copy_node = new Node(node->val);
    m[node] = copy_node;

    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();

        Node *copy_curr = m[curr];

        if (start == nullptr)
            start = copy_curr;

        for (Node *n : curr->neighbors)
        {
            if (m.find(n) == m.end())
            {
                Node *copy_n = new Node(n->val);
                m[n] = copy_n;
            }
            copy_curr->neighbors.push_back(m[n]);
            if (s.find(n) == s.end())
            {
                q.push(n);
                s.insert(n);
            }
        }
    }
    return start;
}

// O(N) Time & O(N) Space
// Recursive
Node *cloneGraph(Node *node)
{
    if (!node)
        return node;

    if (!m.count(node))
    {
        m[node] = new Node(node->val);
        for (auto neighbor : node->neighbors)
        {
            m[node]->neighbors.push_back(cloneGraph(neighbor));
        }
    }
    return m[node];
}