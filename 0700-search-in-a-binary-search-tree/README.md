<h2><a href="https://leetcode.com/problems/search-in-a-binary-search-tree">783. Search in a Binary Search Tree</a></h2><h3>Easy</h3><hr><p>You are given the <code>root</code> of a binary search tree (BST) and an integer <code>val</code>.</p>

<p>Find the node in the BST that the node&#39;s value equals <code>val</code> and return the subtree rooted with that node. If such a node does not exist, return <code>null</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/01/12/tree1.jpg" style="width: 422px; height: 302px;" />
<pre>
<strong>Input:</strong> root = [4,2,7,1,3], val = 2
<strong>Output:</strong> [2,1,3]
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/01/12/tree2.jpg" style="width: 422px; height: 302px;" />
<pre>
<strong>Input:</strong> root = [4,2,7,1,3], val = 5
<strong>Output:</strong> []
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[1, 5000]</code>.</li>
	<li><code>1 &lt;= Node.val &lt;= 10<sup>7</sup></code></li>
	<li><code>root</code> is a binary search tree.</li>
	<li><code>1 &lt;= val &lt;= 10<sup>7</sup></code></li>
</ul>

---

### Idea

매우 간단한 논리의 문제이다.    
BST 의 특성을 이용하여, 찾으려는 값(`val`) 이 현재 노드(`root`) 보다 작으면 왼쪽, 크면 오른쪽으로 내려가다가 찾은 `val` 을 가진 노드를 반환한다.     
리프 노드에 도달할 때까지 같은 `val` 을 찾지 못하면 `null` 을 반환한다.   
