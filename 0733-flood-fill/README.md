<h2><a href="https://leetcode.com/problems/flood-fill">733. Flood Fill</a></h2><h3>Easy</h3><hr><p>You are given an image represented by an <code>m x n</code> grid of integers <code>image</code>, where <code>image[i][j]</code> represents the pixel value of the image. You are also given three integers <code>sr</code>, <code>sc</code>, and <code>color</code>. Your task is to perform a <strong>flood fill</strong> on the image starting from the pixel <code>image[sr][sc]</code>.</p>

<p>To perform a <strong>flood fill</strong>:</p>

<ol>
	<li>Begin with the starting pixel and change its color to <code>color</code>.</li>
	<li>Perform the same process for each pixel that is <strong>directly adjacent</strong> (pixels that share a side with the original pixel, either horizontally or vertically) and shares the <strong>same color</strong> as the starting pixel.</li>
	<li>Keep <strong>repeating</strong> this process by checking neighboring pixels of the <em>updated</em> pixels&nbsp;and modifying their color if it matches the original color of the starting pixel.</li>
	<li>The process <strong>stops</strong> when there are <strong>no more</strong> adjacent pixels of the original color to update.</li>
</ol>

<p>Return the <strong>modified</strong> image after performing the flood fill.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">image = [[1,1,1],[1,1,0],[1,0,1]], sr = 1, sc = 1, color = 2</span></p>

<p><strong>Output:</strong> <span class="example-io">[[2,2,2],[2,2,0],[2,0,1]]</span></p>

<p><strong>Explanation:</strong></p>

<p><img alt="" src="https://assets.leetcode.com/uploads/2021/06/01/flood1-grid.jpg" style="width: 613px; height: 253px;" /></p>

<p>From the center of the image with position <code>(sr, sc) = (1, 1)</code> (i.e., the red pixel), all pixels connected by a path of the same color as the starting pixel (i.e., the blue pixels) are colored with the new color.</p>

<p>Note the bottom corner is <strong>not</strong> colored 2, because it is not horizontally or vertically connected to the starting pixel.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, color = 0</span></p>

<p><strong>Output:</strong> <span class="example-io">[[0,0,0],[0,0,0]]</span></p>

<p><strong>Explanation:</strong></p>

<p>The starting pixel is already colored with 0, which is the same as the target color. Therefore, no changes are made to the image.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>m == image.length</code></li>
	<li><code>n == image[i].length</code></li>
	<li><code>1 &lt;= m, n &lt;= 50</code></li>
	<li><code>0 &lt;= image[i][j], color &lt; 2<sup>16</sup></code></li>
	<li><code>0 &lt;= sr &lt; m</code></li>
	<li><code>0 &lt;= sc &lt; n</code></li>
</ul>

---

### Idea

문제 이해) 특정 픽셀에서 시작해, 그것과 맞닿아 있으며 값이 같은 픽셀을 전부 주어진 색으로 같게 만들어야 한다.  
  
사실상 그래프의 `DFS/BFS` 구현과 다를 바 없다.  
</br>

- ⭐ 방향 배열(Driection Array)  
  위, 아래, 왼, 오 각각 if 문을 쓴다면 코드가 길어진다. 2차원 배열 탐색 시 방향 배열(델타 배열) 을 활용할 수 있다.    
  행(row) 의 변화량을 `dr`, 열(col) 의 변화량을 `dc` 로 두고 4가지 방향을 나타내는 배열을 미리 만들어 두면 된다.   

``` cpp
// 상(-1, 0), 하(1, 0), 좌(0, -1), 우(0, 1)
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

// 상하좌우 4방향 모두 탐색 가능
for (int i = 0; i < 4; i++) {
    int next_r = sr + dr[i];
    int next_c = sc + dc[i];
}
```
</br>

- ⭐ `visited` 배열은 없어도 된다.  
  원래 같으면 무한 루프를 막기 위해 `visited` 배열을 써야 했겠지만, 이 문제에서는 필요 없다.  
  
  > 조건에 맞는 경우만 이동 -> 💡 __방문한 곳은 반드시 색이 바뀌어 있다. !!__. 

  즉, 방문 전에 '처음 시작점의 색과 같은지' 만 확인하면 된다.   
  *`(칠하려는 색) = (원래 색)` 일 경우 -> 방문은 하고, 색 바꾸지 않고 바로 `return` 하기.   
