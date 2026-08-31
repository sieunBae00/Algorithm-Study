<h2><a href="https://leetcode.com/problems/delete-node-in-a-bst">450. Delete Node in a BST</a></h2><h3>Medium</h3><hr><p>Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return <em>the <strong>root node reference</strong> (possibly updated) of the BST</em>.</p>

<p>Basically, the deletion can be divided into two stages:</p>

<ol>
	<li>Search for a node to remove.</li>
	<li>If the node is found, delete the node.</li>
</ol>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/09/04/del_node_1.jpg" style="width: 800px; height: 214px;" />
<pre>
<strong>Input:</strong> root = [5,3,6,2,4,null,7], key = 3
<strong>Output:</strong> [5,4,6,2,null,null,7]
<strong>Explanation:</strong> Given key to delete is 3. So we find the node with value 3 and delete it.
One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
Please notice that another valid answer is [5,2,6,null,4,null,7] and it&#39;s also accepted.
<img alt="" src="https://assets.leetcode.com/uploads/2020/09/04/del_node_supp.jpg" style="width: 350px; height: 255px;" />
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> root = [5,3,6,2,4,null,7], key = 0
<strong>Output:</strong> [5,3,6,2,4,null,7]
<strong>Explanation:</strong> The tree does not contain a node with value = 0.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> root = [], key = 0
<strong>Output:</strong> []
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[0, 10<sup>4</sup>]</code>.</li>
	<li><code>-10<sup>5</sup> &lt;= Node.val &lt;= 10<sup>5</sup></code></li>
	<li>Each node has a <strong>unique</strong> value.</li>
	<li><code>root</code> is a valid binary search tree.</li>
	<li><code>-10<sup>5</sup> &lt;= key &lt;= 10<sup>5</sup></code></li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong> Could you solve it with time complexity <code>O(height of tree)</code>?</p>


---

### Idea

우선 삭제할 노드를 찾아야(탐색) 한다.     
     
- 🛑 찾으면 -> 그 찾은 노드를 삭제해야 하는데(=부모 노드의 포인터 변경)... 부모 노드로 거슬러 올라갈 수가 없다.    
  어쩌지? 자식에 도달하기 전에 부모 노드에서 멈춰야 하나?     
  그런데 삭제할 노드의 자식 또한 검사해야 하므로 부모, 자식 둘을 모두 저장해야 하겠네.. <- 구현 어떻게?      

> 💡 재귀(recursion) !!  `root->right = deleteNode(root->right, key);` 와 같이 쓰면,    
> 자식이 스스로를 지우고 `nullptr` 또는 다른 자식 노드를 반환하는 셈이 된다.      
> 따라서 부모 입장에서 `nullptr` 또는 (자식을 건너뛰고) '자식의 자식' 노드를 가리키게 되는 것.     
</br>   

- 🛑 자식이 2개인 경우 대체할 노드를 찾기 위한 헬퍼 함수(`findSub()`) 를 구현할 때, 헬퍼 함수에 '노드 찾기' + '노드 삭제' 기능을 모두 구현하려다 보니 코드가 꼬였다.    
  -> ⭐ 우린 이미 '노드 삭제' 함수를 구현했다. !! (`deleteNode()`)    
  따라서 헬퍼 함수는 노드를 찾게만 시키고, 반환해온 값으로 `deleteNode()` 의 재귀함수를 호출하면 된다.    
