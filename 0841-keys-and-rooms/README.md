<h2><a href="https://leetcode.com/problems/keys-and-rooms">871. Keys and Rooms</a></h2><h3>Medium</h3><hr><p>There are <code>n</code> rooms labeled from <code>0</code> to <code>n - 1</code>&nbsp;and all the rooms are locked except for room <code>0</code>. Your goal is to visit all the rooms. However, you cannot enter a locked room without having its key.</p>

<p>When you visit a room, you may find a set of <strong>distinct keys</strong> in it. Each key has a number on it, denoting which room it unlocks, and you can take all of them with you to unlock the other rooms.</p>

<p>Given an array <code>rooms</code> where <code>rooms[i]</code> is the set of keys that you can obtain if you visited room <code>i</code>, return <code>true</code> <em>if you can visit <strong>all</strong> the rooms, or</em> <code>false</code> <em>otherwise</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> rooms = [[1],[2],[3],[]]
<strong>Output:</strong> true
<strong>Explanation:</strong> 
We visit room 0 and pick up key 1.
We then visit room 1 and pick up key 2.
We then visit room 2 and pick up key 3.
We then visit room 3.
Since we were able to visit every room, we return true.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> rooms = [[1,3],[3,0,1],[2],[0]]
<strong>Output:</strong> false
<strong>Explanation:</strong> We can not enter room number 2 since the only key that unlocks it is in that room.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>n == rooms.length</code></li>
	<li><code>2 &lt;= n &lt;= 1000</code></li>
	<li><code>0 &lt;= rooms[i].length &lt;= 1000</code></li>
	<li><code>1 &lt;= sum(rooms[i].length) &lt;= 3000</code></li>
	<li><code>0 &lt;= rooms[i][j] &lt; n</code></li>
	<li>All the values of <code>rooms[i]</code> are <strong>unique</strong>.</li>
</ul>

---

### Idea

그래프의 덩어리(영역) 개수..   
영역 개수가 `1` 이어야 (모든 노드를 방문할 수 있어야 = 모든 방문을 열 수 있어야) 한다. -> `True`    
   
아직 방문하지 않은 방만 추가로 열면 된다. => `visited[]` 배열     
   
탐색이 끝난 후 (더 이상 방문을 열 수 없을 때)    
`visited` 배열이 모두 `True` 인지 검사. (하나라도 방문 안한 방이 있으면 영역 개수는 `1` 이 아님)    
