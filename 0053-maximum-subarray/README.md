<h2><a href="https://leetcode.com/problems/maximum-subarray">53. Maximum Subarray</a></h2><h3>Medium</h3><hr><p>Given an integer array <code>nums</code>, find the <span data-keyword="subarray-nonempty">subarray</span> with the largest sum, and return <em>its sum</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> nums = [-2,1,-3,4,-1,2,1,-5,4]
<strong>Output:</strong> 6
<strong>Explanation:</strong> The subarray [4,-1,2,1] has the largest sum 6.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> nums = [1]
<strong>Output:</strong> 1
<strong>Explanation:</strong> The subarray [1] has the largest sum 1.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> nums = [5,4,-1,7,8]
<strong>Output:</strong> 23
<strong>Explanation:</strong> The subarray [5,4,-1,7,8] has the largest sum 23.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>4</sup> &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
</ul>

<p>&nbsp;</p>
<p><strong>Follow up:</strong> If you have figured out the <code>O(n)</code> solution, try coding another solution using the <strong>divide and conquer</strong> approach, which is more subtle.</p>

---

### Idea

121번 Best Time to Buy and Sell Stock 와 풀이 방식 같음.  
</br>

처음 생각) '누적합' 을 계산   
-> `(누적합 중 가장 큰 것)` - `(그보다 앞선 범위에서 누적합 중 음수이고 가장 작은 것)`  
  

- 🛑 '누적합 중 가장 큰 것' 이라는 로직에는 문제가 있음.  
  '원소 하나'로 된 부분합도 정답이 될 수 있기 때문.  
  예를 들어, 배열이 `[-3, 10, -20, 15]` 일 때,  
  누적합 배열은 `[-3, 7, -13, 2]` 이고 가장 큰 누적합은 `7` 이지만,  
  정답은 맨 뒤 원소인 `15` 가 된다.   
</br>

-> 로직 수정 필요. !!   

> 💡 `(오늘까지의 누적합)` - `(과거의 최소 누적합)` = `(오늘까지의 최대 부분배열의 합)`  
> `최대 부분배열의 합` 만 `max` 로 갱신하면 됨.  

** "최소 누적합"은 '오늘' 이 아닌 '과거' 기준이므로, 초기값을 `0` 으로 설정한다.   
(최대 부분배열의 합 과 마찬가지로 배열의 첫 번째 원소로 하게 되면,   
`max = hap[i] - min` 갱신 에서 `hap[i] = min` 인 상황에 __`max = 0 ⭐(빈 배열)`__ 이 될 수 있기 때문)  
  
배열 딱 한 번만 순회하면 됨. !! -> `max` 갱신

