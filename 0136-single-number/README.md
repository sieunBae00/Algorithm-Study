<h2><a href="https://leetcode.com/problems/single-number">136. Single Number</a></h2><h3>Easy</h3><hr><p>Given a <strong>non-empty</strong>&nbsp;array of integers <code>nums</code>, every element appears <em>twice</em> except for one. Find that single one.</p>

<p>You must&nbsp;implement a solution with a linear runtime complexity and use&nbsp;only constant&nbsp;extra space.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [2,2,1]</span></p>

<p><strong>Output:</strong> <span class="example-io">1</span></p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [4,1,2,1,2]</span></p>

<p><strong>Output:</strong> <span class="example-io">4</span></p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [1]</span></p>

<p><strong>Output:</strong> <span class="example-io">1</span></p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>-3 * 10<sup>4</sup> &lt;= nums[i] &lt;= 3 * 10<sup>4</sup></code></li>
	<li>Each element in the array appears twice except for one element which appears only once.</li>
</ul>

---

### Idea

xor 연산의 속성을 활용하는 문제. 이 이외의 로직은 거의 필요하지 않다.    
    
#### xor 연산의 속성    
- __`A ^ A = 0`:__ 같은 숫자끼리 xor 하면 0이 된다.    
- __`0 ^ A = A`:__ 0과 어떤 숫자를 xor 하면 그 숫자 자신이 된다.    
- __`A ^ B ^ A` = `(A ^ A) ^ B`:__ 교환/결합 법칙. 순서에 상관없이 결과가 같다.    
    
위 법칙들을 적용한다면, 2번 등장하는 숫자들은 xor 하여 0이 될 것이고,    
단 한 번 등장하는 숫자만 0 과 xor 해서 살아남게 될 것이다.    
즉, __배열을 순회하며 모든 원소들을 xor 연산__ 한 뒤, 마지막 결과값이 정답이 된다.    

