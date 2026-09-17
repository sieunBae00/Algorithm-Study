<h2><a href="https://leetcode.com/problems/domino-and-tromino-tiling">806. Domino and Tromino Tiling</a></h2><h3>Medium</h3><hr><p>You have two types of tiles: a <code>2 x 1</code> domino shape and a tromino shape. You may rotate these shapes.</p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/07/15/lc-domino.jpg" style="width: 362px; height: 195px;" />
<p>Given an integer n, return <em>the number of ways to tile an</em> <code>2 x n</code> <em>board</em>. Since the answer may be very large, return it <strong>modulo</strong> <code>10<sup>9</sup> + 7</code>.</p>

<p>In a tiling, every square must be covered by a tile. Two tilings are different if and only if there are two 4-directionally adjacent cells on the board such that exactly one of the tilings has both squares occupied by a tile.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/07/15/lc-domino1.jpg" style="width: 500px; height: 226px;" />
<pre>
<strong>Input:</strong> n = 3
<strong>Output:</strong> 5
<strong>Explanation:</strong> The five different ways are shown above.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 1
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 1000</code></li>
</ul>


---

### Idea

D.P. -> '메모장' 에 적어두기.    
    
처음 생각)     
`n*2` 에서 domino tile 을 하나 놓으면 -> 문제 공간 축소.    
tromino tile 을 놓으면? -> 남은 타일이 홀수 -> ???    
    
=> 문제 공간이 축소된다는 생각보다, 이전 것으로부터 현재를 만들어낸다고 생각.    
(패턴 찾아서 점화식 세우기가 가장 어렵다...)    
</br>

- 완벽하게 채워진 `n*2` 칸을 만드는 법(`full[n]`)
      
  (1) `full[n-1]` 에 domino 를 하나 붙이는 경우    
  (2) `full[n-2]` 에 domino 2개를 눕혀 붙이는 경우    
  (3) `jagged[n-1]` 에 tromino 를 하나 붙이는 경우    

> 💡 점화식: `full[n] = full[n-1] + full[n-2] + jagged[n-1]`
</br>

- 그렇다면 어딘가 튀어나온 경우 (`jagged[n]`) 는 ?
      
  (1) `jagged[n-1]` 에 domino 를 눕혀 붙이는 경우    
  (2) `full[n-2]` 에 tromino 를 위 또는 아래 방향으로 붙이는 경우    

> 💡 점화식: `jagged[n] = jagged[n-1] + full[n-2]*2`


