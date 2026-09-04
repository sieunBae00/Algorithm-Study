<h2><a href="https://leetcode.com/problems/binary-tree-right-side-view">199. Binary Tree Right Side View</a></h2><h3>Medium</h3><hr><p>Given the <code>root</code> of a binary tree, imagine yourself standing on the <strong>right side</strong> of it, return <em>the values of the nodes you can see ordered from top to bottom</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">root = [1,2,3,null,5,null,4]</span></p>

<p><strong>Output:</strong> <span class="example-io">[1,3,4]</span></p>

<p><strong>Explanation:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2024/11/24/tmpd5jn43fs-1.png" style="width: 400px; height: 207px;" /></p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">root = [1,2,3,4,null,null,null,5]</span></p>

<p><strong>Output:</strong> <span class="example-io">[1,3,4,5]</span></p>

<p><strong>Explanation:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2024/11/24/tmpkpe40xeh-1.png" style="width: 400px; height: 214px;" /></p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">root = [1,null,3]</span></p>

<p><strong>Output:</strong> <span class="example-io">[1,3]</span></p>
</div>

<p><strong class="example">Example 4:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">root = []</span></p>

<p><strong>Output:</strong> <span class="example-io">[]</span></p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[0, 100]</code>.</li>
	<li><code>-100 &lt;= Node.val &lt;= 100</code></li>
</ul>


---

### Idea

문제 이해) '트리의 각 층에서 가장 오른쪽에 있는 노드' 를 순서대로 배열에 담아 반환하면 된다.    
    
처음 생각)     
주어지는 배열에서 트리의 각 층은 1,2,4,8,... 개로 표현된다. 이것을 이용하여 가장 오른 쪽의 노드에 한 번에 접근할 수 있지 않을까? (nullptr 가 아닐 때까지 왼쪽으로 가면 됨. !!)     
그러나 애초에 배열 형태로 주어지는 것이 아니므로 배열 사이즈도 (조차) 알 수 없음. 탈락~     

	 
큐 사용, `pair` 형태로 `level` 을 함께 저장, 다른 층으로 바뀌기 전까지 현재 층의 가장 오른쪽 값을 계속 업데이트. 다음 층이 등장하면 현재 층의 값을 정답 배열에 저장.      
*마지막 층은 '다음 층' 이 등장하지 않으므로, `while` 문 이후 '큐의 마지막 값(`q.back()`)' 은 수동으로 `ans` 배열에 추가해 준다.      
