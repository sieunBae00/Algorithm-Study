<h2><a href="https://leetcode.com/problems/count-good-nodes-in-binary-tree">1544. Count Good Nodes in Binary Tree</a></h2><h3>Medium</h3><hr><p>Given a binary tree <code>root</code>, a node <em>X</em> in the tree is named&nbsp;<strong>good</strong> if in the path from root to <em>X</em> there are no nodes with a value <em>greater than</em> X.</p>

<p>Return the number of <strong>good</strong> nodes in the binary tree.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2020/04/02/test_sample_1.png" style="width: 263px; height: 156px;" /></strong></p>

<pre>
<strong>Input:</strong> root = [3,1,4,3,null,1,5]
<strong>Output:</strong> 4
<strong>Explanation:</strong> Nodes in blue are <strong>good</strong>.
Root Node (3) is always a good node.
Node 4 -&gt; (3,4) is the maximum value in the path starting from the root.
Node 5 -&gt; (3,4,5) is the maximum value in the path
Node 3 -&gt; (3,1,3) is the maximum value in the path.</pre>

<p><strong class="example">Example 2:</strong></p>

<p><strong><img alt="" src="https://assets.leetcode.com/uploads/2020/04/02/test_sample_2.png" style="width: 157px; height: 161px;" /></strong></p>

<pre>
<strong>Input:</strong> root = [3,3,null,4,2]
<strong>Output:</strong> 3
<strong>Explanation:</strong> Node 2 -&gt; (3, 3, 2) is not good, because &quot;3&quot; is higher than it.</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> root = [1]
<strong>Output:</strong> 1
<strong>Explanation:</strong> Root is considered as <strong>good</strong>.</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the binary tree is in the range&nbsp;<code>[1, 10^5]</code>.</li>
	<li>Each node&#39;s value is between <code>[-10^4, 10^4]</code>.</li>
</ul>

---

### Idea

처음 생각).   
`root` 보다 큰 모든 노드에 대하여 검사. <- 길이 중복된다.    
부모(루트에서 가까운 것, `BFS`) 를 먼저 검사, 부모가 `good` 이고 내가 부모보다 크면 자식도 `good`.    
그렇지 않으먼 `good` 이 아니거나 / 다시 검사.   
리프->루트 내림차순이면 줄줄이 `good` 일 텐데, 그렇지 않은 이상 순서는 상관 없으므로 다시 검사.     
    
생각해 보면 `BFS` 말고 `DFS` 도 가능. (__`DFS` 도 부모 노드가 먼저 방문된다.__)   
-> `DFS()` 돌면서, 부모 노드의 `good` 여부를 전달, 부모 노드의 값도 전달.     
    
🛑 그런데 생각해보니 타고 올라가며 '다시 검사' 를 할 수가 없음.    
  
  
처음엔 `DFS` 동작을 하는 헬퍼 함수의 파라미터로 '부모 노드의 `good` 여부' 를 전달하려고 했다.    
그러나 결국엔 '부모 노드의 값' 도 전달해야 하고, 다시 `root` 쪽으로 거슬러 올라갈 수도 없으므로 코드기 복잡해진다.     

> 💡 '부모의 `good` 여부' 같은 거 말고, __'이제까지 내려오면서 마주한 가장 큰 값'__ 을 전달하자.    

-> 부모의 `good` 여부가 자식의 `good` 여부를 결정하는 로직에 영향을 미치지 않으므로 간단해진다. !! (그저 `good` 이면 정답 값에 하나를 더할 뿐이다.)   


