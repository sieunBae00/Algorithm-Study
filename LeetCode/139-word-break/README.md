<h2><a href="https://leetcode.com/problems/word-break">Word Break</a></h2> <img src='https://img.shields.io/badge/Difficulty-Medium-orange' alt='Difficulty: Medium' /><hr><p>Given a string <code>s</code> and a dictionary of strings <code>wordDict</code>, return <code>true</code> if <code>s</code> can be segmented into a space-separated sequence of one or more dictionary words.</p>

<p><strong>Note</strong> that the same word in the dictionary may be reused multiple times in the segmentation.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;leetcode&quot;, wordDict = [&quot;leet&quot;,&quot;code&quot;]
<strong>Output:</strong> true
<strong>Explanation:</strong> Return true because &quot;leetcode&quot; can be segmented as &quot;leet code&quot;.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;applepenapple&quot;, wordDict = [&quot;apple&quot;,&quot;pen&quot;]
<strong>Output:</strong> true
<strong>Explanation:</strong> Return true because &quot;applepenapple&quot; can be segmented as &quot;apple pen apple&quot;.
Note that you are allowed to reuse a dictionary word.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> s = &quot;catsandog&quot;, wordDict = [&quot;cats&quot;,&quot;dog&quot;,&quot;sand&quot;,&quot;and&quot;,&quot;cat&quot;]
<strong>Output:</strong> false
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length &lt;= 300</code></li>
	<li><code>1 &lt;= wordDict.length &lt;= 1000</code></li>
	<li><code>1 &lt;= wordDict[i].length &lt;= 20</code></li>
	<li><code>s</code> and <code>wordDict[i]</code> consist of only lowercase English letters.</li>
	<li>All the strings of <code>wordDict</code> are <strong>unique</strong>.</li>
</ul>

---

### Idea

만약 string 의 특정 범위 문자열이 wordDict 에 있다고 해서 바로 그대로 확정지으면 문제가 생긴다.  
-> 경우의 수를 전부 확인해 봐야 한다. 다만 효율적으로, Dynamic Programming!  
   
`f(n)`: n 번째 글자까지 도달 가능한지 여부 (T/F)  
`f(i)` <- 만약 `f(j)=true` 인 `j` 가 존재하고, `j~i` 위치를 잘라낸 문자열이 wordDict 에 존재하면 `true`.  
    
🛑 `f(j)=true` 인 `j` 가 존재하지 않는 경우는 어떻게 할 것인가? (초기값 설정 관련)  

> 💡 `ans[]` 배열의 사이즈를 주어진 string 사이즈보다 한 칸 크게 만들어, __0번째 인덱스를 '빈 문자열' 로 생각한다.__   
> (빈 문자열은 무조건 만들 수 있으므로, `ans[0]=true` 가 된다)   
> -> 초기값 문제 해결. !!  
</br>

- ⭐ __`unordered_set`: 해시 기반 자료구조__  
매번 wordDict[] 를 순회하며 i~j까지 잘라낸 문자열이 있는지 확인해야 한다면.. <- 비효율적   
`unordered_set` 을 사용하면 상수 시간(`O(1)`) 만에 삽입/삭제/탐색 이 가능하다.  
   
<`unordered_set` 의 특징>  
중복 원소 허용 x. / 특정 순서로 정렬 x. / 평균 `O(1)` 시간에 삽입/삭제/탐색 가능.  
