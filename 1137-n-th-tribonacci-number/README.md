<h2><a href="https://leetcode.com/problems/n-th-tribonacci-number">1236. N-th Tribonacci Number</a></h2><h3>Easy</h3><hr><p>The Tribonacci sequence T<sub>n</sub> is defined as follows:&nbsp;</p>

<p>T<sub>0</sub> = 0, T<sub>1</sub> = 1, T<sub>2</sub> = 1, and T<sub>n+3</sub> = T<sub>n</sub> + T<sub>n+1</sub> + T<sub>n+2</sub> for n &gt;= 0.</p>

<p>Given <code>n</code>, return the value of T<sub>n</sub>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = 4
<strong>Output:</strong> 4
<strong>Explanation:</strong>
T_3 = 0 + 1 + 1 = 2
T_4 = 1 + 1 + 2 = 4
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 25
<strong>Output:</strong> 1389537
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= n &lt;= 37</code></li>
	<li>The answer is guaranteed to fit within a 32-bit integer, ie. <code>answer &lt;= 2^31 - 1</code>.</li>
</ul>

---

### Idea

피보나치 수열이 바로 앞의 두 수를 더해 다음 수를 만드는 것이라면,   
이 문제는 tribonacci 로, 바로 앞의 세 수를 더해 다음 수를 만들게 된다.

피보나치(또는 트라이보나치) 의 `n` 번째 항을 구할 때, 재귀로 구현하면 시간복잡도가 매우 커지므로(`O(2^n)`, 또는 이 문제에서는 `O(3^n)`),    
처음부터 거슬러 올라가며 모든 항을 구하기로 한다.   
