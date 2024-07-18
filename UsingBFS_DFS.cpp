#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <climits>
#include <initializer_list>


using namespace std;

// 미로의 각 셀을 나타내는 클래스
class Cell {
public:
    int row; // 행 인덱스
    int col; // 열 인덱스
    Cell(int r = 0, int c = 0) : row(r), col(c) {}
};

// 미로와 탐색 알고리즘을 포함하는 클래스
class Maze {
public:
    vector<vector<char> > map; // 미로의 구조
    vector<vector<bool> > visited; // 방문 여부 체크
    int MAZE_SIZE;

    // 생성자: 미로 초기화
    Maze(vector<vector<char> > input_map) {
        map = input_map;
        MAZE_SIZE = map.size();
        visited = vector<vector<bool> >(MAZE_SIZE, vector<bool>(map[0].size(), false));
    }

    // 주어진 위치가 유효한지 확인하는 메서드
    bool is_valid(int r, int c) {
        if (r < 0 || c < 0 || r >= MAZE_SIZE || c >= map[0].size())
            return false;
        if (visited[r][c] == true)
            return false;
        return map[r][c] == '0' || map[r][c] == 't';
    }

    // BFS 알고리즘 구현
    int bfs(Cell start, Cell end) {
        queue<pair<Cell, int> > q;
        q.push(make_pair(start, 0));
        visited[start.row][start.col] = true;

        int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // 상, 하, 좌, 우

        while (!q.empty()) {
            pair<Cell, int> current_pair = q.front();
            Cell current = current_pair.first;
            int distance = current_pair.second;
            q.pop();

            if (current.row == end.row && current.col == end.col)
                return distance;

            // 4방향 탐색
            for (int i = 0; i < 4; ++i) {
                int newRow = current.row + directions[i][0];
                int newCol = current.col + directions[i][1];

                if (is_valid(newRow, newCol)) {
                    visited[newRow][newCol] = true;
                    q.push(make_pair(Cell(newRow, newCol), distance + 1));
                }
            }
        }

        return -1; // 출구에 도달하지 못한 경우
    }

    // DFS 알고리즘 구현
    int dfs(Cell current, Cell end, int distance) {
        if (current.row == end.row && current.col == end.col) {
            return distance;
        }

        visited[current.row][current.col] = true;
        int result = INT_MAX;

        int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // 상, 하, 좌, 우

        // 4방향 탐색
        for (int i = 0; i < 4; ++i) {
            int newRow = current.row + directions[i][0];
            int newCol = current.col + directions[i][1];

            if (is_valid(newRow, newCol)) {
                result = min(result, dfs(Cell(newRow, newCol), end, distance + 1));
            }
        }

        visited[current.row][current.col] = false; // 백트래킹
        return result;
    }
};

int main() {
    // 미로 초기화
    std::vector<vector<char> > input_map;
    input_map.push_back({'1', '1', '1', '1', '1', '1'});
    input_map.push_back({'s', '0', '1', '0', '0', '0'});
    input_map.push_back({'1', '0', '0', '0', '1', '0'});
    input_map.push_back({'1', '0', '1', '0', '1', '0'});
    input_map.push_back({'1', '0', '1', '0', '1', '0'});
    input_map.push_back({'1', '1', '1', '1', '1', 't'});
    
    Maze maze(input_map);

    // 시작점과 도착점 찾기
    Cell start, end;
    for (int i = 0; i < maze.MAZE_SIZE; ++i) {
        for (int j = 0; j < maze.map[0].size(); ++j) {
            if (maze.map[i][j] == 's') {
                start = Cell(i, j);
            }
            if (maze.map[i][j] == 't') {
                end = Cell(i, j);
            }
        }
    }

    // BFS 탐색 실행 및 결과 출력
    int minDistBFS = maze.bfs(start, end);
    cout << "BFS: " << ((minDistBFS == -1) ? "No path found" : "Minimum distance: " + to_string(minDistBFS)) << endl;

    // DFS 탐색 실행 및 결과 출력
    fill(maze.visited.begin(), maze.visited.end(), vector<bool>(maze.MAZE_SIZE, false)); // 방문 배열 초기화
    int minDistDFS = maze.dfs(start, end, 0);
    cout << "DFS: " << ((minDistDFS == INT_MAX) ? "No path found" : "Minimum distance: " + to_string(minDistDFS)) << endl;

    return 0;
}