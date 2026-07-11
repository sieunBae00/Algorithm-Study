<h2><a href="https://leetcode.com/problems/can-place-flowers">605. Can Place Flowers</a></h2><h3>Easy</h3><hr><p>You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in <strong>adjacent</strong> plots.</p>

<p>Given an integer array <code>flowerbed</code> containing <code>0</code>&#39;s and <code>1</code>&#39;s, where <code>0</code> means empty and <code>1</code> means not empty, and an integer <code>n</code>, return <code>true</code>&nbsp;<em>if</em> <code>n</code> <em>new flowers can be planted in the</em> <code>flowerbed</code> <em>without violating the no-adjacent-flowers rule and</em> <code>false</code> <em>otherwise</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> flowerbed = [1,0,0,0,1], n = 1
<strong>Output:</strong> true
</pre><p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> flowerbed = [1,0,0,0,1], n = 2
<strong>Output:</strong> false
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= flowerbed.length &lt;= 2 * 10<sup>4</sup></code></li>
	<li><code>flowerbed[i]</code> is <code>0</code> or <code>1</code>.</li>
	<li>There are no two adjacent flowers in <code>flowerbed</code>.</li>
	<li><code>0 &lt;= n &lt;= flowerbed.length</code></li>
</ul>

---

### Idea

문제 태그가.. `greedy`?  
  
경우의 수는 다양하지만 특정 방법을 쓴다고 해서 더 많이 넣을 수는 없음.  
-> `greedy` 로 __일단 놓을 수 있으면 놓아 본다. !!__. 
</br>

- 첫 번째/마지막 원소에 대한 것 각각 따로 처리  
  (*원래 원소가 1이면 이미 flower 가 심어져 있는 것이므로 개수를 더하면 안 된다. !!)
  
- 배열 크기가 1일 경우 예외 케이스 처리  

