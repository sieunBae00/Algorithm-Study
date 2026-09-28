<h2><a href="https://leetcode.com/problems/string-compression">443. String Compression</a></h2><h3>Medium</h3><hr><p>Given an array of characters <code>chars</code>, compress it using the following algorithm:</p>

<p>Begin with an empty string <code>s</code>. For each group of <strong>consecutive repeating characters</strong> in <code>chars</code>:</p>

<ul>
	<li>If the group&#39;s length is <code>1</code>, append the character to <code>s</code>.</li>
	<li>Otherwise, append the character followed by the group&#39;s length.</li>
</ul>

<p>The compressed string <code>s</code> <strong>should not be returned separately</strong>, but instead, be stored <strong>in the input character array <code>chars</code></strong>. Note that group lengths that are <code>10</code> or longer will be split into multiple characters in <code>chars</code>.</p>

<p>After you are done <strong>modifying the input array,</strong> return <em>the new length of the array</em>.</p>

<p>You must write an algorithm that uses only constant extra space.</p>

<p><strong>Note: </strong>The characters in the array beyond the returned length do not matter and should be ignored.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> chars = [&quot;a&quot;,&quot;a&quot;,&quot;b&quot;,&quot;b&quot;,&quot;c&quot;,&quot;c&quot;,&quot;c&quot;]
<strong>Output:</strong> 6
<strong>Explanation:</strong> The groups are <code>&quot;aa&quot;</code>, <code>&quot;bb&quot;</code>, and <code>&quot;ccc&quot;</code>. This compresses to <code>&quot;a2b2c3&quot;</code>.
After modifying the input array in-place, the first 6 characters of <code>chars</code> should be <code>[&quot;a&quot;,&quot;2&quot;,&quot;b&quot;,&quot;2&quot;,&quot;c&quot;,&quot;3&quot;]</code>.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> chars = [&quot;a&quot;]
<strong>Output:</strong> 1
<strong>Explanation:</strong> The only group is <code>&quot;a&quot;</code>, which remains uncompressed since it is a single character.
After modifying the input array in-place, the first character of <code>chars</code> should be <code>[&quot;a&quot;]</code>.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> chars = [&quot;a&quot;,&quot;b&quot;,&quot;b&quot;,&quot;b&quot;,&quot;b&quot;,&quot;b&quot;,&quot;b&quot;,&quot;b&quot;,&quot;b&quot;,&quot;b&quot;,&quot;b&quot;,&quot;b&quot;,&quot;b&quot;]
<strong>Output:</strong> 4
<strong>Explanation:</strong> The groups are <code>&quot;a&quot;</code> and <code>&quot;bbbbbbbbbbbb&quot;</code>. This compresses to <code>&quot;ab12&quot;</code>.
After modifying the input array in-place, the first 4 characters of <code>chars</code> should be <code>[&quot;a&quot;,&quot;b&quot;,&quot;1&quot;,&quot;2&quot;]</code>.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= chars.length &lt;= 2000</code></li>
	<li><code>chars[i]</code> is a lowercase English letter, uppercase English letter, digit, or symbol.</li>
</ul>


---

### Idea

처음 생각)    
새로운 정답 배열을 만들기 x. 입력으로 들어오는 `chars` 배열을 수정해야 함.     
     
같으면 -> 현재 위치 erase     
다르면 -> 현재 위치에 cnt 추가하고 다음으로.     
</br>

🛑 ** `erase()` 는 필연적으로 `shift` 발생. <- time limit exceeded!     
    
** compression 한 정답 배열 자체도 존재해야 하는 것 아닌가?    
-> 맞음. 그런데 채점 시 원본 배열로부터 '반환값(크기) 만큼만 떼어서' 검사함. -> 직접 뒤쪽 자를 필요 x.   
   
투포인터로.. `read & write`   
`read`: 같은 것이 나올 동안 계속 전진(개수 세기)    
`write`: 더 이상 같은 것이 아니면, 해당 문자와 그 개수를 `write` 자리에 덮어쓰기.   
