<h2><a href="https://leetcode.com/problems/simplify-path">Simplify Path</a></h2> <img src='https://img.shields.io/badge/Difficulty-Medium-orange' alt='Difficulty: Medium' /><hr><p>You are given an <em>absolute</em> path for a Unix-style file system, which always begins with a slash <code>&#39;/&#39;</code>. Your task is to transform this absolute path into its <strong>simplified canonical path</strong>.</p>

<p>The <em>rules</em> of a Unix-style file system are as follows:</p>

<ul>
	<li>A single period <code>&#39;.&#39;</code> represents the current directory.</li>
	<li>A double period <code>&#39;..&#39;</code> represents the previous/parent directory.</li>
	<li>Multiple consecutive slashes such as <code>&#39;//&#39;</code> and <code>&#39;///&#39;</code> are treated as a single slash <code>&#39;/&#39;</code>.</li>
	<li>Any sequence of periods that does <strong>not match</strong> the rules above should be treated as a <strong>valid directory or</strong> <strong>file </strong><strong>name</strong>. For example, <code>&#39;...&#39; </code>and <code>&#39;....&#39;</code> are valid directory or file names.</li>
</ul>

<p>The simplified canonical path should follow these <em>rules</em>:</p>

<ul>
	<li>The path must start with a single slash <code>&#39;/&#39;</code>.</li>
	<li>Directories within the path must be separated by exactly one slash <code>&#39;/&#39;</code>.</li>
	<li>The path must not end with a slash <code>&#39;/&#39;</code>, unless it is the root directory.</li>
	<li>The path must not have any single or double periods (<code>&#39;.&#39;</code> and <code>&#39;..&#39;</code>) used to denote current or parent directories.</li>
</ul>

<p>Return the <strong>simplified canonical path</strong>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">path = &quot;/home/&quot;</span></p>

<p><strong>Output:</strong> <span class="example-io">&quot;/home&quot;</span></p>

<p><strong>Explanation:</strong></p>

<p>The trailing slash should be removed.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">path = &quot;/home//foo/&quot;</span></p>

<p><strong>Output:</strong> <span class="example-io">&quot;/home/foo&quot;</span></p>

<p><strong>Explanation:</strong></p>

<p>Multiple consecutive slashes are replaced by a single one.</p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">path = &quot;/home/user/Documents/../Pictures&quot;</span></p>

<p><strong>Output:</strong> <span class="example-io">&quot;/home/user/Pictures&quot;</span></p>

<p><strong>Explanation:</strong></p>

<p>A double period <code>&quot;..&quot;</code> refers to the directory up a level (the parent directory).</p>
</div>

<p><strong class="example">Example 4:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">path = &quot;/../&quot;</span></p>

<p><strong>Output:</strong> <span class="example-io">&quot;/&quot;</span></p>

<p><strong>Explanation:</strong></p>

<p>Going one level up from the root directory is not possible.</p>
</div>

<p><strong class="example">Example 5:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">path = &quot;/.../a/../b/c/../d/./&quot;</span></p>

<p><strong>Output:</strong> <span class="example-io">&quot;/.../b/d&quot;</span></p>

<p><strong>Explanation:</strong></p>

<p><code>&quot;...&quot;</code> is a valid name for a directory in this problem.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= path.length &lt;= 3000</code></li>
	<li><code>path</code> consists of English letters, digits, period <code>&#39;.&#39;</code>, slash <code>&#39;/&#39;</code> or <code>&#39;_&#39;</code>.</li>
	<li><code>path</code> is a valid absolute Unix path.</li>
</ul>

---

### Idea

'/' 을 기준으로 문자열을 분리한다. -> `getline()` 함수를 이용한다.  
  
- ⭐ __`stringstream`__: 파이프(`|`) 역할을 한다.  
  
``` text
".": 현재 디렉토리를 나타낸다. 아무 동작도 하지 않는다.  
"..": 상위 디렉토리를 나타낸다. 바로 이전 문자열을 pop() 한다.  
"": 빈 문자열. "//" 와 같이 '/' 가 중복되어 등장했음을 의미한다. 아무 동작도 하지 않는다.  
이외의 문자열: 유효한 디렉토리 이름이다. push() 한다.  
```

> 💡 문자열 `push()`, `pop()` -> __스택__ 자료구조 !!  
> * 마지막에 문자열 하나로 합치기를 용이하게 하기 위해, `string` 을 `stack` 처럼 사용했다. (`push_back()`, `pop_back()`)  
