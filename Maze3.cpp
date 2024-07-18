#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int recursive(vector<string>& maps, vector<vector<bool> >& visited, int x, int y, int depth) {
    int n = maps.size();
    int m = maps[0].size();

    // 범위를 벗어나거나 벽이거나 이미 방문한 곳인 경우
    if (x < 0 || x >= n || y < 0 || y >= m || maps[x][y] == 'X' || visited[x][y]) {
        return -1; // 이동 불가능한 경우 -1 반환
    }

    // 출구에 도착한 경우
    if (maps[x][y] == 'E') {
        return depth; // 현재 깊이 반환
    }

    visited[x][y] = true; // 현재 위치 방문 표시

    int minDist = -1; // 최소 거리 초기값을 -1로 설정 (이동 불가능을 의미)

    // 상하좌우 이동 시도
    if (x + 1 < n && maps[x + 1][y] != 'X') {
        minDist = max(minDist, recursive(maps, visited, x + 1, y, depth + 1));
    }
    if (x - 1 >= 0 && maps[x - 1][y] != 'X') {
        minDist = max(minDist, recursive(maps, visited, x - 1, y, depth + 1));
    }
    if (y + 1 < m && maps[x][y + 1] != 'X') {
        minDist = max(minDist, recursive(maps, visited, x, y + 1, depth + 1));
    }
    if (y - 1 >= 0 && maps[x][y - 1] != 'X') {
        minDist = max(minDist, recursive(maps, visited, x, y - 1, depth + 1));
    }

    visited[x][y] = false; // 현재 위치 방문 해제 (다른 경로 탐색을 위해)

    return minDist;
}

int solution(vector<string> maps) {
    int n = maps.size();
    int m = maps[0].size();

    vector<vector<bool> > visited(n, vector<bool>(m, false));

    // 시작 지점 찾기
    int start_x, start_y;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (maps[i][j] == 'S') {
                start_x = i;
                start_y = j;
                break;
            }
        }
    }

    return recursive(maps, visited, start_x, start_y, 0); // 최종 결과 반환
}

int main() {
    vector<string> maps;
    maps.push_back("SOOOO");
    maps.push_back("XXXXO");
    maps.push_back("OOOOO");
    maps.push_back("OXXXX");
    maps.push_back("EOOOO");
    cout << solution(maps) << endl; // Output: 11

    return 0;
}