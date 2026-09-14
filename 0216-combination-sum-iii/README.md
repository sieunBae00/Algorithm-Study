<h2><a href="https://leetcode.com/problems/combination-sum-iii">216. Combination Sum III</a></h2><h3>Medium</h3><hr><p>Find all valid combinations of <code>k</code> numbers that sum up to <code>n</code> such that the following conditions are true:</p>

<ul>
	<li>Only numbers <code>1</code> through <code>9</code> are used.</li>
	<li>Each number is used <strong>at most once</strong>.</li>
</ul>

<p>Return <em>a list of all possible valid combinations</em>. The list must not contain the same combination twice, and the combinations may be returned in any order.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> k = 3, n = 7
<strong>Output:</strong> [[1,2,4]]
<strong>Explanation:</strong>
1 + 2 + 4 = 7
There are no other valid combinations.</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> k = 3, n = 9
<strong>Output:</strong> [[1,2,6],[1,3,5],[2,3,4]]
<strong>Explanation:</strong>
1 + 2 + 6 = 9
1 + 3 + 5 = 9
2 + 3 + 4 = 9
There are no other valid combinations.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> k = 4, n = 1
<strong>Output:</strong> []
<strong>Explanation:</strong> There are no valid combinations.
Using 4 different numbers in the range [1,9], the smallest sum we can get is 1+2+3+4 = 10 and since 10 &gt; 1, there are no valid combination.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= k &lt;= 9</code></li>
	<li><code>1 &lt;= n &lt;= 60</code></li>
</ul>


---

### Idea

문제 이해) 1~9 사이의 `k` 개 숫자를 활용하여, 그 합이 `n` 이 되도록 하는 모든 조합을 찾아 반환하기.     
    
백트래킹의 본질: brute-force.    
모든 길을 탐색해 보고자 마음을 먹는다. *단, 도중에 아닌 것 같으면 빨리 포기한다.     
</br>

- 🛑 '아닌 것 같은데' 검사 어떻게?    
  -> 이미 현재의 `sum` 이 `n` 을 초과했다면 -> 가망 없음. 되돌아가기.    
  -> 현재 고른 숫자가 `k` 개일때 `sum` 을 검사 -> `n` 이 아니면 실패. 되돌아가기.    
    
- '이미 사용한 숫자' 구현 어떻게?    
  -> `visited` 배열 같은 건 필요 없다. 무조건 '직전에 선택한 수보다 큰 수' 를 선택하도록 구현하면 된다.    
</br>

재귀함수에 필요한 파라미터(void): `k`, `n`, `ans` 2차원 배열, `path` 임시 바구니, 현재 바구니의 `sum`, 탐색을 시작할 숫자 `st_num`     
=> 파라미터가 6개.. 너무 많다. !!     
-> `k`, `n`, `ans` 배열은 '클래스의 멤버변수'로 두어 가볍게 하자.     
