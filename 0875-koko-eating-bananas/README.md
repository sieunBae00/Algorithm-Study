<h2><a href="https://leetcode.com/problems/koko-eating-bananas">907. Koko Eating Bananas</a></h2><h3>Medium</h3><hr><p>Koko loves to eat bananas. There are <code>n</code> piles of bananas, the <code>i<sup>th</sup></code> pile has <code>piles[i]</code> bananas. The guards have gone and will come back in <code>h</code> hours.</p>

<p>Koko can decide her bananas-per-hour eating speed of <code>k</code>. Each hour, she chooses some pile of bananas and eats <code>k</code> bananas from that pile. If the pile has less than <code>k</code> bananas, she eats all of them instead and will not eat any more bananas during this hour.</p>

<p>Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.</p>

<p>Return <em>the minimum integer</em> <code>k</code> <em>such that she can eat all the bananas within</em> <code>h</code> <em>hours</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> piles = [3,6,7,11], h = 8
<strong>Output:</strong> 4
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> piles = [30,11,23,4,20], h = 5
<strong>Output:</strong> 30
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> piles = [30,11,23,4,20], h = 6
<strong>Output:</strong> 23
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= piles.length &lt;= 10<sup>4</sup></code></li>
	<li><code>piles.length &lt;= h &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= piles[i] &lt;= 10<sup>9</sup></code></li>
</ul>


---

### Idea

처음 생각)    
주어지는 더미의 최소/최대 내에서 이분탐색?    
어떤 `k` 일때 '되네' 여도 끝이 아니다. 가장 작은 `k` 를 찾아야 한다.    
'되네' 면 작게, '안되네' 면 크게. .... `min < max` 일 동안 반복.    
`while` 문을 탈출하면? 그게(`min/max`) 정답인거지...    
    
** `min` 의 초기화: '주어지는 더미의 최소값' 이 아닌, 무조건 `1`로 초기화한다. 매우 긴 시간이 주어져 한 개씩만 먹어도 충분한 상황이 가능하기 떄문.     
    
`k` 일때 '되는지' 검사하기    
    
-⭐ 마지막 `return` 값 - `min` ? `max` ? 무엇을 return 하지?    
  결론은 '아무거나 `return` 해도 상관 없다'.    
  애초에 `max = mid` 또는 `min = mid + 1` 로 범위를 업데이트하므로, `min > max` 가 될 일은 없기 때문이다.    
  언제나 `while` 문 종료 후에는 `min == max` 가 된다. 따라서 둘 중 아무거나 `return` 하면 된다.    
  
