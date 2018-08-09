# PUSH_SWAP

Sort a series of random integers using only two stacks. The "push_swap" program finds the most efficient way to sort the stack and returns a series of commands. These commands when piped to the "checker" executable will confirm or deny whether the stack has been sorted by outputting either "OK" or "KO".

### Installing

Clone the "push_swap" repository to your system. This will create a folder called "push_swap" containing all the necessary files.

```
git clone https://github.com/vanniekerkalex/push_swap.git
```

Compile the program by executing the Makefile in the repository directory as follows:

```
make re
```

## Running the tests

Execute the the following command which will generate 50 random numbers, send it to the "push_swap" program which will in turn send the sorting commands to "checker" for confirmation of a sorted stack.

```
ARG=`ruby -e "puts (0..49).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker $ARG
```

To activate the visualizer for the "push_swap" program. Add the command "-v" after "./checker" and before "$ARG" as follows:

```
ARG=`ruby -e "puts (0..49).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker -v $ARG
```

## Built With

* [Atom](http://atom.io/) in C
