### 💡 Description of solution : (35 lines of code)
--------------------------------
<p> <b>1.</b> Code consists of a program that take a string as a parameter rewrites the alphabetical characters of the string 13 positions ahead.</p>
<p> <b>2.</b> To do so i first make sure that the number of arguments is correct (the program + the string itself). </p>
<p> <b>3.</b> Then, i run a loop to reach the last character of the string. </p>
<p> <b>4.</b> From there, i have 3 main "If" condition. The first corresponds to the scenario where the current character is a small case alphabet. If true i have another if condition that checks if the iteration of 13 positions will lead to a character bigger than 'z'. If so, i subtract the excess of the iteration so that the addition will continue with 'a'. </p>
<p> <b>5.</b> The second main "If" condition does the same but for the capital case alphabets.</p>
<p> <b>6.</b> The third main "If" condition just writes the character, if the character is not an alphabetical character.</p>
<p> <b>7.</b> A the end of the main loop, a newline character is written and the program terminates.</p>
