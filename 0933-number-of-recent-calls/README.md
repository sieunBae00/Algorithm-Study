<h2><a href="https://leetcode.com/problems/number-of-recent-calls">969. Number of Recent Calls</a></h2><h3>Easy</h3><hr><p>You have a <code>RecentCounter</code> class which counts the number of recent requests within a certain time frame.</p>

<p>Implement the <code>RecentCounter</code> class:</p>

<ul>
	<li><code>RecentCounter()</code> Initializes the counter with zero recent requests.</li>
	<li><code>int ping(int t)</code> Adds a new request at time <code>t</code>, where <code>t</code> represents some time in milliseconds, and returns the number of requests that has happened in the past <code>3000</code> milliseconds (including the new request). Specifically, return the number of requests that have happened in the inclusive range <code>[t - 3000, t]</code>.</li>
</ul>

<p>It is <strong>guaranteed</strong> that every call to <code>ping</code> uses a strictly larger value of <code>t</code> than the previous call.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input</strong>
[&quot;RecentCounter&quot;, &quot;ping&quot;, &quot;ping&quot;, &quot;ping&quot;, &quot;ping&quot;]
[[], [1], [100], [3001], [3002]]
<strong>Output</strong>
[null, 1, 2, 3, 3]

<strong>Explanation</strong>
RecentCounter recentCounter = new RecentCounter();
recentCounter.ping(1);     // requests = [<u>1</u>], range is [-2999,1], return 1
recentCounter.ping(100);   // requests = [<u>1</u>, <u>100</u>], range is [-2900,100], return 2
recentCounter.ping(3001);  // requests = [<u>1</u>, <u>100</u>, <u>3001</u>], range is [1,3001], return 3
recentCounter.ping(3002);  // requests = [1, <u>100</u>, <u>3001</u>, <u>3002</u>], range is [2,3002], return 3
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= t &lt;= 10<sup>9</sup></code></li>
	<li>Each test case will call <code>ping</code> with <strong>strictly increasing</strong> values of <code>t</code>.</li>
	<li>At most <code>10<sup>4</sup></code> calls will be made to <code>ping</code>.</li>
</ul>

---

### Idea

문제 이해) `RecentCounter()` 로 최근 요청을 초기화한다.  
`ping(int t)` 로 `t` 밀리초때의 `ping` 요청이 주어진다.  
요청 시마다 근 3000 밀리초 내에 주어진 요청의 개수를 반환한다.  
*`t`는 모든 경우에 '증가하는 형태로' 주어진다.  
</br>

`t` 가 증가하는 형태로 주어지므로, 선입선출 자료구조인 `queue` 를 이용한다.    
-> `ping()` 요청이 올 때마다 큐에 `push()` 하고, 3000ms 보다 오래된 요청들은 큐에서 삭제(`pop()`) 한다.  
