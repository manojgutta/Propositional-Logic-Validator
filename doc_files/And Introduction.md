# Algorithm:

 

And Introduction: 

Here we are storing the statement where the formula declaration is appearing with the respective premise line numbers.
Using the line numbers  we are generating a combined string to compare the original formula with the premises to verify the correctness of the proof.
 

 

And Elimination1:

Here in the andElimination function , using the formula declaration statement and the specified line number we are using a new String (generate) to add elements corresponding to the first part of the and formula and compare it with the ruleLine from index zero to and symbol(* not included).we are storing the open brakets in stack and poping them out on encountering a corresponding close braket. We return the truth value of our comparison as output(return value) of our function
 
 
And Elimination2:

Here in the andElimination function , using the formula declaration statement and the specified line number we are creating a new String (generate) through addition of required elements and making this string equivalent to the left part of the "and formula" and compute the length of the right part of the "and formula" by subtracting the no of elements on left part and these three elements["(",")","*"] of the "and formula" to obtain the length of the right part of the "and formula".We compare the obtained string with the corrsponding part of the ruleLine and return the truth value of our comparison as output(return value) of our function.
 


 

Or Introduction

 

By adding the required characters to the premise line a string is obtained which is compared with the rule line statement for commonality
Using this logic we are checking for +i1 +i2
 

 
Implications rules

Modus ponens: 
 Using the formula declaration statement we extract the lines numbers of premises and
we add the bracket and implication to the first premise and compare with the second premise till the implication symbol. After its verification we proceed to generate a new string equivalent to the right part of the "implication formula" and finally  compare it with the rule declaration statement for commonality.

Modus tollens:

Using the formula declaration statement we extract the lines numbers of premises and we are applying conditional checks to make sure if the statements of type {eg: (p->q) and q  are given as premises }then the proof becomes invalid under Modus Tollens criteria .After the verification if the premises are of the type {eg: (p->q) and (~q) as premises } we check if the negation of left part of the "implication formula" is equivalent to the ruleLine. 
