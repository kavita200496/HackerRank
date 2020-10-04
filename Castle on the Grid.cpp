typedef pair<int, int> Node;
struct NodeDistance {
    Node node;
    int distance;
};

// Complete the minimumMoves function below.
int minimumMoves(vector<string> grid, int startX, int startY, int goalX, int goalY) {
    int dir_x[4] = {0, 1, 0, -1};
    int dir_y[4] = {1, 0, -1, 0};
    int n = grid.size();

    queue<NodeDistance> q;
    Node start = {startX, startY};
    Node end = {goalX, goalY};
    vector<vector<bool>> visited(grid.size(), vector<bool> (grid.size()));
    q.push({start, 0});
    visited[startX][startY] = true;

    while (!q.empty()) {
        NodeDistance tmp = q.front();
        q.pop();
        int x = tmp.node.first;
        int y = tmp.node.second;
        if (tmp.node == end) return tmp.distance;

        for (int dir = 0; dir < 4; dir++) {
            int dx = dir_x[dir], dy = dir_y[dir];

            for (int i = x+dx, j = y+dy; i >= 0 && j >= 0 && i < n && j < n&&grid[i][j] == '.' ; i = i+dx, j = j+dy) {
                if (!visited[i][j]) {
                    visited[i][j] = true;
                    q.push({{i,j}, tmp.distance+1});
                }
            }
        }
    }
    return -1;

}
