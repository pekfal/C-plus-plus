#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int recursive(vector<string>& maps, int x, int y, int Min) {
    // 출구에 도달한 경우 현재 거리 반환
    if (maps[x][y] == 'F') {
        return Min;
    }

    int result = 0; 

    // 상하좌우 네 방향으로 이동
    if (x + 1 < maps.size() && maps[x + 1][y] != 'X') {
        result = min(result, recursive(maps, x + 1, y, Min + 1));
    }
    if (y + 1 < maps[0].size() && maps[x][y + 1] != 'X') {
        result = min(result, recursive(maps, x, y + 1, Min + 1));
    }
    if (x - 1 >= 0 && maps[x - 1][y] != 'X') {
        result = min(result, recursive(maps, x - 1, y, Min + 1));
    }
    if (y - 1 >= 0 && maps[x][y - 1] != 'X') {
        result = min(result, recursive(maps, x, y - 1, Min + 1));
    }

    return result;
}

int main() {
    vector<string> maps;
    maps.push_back("SOOOO");
    maps.push_back("XXXXO");
    maps.push_back("OOOOO");
    maps.push_back("OXXXX");
    maps.push_back("FOOOO");

    int startX = -1, startY = -1;
    for (int i = 0; i < maps.size(); ++i) {
        for (int j = 0; j < maps[0].size(); ++j) {
            if (maps[i][j] == 'S') {
                startX = i;
                startY = j;
                break;
            }
        }
        if (startX != -1) break; // 'S'를 찾으면 더 이상 탐색하지 않음
    }

    if (startX == -1 || startY == -1) {
        cout << -1 << endl;
        return 0; // 시작 지점을 찾을 수 없으면 -1 출력 후 종료
    }
    int minDist = recursive(maps, startX, startY, 0);

    cout << ((minDist == INT_MAX) ? -1 : minDist) << endl;

    return 0;
}
