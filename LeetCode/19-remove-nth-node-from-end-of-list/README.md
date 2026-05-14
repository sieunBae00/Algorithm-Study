<h2><a href="https://leetcode.com/problems/remove-nth-node-from-end-of-list">Remove Nth Node From End of List</a></h2> <img src='https://img.shields.io/badge/Difficulty-Medium-orange' alt='Difficulty: Medium' /><hr><p>Given the <code>head</code> of a linked list, remove the <code>n<sup>th</sup></code> node from the end of the list and return its head.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/10/03/remove_ex1.jpg" style="width: 542px; height: 222px;" />
<pre>
<strong>Input:</strong> head = [1,2,3,4,5], n = 2
<strong>Output:</strong> [1,2,3,5]
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> head = [1], n = 1
<strong>Output:</strong> []
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> head = [1,2], n = 1
<strong>Output:</strong> [1]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the list is <code>sz</code>.</li>
	<li><code>1 &lt;= sz &lt;= 30</code></li>
	<li><code>0 &lt;= Node.val &lt;= 100</code></li>
	<li><code>1 &lt;= n &lt;= sz</code></li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong> Could you do this in one pass?</p>


---

---

### Idea

🛑 연결 리스트는 next 만 포인터로 가리키는데, 어떻게 뒤에서 n번째 노드로 되돌아올 것인가?  
-> 💡 되돌아오는 게 아니라, 다시 head 부터 시작해서 두 번 돈다. !! (two pass)    

``` text
1. 전체 노드의 개수(cnt) 구하기  
2. cnt-n 번째 노드 찾기  
3. 노드 삭제하기 (n-1번 노드를 n+1번 노드에 연결)  
```
  
- ⭐ 예외 케이스 처리:  head 노드가 지워지는 경우  
  `(cnt == n)` 인 경우, 즉 뒤에서 cnt 번째 노드를 지우는 경우 => 뒤에서 cnt 번째 노드는 head 노드이므로 head 노드를 지워야 한다.  
  head 를 지우는 경우에는 단순히 head->next 를 새로운 head 로 하여 return 하면 된다.  

- one pass 로 푸는 법?  
  연결 리스트를 한 번만 훑어서 풀고 싶다면, 포인터 두 개를 사용하여 간격을 유지하면 된다.  
