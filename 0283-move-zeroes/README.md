<h2><a href="https://leetcode.com/problems/move-zeroes">283. Move Zeroes</a></h2><h3>Easy</h3><hr><p>Given an integer array <code>nums</code>, move all <code>0</code>&#39;s to the end of it while maintaining the relative order of the non-zero elements.</p>

<p><strong>Note</strong> that you must do this in-place without making a copy of the array.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> nums = [0,1,0,3,12]
<strong>Output:</strong> [1,3,12,0,0]
</pre><p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> nums = [0]
<strong>Output:</strong> [0]
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>4</sup></code></li>
	<li><code>-2<sup>31</sup> &lt;= nums[i] &lt;= 2<sup>31</sup> - 1</code></li>
</ul>

<p>&nbsp;</p>
<strong>Follow up:</strong> Could you minimize the total number of operations done?


---

### Idea

문제 이해) 배열 내의 모든 `0` 을 배열의 끝으로 이동시켜야 한다. *`in-place` 가 요구된다.  
</br>

처음 생각)   
먼저 '추가 공간이 허용될 때'의 방법을 생각해 보자.   
-> 정답 배열을 하나 두고, 배열에서 하나씩 꺼내서 넣는다.   
0 이면 cnt 후 무시, 나머지를 순서대로 넣고 마지막에 cnt 로 센 개수만큼 0을 추가.  
  
추가 공간 없이 하려면...   
-> 0 등장 시마다 shift 하기는 좀 그럼   
-> 포인터 두 개로.. 하나는 0, 하나는 0 이후의 수를 가리키도록. -> 0이고 && 다른 수라면 => swap   
  
🛑 로직이 복잡해지고 예외 케이스 처리가 쉽지 않음.  
-> `slow`, `fast` 포인터 도입 (`27. Remove Element` 참고)  
</br>

- 💡 주목할 점: `slow` 는 '0인 자리' 에만 멈추는 게 아니다.   
  `slow` 도 무조건 한 칸씩 전진한다. `slow` 가 0인지/아닌지는 상관 x, `fast` 가 0이 아닐 때 `swap()` 하는 것.   
</br>

- `slow`, `fast` 둘 다 0이 아니면?   
  0을 만날 때까지는 `slow == fast` 인 상태에서 `swap()` 한다.(`slow == fast` 인 상태이므로 자기자신과 `swap()` 하여 배열의 변화는 일어나지 않는다.)    
  0을 만나면 아무 동작 하지 않고 `fast` 만 한 칸 전진, 즉 `slow` 는 그대로 0에 머물러 있게 된다.
  `fast` 가 전진하다가 0이 아닌 수를 만나면 둘을 `swap()`. 0이 뒤쪽으로 옮겨가게 된다.

