<h2><a href="https://leetcode.com/problems/sum-root-to-leaf-numbers">129. Sum Root to Leaf Numbers</a></h2><h3>Medium</h3><hr><p>You are given the <code>root</code> of a binary tree containing digits from <code>0</code> to <code>9</code> only.</p>

<p>Each root-to-leaf path in the tree represents a number.</p>

<ul>
	<li>For example, the root-to-leaf path <code>1 -&gt; 2 -&gt; 3</code> represents the number <code>123</code>.</li>
</ul>

<p>Return <em>the total sum of all root-to-leaf numbers</em>. Test cases are generated so that the answer will fit in a <strong>32-bit</strong> integer.</p>

<p>A <strong>leaf</strong> node is a node with no children.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/19/num1tree.jpg" style="width: 212px; height: 182px;" />
<pre>
<strong>Input:</strong> root = [1,2,3]
<strong>Output:</strong> 25
<strong>Explanation:</strong>
The root-to-leaf path <code>1-&gt;2</code> represents the number <code>12</code>.
The root-to-leaf path <code>1-&gt;3</code> represents the number <code>13</code>.
Therefore, sum = 12 + 13 = <code>25</code>.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/02/19/num2tree.jpg" style="width: 292px; height: 302px;" />
<pre>
<strong>Input:</strong> root = [4,9,0,5,1]
<strong>Output:</strong> 1026
<strong>Explanation:</strong>
The root-to-leaf path <code>4-&gt;9-&gt;5</code> represents the number 495.
The root-to-leaf path <code>4-&gt;9-&gt;1</code> represents the number 491.
The root-to-leaf path <code>4-&gt;0</code> represents the number 40.
Therefore, sum = 495 + 491 + 40 = <code>1026</code>.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[1, 1000]</code>.</li>
	<li><code>0 &lt;= Node.val &lt;= 9</code></li>
	<li>The depth of the tree will not exceed <code>10</code>.</li>
</ul>

---

### Idea

결국 모든 리프 노드까지 이르는 경로를 모두 탐색해야 함.    
  
`DFS()`     
등장하는 숫자 합치는 것을 어떻게 구현할 것인가?   

``` text
- string 을 스택처럼 사용 -> 이후 int 로 변환
- 처음부터 int 로 *10 한 후 더하기
```
</br>

- 🛑 어떻게 리프 노드에 이르기까지의 경로를 하나의 숫자로 만들 것인가?
  
``` text
         1
       /   
     2      
    /  \
  3     4

예를 들어, 위와 같은 트리에서 DFS() 를 돈다면 1->2->3->2->4 의 순서가 될 것이다.  
그 과정에서, 어떻게 1->2->3 (123) 과 1->2->4 (124) 를 적절히 완성할 것인가?  
```
</br>

> 💡 `DFS()` 호출 시, __"지금까지의 숫자"를 함께 담아서__ 호출. !!

> `1->2->3` : `DFS()` 로 `3` 에 해당하는 노드 호출 시 `1->2` 인 상태(`12`)를 함께 인자로 전달  
> `1->2->4` : 마찬가지로 `4` 에 해당하는 노드 호출 시에도 똑같이 `1->2` 인 상태(`12`)를 인자로 전달   
