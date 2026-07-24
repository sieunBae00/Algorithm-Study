<h2><a href="https://leetcode.com/problems/subtree-of-another-tree">572. Subtree of Another Tree</a></h2><h3>Easy</h3><hr><p>Given the roots of two binary trees <code>root</code> and <code>subRoot</code>, return <code>true</code> if there is a subtree of <code>root</code> with the same structure and node values of<code> subRoot</code> and <code>false</code> otherwise.</p>

<p>A subtree of a binary tree <code>tree</code> is a tree that consists of a node in <code>tree</code> and all of this node&#39;s descendants. The tree <code>tree</code> could also be considered as a subtree of itself.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/04/28/subtree1-tree.jpg" style="width: 532px; height: 400px;" />
<pre>
<strong>Input:</strong> root = [3,4,5,1,2], subRoot = [4,1,2]
<strong>Output:</strong> true
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/04/28/subtree2-tree.jpg" style="width: 502px; height: 458px;" />
<pre>
<strong>Input:</strong> root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the <code>root</code> tree is in the range <code>[1, 2000]</code>.</li>
	<li>The number of nodes in the <code>subRoot</code> tree is in the range <code>[1, 1000]</code>.</li>
	<li><code>-10<sup>4</sup> &lt;= root.val &lt;= 10<sup>4</sup></code></li>
	<li><code>-10<sup>4</sup> &lt;= subRoot.val &lt;= 10<sup>4</sup></code></li>
</ul>

---

### Idea

처음 생각) 일단 루트와 같은 값을 가지는 노드를 찾아야 한다. BST 가 아니므로 트리 전체를 순회하며 찾아야 함.   
- DFS 로 트리를 순회하며 subRoot 와 같은 값을 가지는 노드를 찾는다고 하자. 그 다음에는??   
  해당 노드를 반환,,? -> 그 노드로 다시 DFS, 처음에 같이 주어지는 subtree 에 대해서도 DFS. (배열에 저장) 값이 모두 같으먼 true.    
</br>

🛑 배열에 저장하는 방식 -> `nullptr` 파악이 불가,    
  and 위 방식에는 주어진 트리의 값이 `subRoot` 와 같을 경우가 '여러 번' 발생할 경우에 대한 로직이 포함되어 있지 않음.   
  (트리의 값(`node.val`) 이 unique 하다는 보장은 없다.)   
   
> 💡 값이 같으면, __그 노드를 root 로 하는 subtree 를 바로 검사__ 하는 식으로 !!   
> 즉, 모든 노드에 대하여 `isSameTree()` 를 호출하여 해당 노드를 root 로 하는 서브트리가 주어진 서브트리와 같은지 확인한다.   

- 🛑 `isSameTree()` 에서 단지 `n1 == n2` 를 비교하면 안 되는 이유   
  `n1`, `n2` 의 자료형은 `TreeNode*` 이다. 즉 포인터(주소) 이다.    
  따라서 두 노드의 값(`val`) 을 비교해야 하는데, `nullptr` 는 `val` 에 해당하지 않는다. 따라서 `nullptr` 에 대한 모든 부분을 명시적으로 검사해야 하는 것이다.   
