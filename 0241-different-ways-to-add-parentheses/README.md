<h2><a href="https://leetcode.com/problems/different-ways-to-add-parentheses">241. Different Ways to Add Parentheses</a></h2><h3>Medium</h3><hr><p>Given a string <code>expression</code> of numbers and operators, return <em>all possible results from computing all the different possible ways to group numbers and operators</em>. You may return the answer in <strong>any order</strong>.</p>

<p>The test cases are generated such that the output values fit in a 32-bit integer and the number of different results does not exceed <code>10<sup>4</sup></code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> expression = &quot;2-1-1&quot;
<strong>Output:</strong> [0,2]
<strong>Explanation:</strong>
((2-1)-1) = 0 
(2-(1-1)) = 2
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> expression = &quot;2*3-4*5&quot;
<strong>Output:</strong> [-34,-14,-10,-10,10]
<strong>Explanation:</strong>
(2*(3-(4*5))) = -34 
((2*3)-(4*5)) = -14 
((2*(3-4))*5) = -10 
(2*((3-4)*5)) = -10 
(((2*3)-4)*5) = 10
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= expression.length &lt;= 20</code></li>
	<li><code>expression</code> consists of digits and the operator <code>&#39;+&#39;</code>, <code>&#39;-&#39;</code>, and <code>&#39;*&#39;</code>.</li>
	<li>All the integer values in the input expression are in the range <code>[0, 99]</code>.</li>
	<li>The integer values in the input expression do not have a leading <code>&#39;-&#39;</code> or <code>&#39;+&#39;</code> denoting the sign.</li>
</ul>

---

### Idea

문제 이해) 어떤 수식이 문자열로 주어지면, 그 수식에 모든 계산 순서에 따른 결과값 배열을 반환하기.  
  
연산자 하나당 피연산자 두 개. (부호를 나타내는 단한 연산자로써의 `+`, `-` 은 주어지지 않음)  
  
- 🛑 연산자 하나와 피연산자 두 개를 어떻게 묶어내지?  
  -> '괄호를 추가한다' 보다는, __"연산자를 기준으로 쪼갠다."__  
  
> 💡 __`substr()` + recursion !!__  
  
```text
문자열을 순회하다가, 연산자를 만나면 양쪽으로 쪼갠다.  
`substr()` 로 쪼갠 양쪽 문자열도 수식이므로, recursion 을 돈다.  
문자열을 끝까지 순회했는데 연산자가 없다면 -> 피연산자이므로 숫자를 배열에 담아 그대로 반환한다. (Base case!)  
양쪽에서 재귀를 돈 결과들(결과 ⭐"배열") 끼리 연산자로 계산한다. 계산 결과를 배열에 담아 반환한다.  
```
