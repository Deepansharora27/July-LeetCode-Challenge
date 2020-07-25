/*


PROBLEM STATEMENT : 

Given a directed, acyclic graph of N nodes.  Find all possible paths from node 0 to node N-1, and return them in any order.

The graph is given as follows:  the nodes are 0, 1, ..., graph.length - 1.  graph[i] is a list of all nodes j for which the edge (i, j) exists.

Example:
Input: [[1,2], [3], [3], []] 
Output: [[0,1,3],[0,2,3]] 
Explanation: The graph looks like this:
0--->1
|    |
v    v
2--->3
There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
Note:

The number of nodes in the graph will be in the range [2, 15].
You can print different paths in any order, but you should keep the order of nodes inside one path

*/

class Solution
{
public:
    void dfs(vector<vector<int>> &graph, vector<int> &Subpaths, vector<vector<int>> &resultant_path, int source)
    {

        Subpaths.push_back(source);
        if (source == graph.size() - 1)
            resultant_path.push_back(Subpaths);
        else
        {
            for (int v : graph[source])
            {
                dfs(graph, Subpaths, resultant_path, v);
            }
        }
        Subpaths.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        vector<vector<int>> resultant_path;
        vector<int> Subpaths;
        dfs(graph, Subpaths, resultant_path, 0);
        return resultant_path;
    }
};