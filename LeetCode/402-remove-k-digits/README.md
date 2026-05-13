<h2><a href="https://leetcode.com/problems/remove-k-digits">Remove K Digits</a></h2> <img src='https://img.shields.io/badge/Difficulty-Medium-orange' alt='Difficulty: Medium' /><hr><p>Given string num representing a non-negative integer <code>num</code>, and an integer <code>k</code>, return <em>the smallest possible integer after removing</em> <code>k</code> <em>digits from</em> <code>num</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> num = &quot;1432219&quot;, k = 3
<strong>Output:</strong> &quot;1219&quot;
<strong>Explanation:</strong> Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> num = &quot;10200&quot;, k = 1
<strong>Output:</strong> &quot;200&quot;
<strong>Explanation:</strong> Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> num = &quot;10&quot;, k = 2
<strong>Output:</strong> &quot;0&quot;
<strong>Explanation:</strong> Remove all the digits from the number and it is left with nothing which is 0.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= k &lt;= num.length &lt;= 10<sup>5</sup></code></li>
	<li><code>num</code> consists of only digits.</li>
	<li><code>num</code> does not have any leading zeros except for the zero itself.</li>
</ul>

---

### Idea

무조건 큰 수부터 지우면 x. 작은 숫자가 앞 자리에 위치해야 함.  
  
> 💡 방금 전 숫자보다 더 작은 숫자가 나오면, 방금 전 숫자를 지워서 작은 숫자가 높은 자릿수에 오게 만든다.  
> 방금 넣었던 걸 다시 뺸다 -> 스택 자료구조 사용  
  
** __c++ 에선 string 을 스택처럼 쓸 수 있다.__ `push_back()` / `pop_back()` 이용.  
(진짜 stack<int> 를 쓰면 마지막에 다시 배열하기 골치 아프다.)  

```
예외처리1) 맨 앞 자리에 0이 들어갈 경우: 처음부터 넣지 않는다.  
예외처리2) 12345 와 같이 뒤에 오는 숫자가 항상 더 클 경우 <- pop() 되지 않는다. : while 문 빠져나온 후 뒤에서부터(큰 수부터) k개 지운다.  
예외처리3) 숫자가 모두 지워져 ans 가 비어 있다면: 0을 출력한다.
```
