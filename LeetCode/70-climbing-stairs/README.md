<h2><a href="https://leetcode.com/problems/climbing-stairs">Climbing Stairs</a></h2> <img src='https://img.shields.io/badge/Difficulty-Easy-brightgreen' alt='Difficulty: Easy' /><hr><p>You are climbing a staircase. It takes <code>n</code> steps to reach the top.</p>

<p>Each time you can either climb <code>1</code> or <code>2</code> steps. In how many distinct ways can you climb to the top?</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> n = 2
<strong>Output:</strong> 2
<strong>Explanation:</strong> There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> n = 3
<strong>Output:</strong> 3
<strong>Explanation:</strong> There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 45</code></li>
</ul>

---

### Idea

`백준 2579 계단 오르기` 문제와 비슷해 보이지만 더 간단한 문제.  
계단 오르기 문제와 달리 계단마다의 점수가 없다.  

``` text
n 번째 계단에 도달하는 경우의 수:
1. n-1 번째 계단을 밟고 올라오는 경우  
2. n-2 번째 계단을 밟고 올라오는 경우
```
  
경우의 수를 구하는 문제이므로 f(1) 을 1로, f(2) 를 2로 초기값을 세팅한 후 f(n)까지를 채우면 된다.  
`f(n) = f(n-1) + f(n-2)`  
