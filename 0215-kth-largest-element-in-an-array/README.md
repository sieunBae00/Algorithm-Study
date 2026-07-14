<h2><a href="https://leetcode.com/problems/kth-largest-element-in-an-array">215. Kth Largest Element in an Array</a></h2><h3>Medium</h3><hr><p>Given an integer array <code>nums</code> and an integer <code>k</code>, return <em>the</em> <code>k<sup>th</sup></code> <em>largest element in the array</em>.</p>

<p>Note that it is the <code>k<sup>th</sup></code> largest element in the sorted order, not the <code>k<sup>th</sup></code> distinct element.</p>

<p>Can you solve it without sorting?</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [3,2,1,5,6,4], k = 2
<strong>Output:</strong> 5
</pre><p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [3,2,3,1,2,4,5,5,6], k = 4
<strong>Output:</strong> 4
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>4</sup> &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
</ul>

---

### Idea

처음 생각) 배열의 원소들을 힙에 몽땅 넣었다가 하나씩 pop 할 수도 없고 (<< 최대힙),  
배열 내에서 가장 큰 수를 찾아 하나씩 pop 하기도 힘들 것 같고...
</br>

=> "힙" 에 대한 아이디어를 뒤집어 생각해 보자.    
`Max_heap` 대신, __`Min_heap` 을 사용__ 하면 보다 간단하고 빠르게 문제를 해결할 수 있다.    
   
> `Min_heap` 을 사용하고, 배열의 원소들을 하나씩 `push()` 한다.  
> 이때, 💡 __힙의 원소를 `k` 개로 유지__ 한다.   
> -> 배열 순회 후, 배열에서 가장 큰 `k` 개의 원소가 힙에 남게 된다.   
> --> 배열 순회 후, 힙의 `top()` 이 `k` 번째로 큰 원소가 된다.    
