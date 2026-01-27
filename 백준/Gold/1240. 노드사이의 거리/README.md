# [Gold V] 노드사이의 거리 - 1240 

[문제 링크](https://www.acmicpc.net/problem/1240) 

### 성능 요약

메모리: 2024 KB, 시간: 40 ms

### 분류

그래프 이론, 그래프 탐색, 트리, 너비 우선 탐색, 깊이 우선 탐색

### 제출 일자

2026년 1월 27일 02:53:53

### 문제 설명

<p><mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"> <mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>개의 노드로 이루어진 트리가 주어지고 M개의 두 노드 쌍을 입력받을 때 두 노드 사이의 거리를 출력하라.</p>

### 입력 

 <p>첫째 줄에 노드의 개수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N$</span></mjx-container>과 거리를 알고 싶은 노드 쌍의 개수 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D440 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>M</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$M$</span></mjx-container>이 입력되고 다음 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D441 TEX-I"></mjx-c></mjx-mi><mjx-mo class="mjx-n" space="3"><mjx-c class="mjx-c2212"></mjx-c></mjx-mo><mjx-mn class="mjx-n" space="3"><mjx-c class="mjx-c31"></mjx-c></mjx-mn></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>N</mi><mo>−</mo><mn>1</mn></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$N-1$</span></mjx-container>개의 줄에 트리 상에 연결된 두 점과 거리를 입력받는다. 그 다음 줄에는 거리를 알고 싶은 <mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"><mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D440 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>M</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$M$</span></mjx-container>개의 노드 쌍이 한 줄에 한 쌍씩 입력된다.</p>

### 출력 

 <p><mjx-container class="MathJax" jax="CHTML" style="font-size: 109%; position: relative;"> <mjx-math class="MJX-TEX" aria-hidden="true"><mjx-mi class="mjx-i"><mjx-c class="mjx-c1D440 TEX-I"></mjx-c></mjx-mi></mjx-math><mjx-assistive-mml unselectable="on" display="inline"><math xmlns="http://www.w3.org/1998/Math/MathML"><mi>M</mi></math></mjx-assistive-mml><span aria-hidden="true" class="no-mathjax mjx-copytext">$M$</span></mjx-container>개의 줄에 차례대로 입력받은 두 노드 사이의 거리를 출력한다.</p>

---

### Idea

- 처음 생각  
그래프 느낌.. 시작 노드에서 끝 노드까지의 길이 있는가?  
> 💡'트리'이므로, 무조건 길은 있다. (연결은 다 되어있음)


#### 두 노드의 연결 저장하기
- 처음엔 (N+1)*(N+1) 2차원 배열에 저장할까 생각함.  
🛑 그러면 direct 한 길이 있는지 확인하기 위해 N+1번을 일일히 확인해야 함.
> 💡 `vector<vector<pair<int, int>>>`배열을 만들어 `(연결된 노드 번호, 거리)` 를 저장하자.


#### 🛑거리는 어떻게 계산할 것인가?
'잘못 들은 길' 이라면 거리를 어떻게 처리할 것인가?
- 처음 생각: 일단 계속 더하면서 가고, 잘못된 길이면 그만큼만 __다시 빼자__. (<--구현 x)
> 다시 뺸다 -> 💡 잘못된 길이라면 더하지 말자. = __올바른 길을 찾으면 더하자.__ (찾으려는 노드가 아닌 경우 아무 액션도 하지 않음)

- 🛑거리를 실시간으로 `ans`에 더하면서 가면 빼야 할 일이 생김. (xx)
> 💡 '지금까지 온 거리'를 함께 넘겨준다. end 노드를 찾았을 때에만 `ans`에 거리를 저장한다.


#### 코드 다르게 쓰기
나는 dist 배열에서 찾던 노드와의 연결을 발견하면 그 노드를 방문하지 않고 바로 거리를 더해 `ans` 에 저장하도록 코드를 짰다.  
한편, 아래와 같이 우선 재귀를 돌고 `(현재 노드) == (찾던 노드)` 인지 확인하여 `ans`에 저장하는 식으로 코드를 쓸 수도 있다.

```
void trip(int s, int e, int sum) {
	if (s == e) {  // (현재 노드) == (찾던 노드) 인지 확인
		ans = sum;
		return;
	}

	visited[s] = true;

	for (p next : dist[s]) {
		if (!visited[next.first]) {  // 방문하지 않은 연결
			trip(next.first, e, sum + next.second);  // 일단 재귀를 돌자
		}
	}
	return;
}
```
