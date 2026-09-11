<h2><a href="https://leetcode.com/problems/number-of-provinces">547. Number of Provinces</a></h2><h3>Medium</h3><hr><p>There are <code>n</code> cities. Some of them are connected, while some are not. If city <code>a</code> is connected directly with city <code>b</code>, and city <code>b</code> is connected directly with city <code>c</code>, then city <code>a</code> is connected indirectly with city <code>c</code>.</p>

<p>A <strong>province</strong> is a group of directly or indirectly connected cities and no other cities outside of the group.</p>

<p>You are given an <code>n x n</code> matrix <code>isConnected</code> where <code>isConnected[i][j] = 1</code> if the <code>i<sup>th</sup></code> city and the <code>j<sup>th</sup></code> city are directly connected, and <code>isConnected[i][j] = 0</code> otherwise.</p>

<p>Return <em>the total number of <strong>provinces</strong></em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/12/24/graph1.jpg" style="width: 222px; height: 142px;" />
<pre>
<strong>Input:</strong> isConnected = [[1,1,0],[1,1,0],[0,0,1]]
<strong>Output:</strong> 2
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/12/24/graph2.jpg" style="width: 222px; height: 142px;" />
<pre>
<strong>Input:</strong> isConnected = [[1,0,0],[0,1,0],[0,0,1]]
<strong>Output:</strong> 3
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 200</code></li>
	<li><code>n == isConnected.length</code></li>
	<li><code>n == isConnected[i].length</code></li>
	<li><code>isConnected[i][j]</code> is <code>1</code> or <code>0</code>.</li>
	<li><code>isConnected[i][i] == 1</code></li>
	<li><code>isConnected[i][j] == isConnected[j][i]</code></li>
</ul>


---

### Idea

문제 이해) '연결 요소의 개수' 찾기.    
-> DFS 를 몇 번 돌아야 전체를 방문할 수 있는지 구한다.    
</br>

- 🛑 간선 정보는 `n*n` 인접 행렬로 주어진다.    
  '인접 리스트' 형태에 익숙한 나머지, 처음에 다음과 같이 코드를 작성했다.    

``` cpp
for(int next : isConnected[curr]){
    if(next == 1 && !visited[next]) DFS(next, isConnected, visited);
}
```

위와 같이 코드를 작성하면 `next` 에는 노드의 인덱스 값이 들어가는 것이 아닌 0 또는 1의 값이 들어가게 되고,         
`DFS(1, ...);` 이 되어 인덱스가 `1`인 노드로만 계속해서 탐색을 시도하게 된다. 따라서 값이 아닌 인덱스를 순회하는 형태로 변경해야 한다.     
