<h2><a href="https://leetcode.com/problems/asteroid-collision">735. Asteroid Collision</a></h2><h3>Medium</h3><hr><p>We are given an array <code>asteroids</code> of integers representing asteroids in a row. The indices of the asteroid in the array represent their relative position in space.</p>

<p>For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.</p>

<p>Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> asteroids = [5,10,-5]
<strong>Output:</strong> [5,10]
<strong>Explanation:</strong> The 10 and -5 collide resulting in 10. The 5 and 10 never collide.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> asteroids = [8,-8]
<strong>Output:</strong> []
<strong>Explanation:</strong> The 8 and -8 collide exploding each other.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> asteroids = [10,2,-5]
<strong>Output:</strong> [10]
<strong>Explanation:</strong> The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.
</pre>

<p><strong class="example">Example 4:</strong></p>

<pre>
<strong>Input:</strong> asteroids = [3,5,-6,2,-1,4]​​​​​​​
<strong>Output:</strong> [-6,2,4]
<strong>Explanation:</strong> The asteroid -6 makes the asteroid 3 and 5 explode, and then continues going left. On the other side, the asteroid 2 destroys -1. Since 2 and 4 are both moving right, they never collide.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>2 &lt;= asteroids.length &lt;= 10<sup>4</sup></code></li>
	<li><code>-1000 &lt;= asteroids[i] &lt;= 1000</code></li>
	<li><code>asteroids[i] != 0</code></li>
</ul>


---

### Idea

처음 생각) 처음엔 왼->오 로 배열을 순회하려고 했다.   
그러나 정답 배열을 만들어야 하고, 이는 앞에서부터 맨 뒤에 `v.push_back()` 하는 게 낫다.   
(맨 앞에 추가하려고 `v.insert(v.begin, 값)` 하면 느리다)    

``` text
왼->오 로 배열을 순회하면서,    
양수면 정답 배열에 추가    
음수이면 정답 배열의 마지막과 비교(충돌) 하여 비교. (이 동작이 스택과 같다)    
```

*정답 배열의 마지막 원소가 이미 음수일 경우, 그대로 정답 배열에 추가.   
(특히, 주어지는 원소가 음수이고, 배열의 마지막 원소와 대결하여 승리하다가- 마지막 원소로 음수를 만나게 되었을 때.)    

#### Advanced
