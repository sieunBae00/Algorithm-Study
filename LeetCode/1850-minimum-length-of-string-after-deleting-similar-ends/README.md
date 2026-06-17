<h2><a href="https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends">Minimum Length of String After Deleting Similar Ends</a></h2> <img src='https://img.shields.io/badge/Difficulty-Medium-orange' alt='Difficulty: Medium' /><hr><p>Given a string <code>s</code> consisting only of characters <code>&#39;a&#39;</code>, <code>&#39;b&#39;</code>, and <code>&#39;c&#39;</code>. You are asked to apply the following algorithm on the string any number of times:</p>

<ol>
	<li>Pick a <strong>non-empty</strong> prefix from the string <code>s</code> where all the characters in the prefix are equal.</li>
	<li>Pick a <strong>non-empty</strong> suffix from the string <code>s</code> where all the characters in this suffix are equal.</li>
	<li>The prefix and the suffix should not intersect at any index.</li>
	<li>The characters from the prefix and suffix must be the same.</li>
	<li>Delete both the prefix and the suffix.</li>
</ol>

<p>Return <em>the <strong>minimum length</strong> of </em><code>s</code> <em>after performing the above operation any number of times (possibly zero times)</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;ca&quot;
<strong>Output:</strong> 2
<strong>Explanation: </strong>You can&#39;t remove any characters, so the string stays as is.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;cabaabac&quot;
<strong>Output:</strong> 0
<strong>Explanation:</strong> An optimal sequence of operations is:
- Take prefix = &quot;c&quot; and suffix = &quot;c&quot; and remove them, s = &quot;abaaba&quot;.
- Take prefix = &quot;a&quot; and suffix = &quot;a&quot; and remove them, s = &quot;baab&quot;.
- Take prefix = &quot;b&quot; and suffix = &quot;b&quot; and remove them, s = &quot;aa&quot;.
- Take prefix = &quot;a&quot; and suffix = &quot;a&quot; and remove them, s = &quot;&quot;.</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;aabccabba&quot;
<strong>Output:</strong> 3
<strong>Explanation:</strong> An optimal sequence of operations is:
- Take prefix = &quot;aa&quot; and suffix = &quot;a&quot; and remove them, s = &quot;bccabb&quot;.
- Take prefix = &quot;b&quot; and suffix = &quot;bb&quot; and remove them, s = &quot;cca&quot;.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code> only consists of characters <code>&#39;a&#39;</code>, <code>&#39;b&#39;</code>, and <code>&#39;c&#39;</code>.</li>
</ul>


---

### Idea

처음 생각) 연속되는 문자열을 확인하기 위해 한 쪽당 포인터를 두 개씩 둬야 하나?  
  
그러나 포인터를 두 개 더 쓸 필요 없이, 현재 문자를 저장하고 while 문을 도는 것만으로 처리 가능하다.  
</br>

``` text
포인터 `i`, `j` 가 각각 `string` 의 시작/끝 에서 출발한다.  
만약 두 포인터가 가리키는 문자가 같다면 -> `i`, `j` 를 각각 안쪽 방향으로 전진  
`i`, `j` 각각에 대하여, 전진했을 때의 문자가 현재 문자와 같다면 -> 연속된 문자이므로 `i`/`j` 를 안쪽 방향으로 전진 (반복)  
연속된 문자 모두 쳐낸 후, `i`, `j` 를 각각 안쪽 방향으로 전진 -> 다음 문자 검사  
두 포인터가 가리키는 문자가 같지 않다면 -> 즉시 종료 후 반환  
```
  
연속된 문자 검사를 위해 while 문을 돌 때, 모든 문자가 같은 경우 등 특이 케이스에 대하여 `i > j` 가 될 위험이 있으므로  
⭐ while 문에서도 `i <= j` 를 검사해야 한다. !!


