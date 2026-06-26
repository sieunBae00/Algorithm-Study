<h2><a href="https://leetcode.com/problems/find-players-with-zero-or-one-losses">1354. Find Players With Zero or One Losses</a></h2><h3>Medium</h3><hr><p>You are given an integer array <code>matches</code> where <code>matches[i] = [winner<sub>i</sub>, loser<sub>i</sub>]</code> indicates that the player <code>winner<sub>i</sub></code> defeated player <code>loser<sub>i</sub></code> in a match.</p>

<p>Return <em>a list </em><code>answer</code><em> of size </em><code>2</code><em> where:</em></p>

<ul>
	<li><code>answer[0]</code> is a list of all players that have <strong>not</strong> lost any matches.</li>
	<li><code>answer[1]</code> is a list of all players that have lost exactly <strong>one</strong> match.</li>
</ul>

<p>The values in the two lists should be returned in <strong>increasing</strong> order.</p>

<p><strong>Note:</strong></p>

<ul>
	<li>You should only consider the players that have played <strong>at least one</strong> match.</li>
	<li>The testcases will be generated such that <strong>no</strong> two matches will have the <strong>same</strong> outcome.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> matches = [[1,3],[2,3],[3,6],[5,6],[5,7],[4,5],[4,8],[4,9],[10,4],[10,9]]
<strong>Output:</strong> [[1,2,10],[4,5,7,8]]
<strong>Explanation:</strong>
Players 1, 2, and 10 have not lost any matches.
Players 4, 5, 7, and 8 each have lost one match.
Players 3, 6, and 9 each have lost two matches.
Thus, answer[0] = [1,2,10] and answer[1] = [4,5,7,8].
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> matches = [[2,3],[1,3],[5,4],[6,4]]
<strong>Output:</strong> [[1,2,5,6],[]]
<strong>Explanation:</strong>
Players 1, 2, 5, and 6 have not lost any matches.
Players 3 and 4 each have lost two matches.
Thus, answer[0] = [1,2,5,6] and answer[1] = [].
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= matches.length &lt;= 10<sup>5</sup></code></li>
	<li><code>matches[i].length == 2</code></li>
	<li><code>1 &lt;= winner<sub>i</sub>, loser<sub>i</sub> &lt;= 10<sup>5</sup></code></li>
	<li><code>winner<sub>i</sub> != loser<sub>i</sub></code></li>
	<li>All <code>matches[i]</code> are <strong>unique</strong>.</li>
</ul>

---

### Idea  

문제 이해) 선수들의 경기 결과(승/패) 정보가 배열(`matches`)로 주어진다.  
`'진 적이 없는 선수들의 리스트'` & `'단 한 번만 진 선수들의 리스트'` 를 2차원 배열로 반환하면 된다.  
  
처음엔 `unordered_map` 에 "진 적이 있는" 선수만 저장 `(선수 번호, 진 횟수)` 하고,  
후에 "선수 번호를 순회"하며 `unordered_map` 에 존재하지 않는 선수는 이기기만 한 것으로 파악하려고 했다. 그러나...   
   
- 🛑 선수 번호를 어떻게 알지?   
문제에서 선수 번호에 대한 이야기가 없으므로, 연속된 숫자일지 듬성듬성일지 알 수 없다.   

> `unordered_map` 대신 `map` 사용. (자동 오름차순 정렬)  
> 💡 진 적이 없는 선수도 일단 `map` 에 등록한다. `(선수 번호, 진 횟수)`  
> `map` 을 순회하며 0 또는 1 의 값을 갖는 경우 `ans` 배열에 추가한다.  
</br>

- ⭐ `map<int, int>` 순회하기  
  순회 -> 순회자(`iterator`) 이용.   
  순회자로 `<first, second>` 에 접근하고 싶다면 `iterator->first`, `iterator->second` 이용.  

  ⭐ **순회 for 문 에서 `it < map.end();` 를 쓰지 않는 이유:   
    `map` 의 내부 구조는 트리이다. 즉 `vector` 처럼 다닥다닥 붙어있는 구조가 아니다.   
    따라서 `iterator` 도 더 작고/크고 를 판단할 수 없다.(다음 노드라고 해서 더 크다는 보장 x)   
    따라서 오직 마지막 노드인지 여부(`it != map.end()`) 를 판단하여 노드의 끝까지 순회한다.   

