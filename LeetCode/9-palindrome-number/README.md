<h2><a href="https://leetcode.com/problems/palindrome-number">Palindrome Number</a></h2> <img src='https://img.shields.io/badge/Difficulty-Easy-brightgreen' alt='Difficulty: Easy' /><hr><p>Given an integer <code>x</code>, return <code>true</code><em> if </em><code>x</code><em> is a </em><span data-keyword="palindrome-integer"><em><strong>palindrome</strong></em></span><em>, and </em><code>false</code><em> otherwise</em>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> x = 121
<strong>Output:</strong> true
<strong>Explanation:</strong> 121 reads as 121 from left to right and from right to left.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> x = -121
<strong>Output:</strong> false
<strong>Explanation:</strong> From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> x = 10
<strong>Output:</strong> false
<strong>Explanation:</strong> Reads 01 from right to left. Therefore it is not a palindrome.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>-2<sup>31</sup>&nbsp;&lt;= x &lt;= 2<sup>31</sup>&nbsp;- 1</code></li>
</ul>

<p>&nbsp;</p>
<strong>Follow up:</strong> Could you solve it without converting the integer to a string?

---

### Idea

원래는 `int` 입력을 `string` 으로 바꾸어 풀어 보려 했으나.. (string 에서 인덱스 접근, 투포인터)  
  
Follow-Up 을 보면 string 으로 바꾸지 말고 푸는 것을 제안해서  
  
그냥 처음부터 string 변환 없이 풀어 보기로 했다.  
  

``` text
입력 x가 음수이면 반드시 대칭이 아니므로 false 을 return 한다.

10으로 나누어 마지막 자릿수를 분리.
반복하며 backward 에 자릿수 올리며 저장,
만약 10으로 나눈 몫이 한 자릿수라면 -> 그것이 마지막이므로 바로 몫까지 backward 에 저장.

backward 와 x 가 일치할 경우 true, 아니면 false를 return.
```
</br>

#### ⚠️ 주의할 부분  

- 몫(`tmp`)/나머지(`r`) 떼어내는 순서  
  반드시 나머지를 먼저 떼어낸다. 몫을 스스로를 업데이트하는 구조이므로 몫을 먼저 업데이트 후 나머지 계산 시 순서상 오류 발생.  
  
- `while` 문의 종결조건  
  `tmp = 0` 인 상황이면 -> 입력 `x` 의 맨 첫 자리가 0 인 상황. 즉 원래 0 은 표기되지 않았다. -> `backward` 에 추가하면 안 됨. !!  
  따라서 `tmp != 0` 검사 로직을 추가하고, while 문의 종결조건을 `tmp <= 0` 으로 삼는다.   
