<h2><a href="https://leetcode.com/problems/daily-temperatures">739. Daily Temperatures</a></h2><h3>Medium</h3><hr><p>Given an array of integers <code>temperatures</code> represents the daily temperatures, return <em>an array</em> <code>answer</code> <em>such that</em> <code>answer[i]</code> <em>is the number of days you have to wait after the</em> <code>i<sup>th</sup></code> <em>day to get a warmer temperature</em>. If there is no future day for which this is possible, keep <code>answer[i] == 0</code> instead.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> temperatures = [73,74,75,71,69,72,76,73]
<strong>Output:</strong> [1,1,4,2,1,1,0,0]
</pre><p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> temperatures = [30,40,50,60]
<strong>Output:</strong> [1,1,1,0]
</pre><p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> temperatures = [30,60,90]
<strong>Output:</strong> [1,1,0]
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;=&nbsp;temperatures.length &lt;= 10<sup>5</sup></code></li>
	<li><code>30 &lt;=&nbsp;temperatures[i] &lt;= 100</code></li>
</ul>


---

### Idea

'앞으로 다가올 날씨' 를 하나하나 검사하려면 시간이 오래 걸림 (이중 `for` 문)       
    
> 💡 대신, '아직 더 높은 기온을 발견하지 못한 과거' 를 저장해 두자.        

	  
스택의 `top()` 날짜의 기온이 오늘보다 낮다면, 오늘과 그 날짜의 차이를 비교하여 `ans` 배열에 저장 후 `pop()` 한다. <- **스택에는 `index` 를 저장한다.   
오늘보다 기온이 낮은 과거를 모두 `pop()` (= 기온 높은 날을 찾음) 한 후 오늘의 `index` 를 저장한다.(오늘 또한 오늘보다 기온 높은 날을 찾아야 하므로)   
`temperature` 배열을 모두 순회한 후에도 스택에 남아 있다면 -> 기온 높은 날을 찾지 못한 것. `ans` 배열에 `0` 을 저장한다.    
