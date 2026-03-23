#include <iostream>
using namespace std;
#include <vector>
#include <queue>
#include <tuple>

typedef tuple<int, int, int> road;

vector<int> house;

int find(int curr) {
    if (house[curr] == curr) return curr;
    else return find(house[curr]);
}

bool Union(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);

    if (rootA == rootB) return true; // 보스가 같다면 true를 return
    else {
        // 병합: 작은 쪽이 보스가 되도록 (어느 정도 예쁜-균형잡힌 트리가 되도록)
        if (rootA < rootB) house[rootB] = rootA;
        else house[rootA] = rootB;

        return false; // 보스가 다르다면 false를 return
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (true) {
        int m, n;
        cin >> m >> n;

        if (m == 0 && n == 0) break; // 입력의 끝이라면 -> 종료!


        priority_queue<road, vector<road>, greater<road>> pq; // 도로의 길이와 연결된 집 저장 (오름차순)

        // union-find 에 쓸 house 배열 초기화
        house.resize(m);
        for (int i = 0; i < house.size(); i++) {
            house[i] = i;
        }

        int all_hap = 0; // 존재하는 모든 도로의 길이 총합

        for (int i = 0; i < n; i++) {
            int x, y, z;
            cin >> x >> y >> z;

            pq.push({ z, x, y }); // 길의 거리 순으로 정렬 (오름차순)
            all_hap += z;
        }

        int cnt = 0; // 현재 연결된 도로 개수
        int road_hap = 0; //연결한 도로의 길이 총합

        while (cnt < m - 1) {
            int a = get<1>(pq.top());
            int b = get<2>(pq.top());

            if (Union(a, b)) { // 보스가 같다면 -> 연결할 경우 사이클 발생
                pq.pop();
            }
            else { // 보스가 다르다면 -> 연결! (병합)
                cnt++;
                road_hap += get<0>(pq.top());
                pq.pop();
            }
        }

        int ans = all_hap - road_hap; // 절약한 액수 계산

        cout << ans << '\n';
    }

    return 0;
}