# <center>alpic</center>

This project was made for the 2nd semester at Lille's IUT A.

### What's this?

alpic is a logic parser written in C. Its goal is to parse a file, passed as an argument, and tell if a word, passed as a second argument, is part of the logic described in the file.

### Limitations

This logic parser only supports 5 states at a time.
This logic parser only supports one initial state.
This logic parser doesn't support non decisive logics (e.g. two different possible paths).

### File format definition

`Line 1` : alphabet definition

`Line 2` : initial states

`Line 3` : final states

`Line 4-8` : state descriptions

State descriptions are made using this format :
```
# Example : nothing on this line
;;;;;

# Example : from state 1 (the line is describing state 1) possible change to state 3 :
# if we are at state 1 and we have an a, we can go to state 3
;;;a;;

# State descriptions goes from 0 to 4 ;
;ab;a;b;c;
0 1 2 3 4 
```