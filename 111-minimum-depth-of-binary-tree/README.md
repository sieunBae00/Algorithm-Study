<h2><a href="https://leetcode.com/problems/minimum-depth-of-binary-tree">Minimum Depth of Binary Tree</a></h2> <img src='https://img.shields.io/badge/Difficulty-Easy-brightgreen' alt='Difficulty: Easy' /><hr><p>Given a binary tree, find its minimum depth.</p>

<p>The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.</p>

<p><strong>Note:</strong>&nbsp;A leaf is a node with no children.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/12/ex_depth.jpg" style="width: 432px; height: 302px;" />
<pre>
<strong>Input:</strong> root = [3,9,20,null,null,15,7]
<strong>Output:</strong> 2
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> root = [2,null,3,null,4,null,5,null,6]
<strong>Output:</strong> 5
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[0, 10<sup>5</sup>]</code>.</li>
	<li><code>-1000 &lt;= Node.val &lt;= 1000</code></li>
</ul>

---

### Idea  

트리의 최대 깊이(Max Depth)를 구할 때 `max(왼쪽 깊이, 오른쪽 깊이)+1`을 이용했던 것처럼,  
최소 깊이(Min Depth) 에서는 `min(왼쪽 깊이, 오른쪽 깊이)+1` 를 생각해볼 수 있다.  
</br>

``` text
루트 노드가 null (빈 트리) 라면 -> 0  
왼쪽/오른쪽 자식이 모두 존재하면 -> min(왼쪽 깊이, 오른쪽 깊이)+1  
왼쪽 자식만 존재하면 -> 왼쪽 깊이+1  
오른쪽 자식만 존재하면 -> 오른쪽 깊이+1  
리프 노드이면 -> 1  
```
