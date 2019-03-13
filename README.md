## High precision random function generator
Generates a sequence of probability variable that when attached to unbiased random number generator gives the desired probability<br>
In other words: Given the probability generate a function which returns 1 with that probability<br>
## working
**Inputs**
- desired probability (best when it's binary representation is finite)<br>
- desired binary precision (i.e. precision upto no of digits after decimal when probability value is written in binary formay)<br>
**Output**
- A sequence with variable `p`. `p` has probability `1/2`;<br>
## Example
- `$ ./generator`
- `$ Enter the probability: 0.83`
- `$ Precision in binary digits: 15`
- `$ p | p | p | p | p * p * (p | p | p * p * (p | p | p * p * p))`
- `# Replace all p's in this sequence with an unbiased random number generator with outcome 0 or 1`
- `>>> p() | p() | p() | p() | p() * p() * (p() | p() | p() * p() * (p() | p() | p() * p() * p()))`<br>
<!--  -->
## Testing
- Use [test.cpp](./test.cpp) or any program of your choice to test the accuracy