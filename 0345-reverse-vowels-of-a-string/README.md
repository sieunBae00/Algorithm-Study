<h2><a href="https://leetcode.com/problems/reverse-vowels-of-a-string">345. Reverse Vowels of a String</a></h2><h3>Easy</h3><hr><p>Given a string <code>s</code>, reverse only all the vowels in the string and return it.</p>

<p>The vowels are <code>&#39;a&#39;</code>, <code>&#39;e&#39;</code>, <code>&#39;i&#39;</code>, <code>&#39;o&#39;</code>, and <code>&#39;u&#39;</code>, and they can appear in both lower and upper cases, more than once.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = &quot;IceCreAm&quot;</span></p>

<p><strong>Output:</strong> <span class="example-io">&quot;AceCreIm&quot;</span></p>

<p><strong>Explanation:</strong></p>

<p>The vowels in <code>s</code> are <code>[&#39;I&#39;, &#39;e&#39;, &#39;e&#39;, &#39;A&#39;]</code>. On reversing the vowels, s becomes <code>&quot;AceCreIm&quot;</code>.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = &quot;leetcode&quot;</span></p>

<p><strong>Output:</strong> <span class="example-io">&quot;leotcede&quot;</span></p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 3 * 10<sup>5</sup></code></li>
	<li><code>s</code> consist of <strong>printable ASCII</strong> characters.</li>
</ul>


---

### Idea

문제 이해) 모음만 골라, 그 순서를 reverse 하면 되는 문제다.    
   
가장 먼저 떠오르는 것은 스택이지만, 최대 `3*10^5` 길이의 문자열을 스택에 넣었다 뺄 수는 없으니...   
투포인터 느낌? 둘 다 모음이면 바꾸는 걸로..   
ㄴ모음인지 검사는 어떻게? '모음의 모음' 배열을 만들어 두어야 할 듯.    
</br>

- ⭐ array 와 vector   
  `array` 는 크기가 고정, 바꿀 수 없다. 스택 영역을 쓴다. vector 에 비해 빠르다.   
  `vector` 는 크기가 동적으로 변한다. 힙 영역을 쓴다.   
   
  => 이 문제에서 모음 배열의 크기는 바뀌지 않으므로 array 를 쓰면 된다.    
  array 를 쓸 경우, `.find()` 형태가 아닌 `find()` 형태를 써야 한다. (`.find()` 는 문자열 안에서 탐색하는 함수이다. 이 경우 배열이므로...)   
