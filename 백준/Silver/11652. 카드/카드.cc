#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<long long> num;

    int N;
    cin >> N;

    num.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> num[i]; // 배열에 저장
    }

    sort(num.begin(), num.end()); // 배열을 정렬

    int curr(0), next(1); // 현재 인덱스, 다음 인덱스
    int cnt = 1; // 현재 숫자의 갯수
    int max_cnt = 1; // 가장 많은 숫자의 갯수
    long long ans = num[0]; // 최고 갯수인 카드의 번호

    while (next <= num.size() - 1) { // 배열에 끝에 도달할 때까지 반복
        if (num[curr] == num[next]) cnt++; // 같은 숫자라면 갯수 +1
        else cnt = 1; // 다른 숫자라면 갯수 초기화

        // 끝 부분에서 같은 숫자인 상태로 끝난다면 업데이트되지 못하므로, else 문 밖에 구현
        if (cnt > max_cnt) {// 현재 갯수가 최고 기록을 경신하면, 최고 기록을 업데이트
            max_cnt = cnt; // 갯수가 같다면 작은 숫자를 출력하므로, 갯수가 더 클 경우에만 업데이트
            ans = num[curr]; // 최고 갯수인 카드의 번호도 함께 업데이트
        }

        // 인덱스 한 칸씩 이동
        curr++;
        next++;
    }

    cout << ans << '\n';

    return 0;
}