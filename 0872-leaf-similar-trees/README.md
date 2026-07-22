<h2><a href="https://leetcode.com/problems/leaf-similar-trees">904. Leaf-Similar Trees</a></h2><h3>Easy</h3><hr><p>Consider all the leaves of a binary tree, from&nbsp;left to right order, the values of those&nbsp;leaves form a <strong>leaf value sequence</strong><em>.</em></p>

<p><img alt="" src="https://s3-lc-upload.s3.amazonaws.com/uploads/2018/07/16/tree.png" style="width: 400px; height: 336px;" /></p>

<p>For example, in the given tree above, the leaf value sequence is <code>(6, 7, 4, 9, 8)</code>.</p>

<p>Two binary trees are considered <em>leaf-similar</em>&nbsp;if their leaf value sequence is the same.</p>

<p>Return <code>true</code> if and only if the two given trees with head nodes <code>root1</code> and <code>root2</code> are leaf-similar.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/09/03/leaf-similar-1.jpg" style="width: 600px; height: 237px;" />
<pre>
<strong>Input:</strong> root1 = [3,5,1,6,2,9,8,null,null,7,4], root2 = [3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]
<strong>Output:</strong> true
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/09/03/leaf-similar-2.jpg" style="width: 300px; height: 110px;" />
<pre>
<strong>Input:</strong> root1 = [1,2,3], root2 = [1,3,2]
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in each tree will be in the range <code>[1, 200]</code>.</li>
	<li>Both of the given trees will have values in the range <code>[0, 200]</code>.</li>
</ul>

---

### Idea

DFS 로 트리를 순회하며 리프 노드를 저장. 저장된 노드의 순서와 값이 모두 일치하면 true.   
    
DFS 방식으로 재귀를 돌아야 하므로, `findLeaf()` 함수를 `void` 로 설계, `vector` 를 반환하는 것이 아닌 저장만 하도록 했다.   
</br>

- 🛑 함수로 배열을 전달: __참조에 의한 전달(Pass by Reference)__ 을 해야 한다.   
  값에 의한 전달(Pass by Value) 의 경우에는 배열의 원본이 전달되는 것이 아닌 복사본이 전달되므로,
  배열의 원본을 전달하기 위해 아래와 같이 참조에 의한 전달을 사용한다.    

```cpp
    void findLeaf(TreeNode* root, vector<int>& leaves){ // 배열 전달: 참조에 의한 전달
```
