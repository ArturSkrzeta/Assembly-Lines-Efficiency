<h2>Efficient Task Scheduler</h2>

<h3>Intro</h3>
<p>Program uses <b>Greedy Algorithm.</b></p>
<p>Due to wikipedia:</p>
<p><i>A greedy algorithm is any algorithm that follows the problem-solving heuristic of making the locally optimal choice at each stage with the intent of finding a global optimum. </i></p>

<h3>Demo</h3>
<ul>
  <li>SLA document requires comapny to process at least 10 tasks per day.</li>
  <li>Each hour from 7:00 AM to 4:00 PM, global system accepts tasks from a client.</li>
  <li>We have to schedule 10 tasks that lasts x hours each to be processed.</li>
  <li>Depending on task, x can equals 1, 2 up to 4 hours.</li>
  <li>The main goal of task scheduler is to schedule as many tasks as possible to one employee.</li>
  <li>The tasks are compatible with each other when they don't overlap.</li>
  <li>The task scheduler assumes that tasks that left will be shifted to assistant of an employee.</li>
</ul>

<img src="images/tasks-time.JPG" width="500" height="460">


              1       2       3       4       5       6       7       8       9       10
    ------------------------------------------------------------------------------------------
    Start |   0   |   1   |   2   |   3   |   3   |   5   |   5   |   6   |   7   |    8       
    ------------------------------------------------------------------------------------------
    End   |   4   |   2   |   4   |   5   |   6   |   6   |   7   |   7   |   9   |   10   
 
 <h3>Outcome</h3>
 <img src="images/console.JPG">
