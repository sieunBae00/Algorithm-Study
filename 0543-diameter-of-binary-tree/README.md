<h2><a href="https://leetcode.com/problems/diameter-of-binary-tree">543. Diameter of Binary Tree</a></h2><h3>Easy</h3><hr><p>Given the <code>root</code> of a binary tree, return <em>the length of the <strong>diameter</strong> of the tree</em>.</p>

<p>The <strong>diameter</strong> of a binary tree is the <strong>length</strong> of the longest path between any two nodes in a tree. This path may or may not pass through the <code>root</code>.</p>

<p>The <strong>length</strong> of a path between two nodes is represented by the number of edges between them.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/03/06/diamtree.jpg" style="width: 292px; height: 302px;" />
<pre>
<strong>Input:</strong> root = [1,2,3,4,5]
<strong>Output:</strong> 3
<strong>Explanation:</strong> 3 is the length of the path [4,2,1,3] or [5,2,1,3].
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> root = [1,2]
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[1, 10<sup>4</sup>]</code>.</li>
	<li><code>-100 &lt;= Node.val &lt;= 100</code></li>
</ul>

---

### Idea

처음 생각) 최소 공통 조상(LCA, Lowest Common Ancestor) 찾기, 조상 노드 ~ 각 노드 까지의 길이의 합 구하기.  
그러나..   
(1) 모든 노드 쌍에 대하여 거리를 구해야 함. -> 시간복잡도 `O(n^2)`  
(2) easy 문제에서 LCA 까지 안 나올 것 같은데...   
</br>

> 💡 '양 노드 쌍' 을 기준으로 생각하기보다, 처음부터 __'조상 노드'를 기준으로 생각__ 하기.   
> 노드 쌍 -> 최소 공통 조상 노드 구하기 (x)  
> 임의의 노드가 '최소 공통 노드' 라고 가정하고 -> 너를 LCA 로 하는 가장 긴 경로는 얼마이니? (o)  
> 가장 긴 경로 = 왼쪽 깊이 + 오른쪽 깊이 -> 원래의 `max_diameter` 보다 크다면 갱신
</br>

-⭐ 최대 지름 갱신 v.s. 깊이 반환    
  최대 지름 갱신(max_diameter): '거리' 기준이므로 `(왼쪽 깊이) + (오른쪽 깊이)` 합 자체로 판단. (현재 노드 +1 하지 x)  
  깊이 반환: 리프 노드의 깊이를 0으로 정하여 반환하므로 현재 노드를 +1.  

