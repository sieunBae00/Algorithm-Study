<h2><a href="https://leetcode.com/problems/guess-number-higher-or-lower">374. Guess Number Higher or Lower</a></h2><h3>Easy</h3><hr><p>We are playing the Guess Game. The game is as follows:</p>

<p>I pick a number from <code>1</code> to <code>n</code>. You have to guess which number I picked (the number I picked stays the same throughout the game).</p>

<p>Every time you guess wrong, I will tell you whether the number I picked is higher or lower than your guess.</p>

<p>You call a pre-defined API <code>int guess(int num)</code>, which returns three possible results:</p>

<ul>
	<li><code>-1</code>: Your guess is higher than the number I picked (i.e. <code>num &gt; pick</code>).</li>
	<li><code>1</code>: Your guess is lower than the number I picked (i.e. <code>num &lt; pick</code>).</li>
	<li><code>0</code>: your guess is equal to the number I picked (i.e. <code>num == pick</code>).</li>
</ul>

<p>Return <em>the number that I picked</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = 10, pick = 6
<strong>Output:</strong> 6
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 1, pick = 1
<strong>Output:</strong> 1
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> n = 2, pick = 1
<strong>Output:</strong> 1
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 2<sup>31</sup> - 1</code></li>
	<li><code>1 &lt;= pick &lt;= n</code></li>
</ul>

---

### Idea   

'이분 탐색' 처럼, `left`, `right` 의 가운데를 질의(`guess()`) 하여 얻은 결과를 바탕으로 가능한 범위를 수정해 나간다.   
`pick` 을 찾을 때까지 반복한다.  
</br>

- 🛑 `curr` 을 업데이트 시, `low + high` 를 하게 되면 오버플로우가 터진다.   
  `low`, `high` 의 자료형이 모두 `int` 이므로, `low+high` 의 연산 결과 또한 `int` 에 담기게 되는 것이다.    
  이를 방지하기 위해 `low`/`high` 둘 중 하나를 `long long` 으로 바꾸는 casting 을 할 수도 있겠지만,       
  ⭐ __수식을 살짝 변형하여 `int` 범위 내에서 해결__ 하도록 할 수 있다.    

  > 💡 `(low+high) / 2` == `low + (high-low) / 2 `  


