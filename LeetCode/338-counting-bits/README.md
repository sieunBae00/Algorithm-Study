<h2><a href="https://leetcode.com/problems/counting-bits">Counting Bits</a></h2> <img src='https://img.shields.io/badge/Difficulty-Easy-brightgreen' alt='Difficulty: Easy' /><hr><p>Given an integer <code>n</code>, return <em>an array </em><code>ans</code><em> of length </em><code>n + 1</code><em> such that for each </em><code>i</code><em> </em>(<code>0 &lt;= i &lt;= n</code>)<em>, </em><code>ans[i]</code><em> is the <strong>number of </strong></em><code>1</code><em><strong>&#39;s</strong> in the binary representation of </em><code>i</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = 2
<strong>Output:</strong> [0,1,1]
<strong>Explanation:</strong>
0 --&gt; 0
1 --&gt; 1
2 --&gt; 10
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 5
<strong>Output:</strong> [0,1,1,2,1,2]
<strong>Explanation:</strong>
0 --&gt; 0
1 --&gt; 1
2 --&gt; 10
3 --&gt; 11
4 --&gt; 100
5 --&gt; 101
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= n &lt;= 10<sup>5</sup></code></li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong></p>

<ul>
	<li>It is very easy to come up with a solution with a runtime of <code>O(n log n)</code>. Can you do it in linear time <code>O(n)</code> and possibly in a single pass?</li>
	<li>Can you do it without using any built-in function (i.e., like <code>__builtin_popcount</code> in C++)?</li>
</ul>

---

### Idea

이진수에서  
짝수 -> 가장 하위 비트 0  
홀수 -> 가장 하위 비트 1  
  
어떤 수에 2를 곱하면 -> 전체가 왼쪽으로 1비트씩 밀리면서, 가장 하위 비트는 0이 된다.  
어떤 짝수에 1을 더하면 -> 가장 하위 비트가 1이 된다.  

> 💡 어떤 짝수 i의 1의 개수 = i/2 가 가진 1의 개수  
> 💡 어떤 홀수 i 의 1의 개수 = i/2 가 가진 1의 개수 + 1  
  
- 1의 개수 counting 은 어떻게 할 것인가?  
  0~n 까지 "순차적으로" 채우며 앞에서 계산한 1의 개수를 이용해 뒤쪽 숫자의 1의 개수를 계산한다.  
