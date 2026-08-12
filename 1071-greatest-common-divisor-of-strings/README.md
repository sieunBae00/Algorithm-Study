<h2><a href="https://leetcode.com/problems/greatest-common-divisor-of-strings">1146. Greatest Common Divisor of Strings</a></h2><h3>Easy</h3><hr><p>For two strings <code>s</code> and <code>t</code>, we say &quot;<code>t</code> divides <code>s</code>&quot; if and only if <code>s = t + t + t + ... + t + t</code> (i.e., <code>t</code> is concatenated with itself one or more times).</p>

<p>Given two strings <code>str1</code> and <code>str2</code>, return <em>the largest string </em><code>x</code><em> such that </em><code>x</code><em> divides both </em><code>str1</code><em> and </em><code>str2</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">str1 = &quot;ABCABC&quot;, str2 = &quot;ABC&quot;</span></p>

<p><strong>Output:</strong> <span class="example-io">&quot;ABC&quot;</span></p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">str1 = &quot;ABABAB&quot;, str2 = &quot;ABAB&quot;</span></p>

<p><strong>Output:</strong> <span class="example-io">&quot;AB&quot;</span></p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">str1 = &quot;LEET&quot;, str2 = &quot;CODE&quot;</span></p>

<p><strong>Output:</strong> <span class="example-io">&quot;&quot;</span></p>
</div>

<p><strong class="example">Example 4:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">str1 = &quot;AAAAAB&quot;, str2 = &quot;AAA&quot;</span></p>

<p><strong>Output:</strong> <span class="example-io">&quot;&quot;</span>​​​​​​​</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= str1.length, str2.length &lt;= 1000</code></li>
	<li><code>str1</code> and <code>str2</code> consist of English uppercase letters.</li>
</ul>


---

### Idea

말하자면 '문자열의 최대공약수' 를 구하는 문제라고 할 수 있겠다.   
    
- 최대공약문자열: (의외로) 존재하는 개념이며, 최대공약수를 구하는 것과 크게 다르지 않다.     
  일단 최대공약문자열이 여러 번 반복된 것이 주어지는 두 문자열이다.     
  그렇다면 두 문자열의 최대공약문자열의 길이는 두 문자열 길이의 최대공약수보다 작거나 같게 된다.    
  (두 문자열이 모두 같은 문자로만 이루어져 있을 경우, 최대공약문자열은 한 글자가 된다.)        

	 
``` text
일단 이어붙인 두 개가 다르면? -> 가능성 없음. 애초에 반복되지 x.  "" 반환.
그러면 이어붙인 두 개가 같은 경우만 남음, -> 최대 길이 계산 후 뗴어서(`substr()`) 반환.
```
