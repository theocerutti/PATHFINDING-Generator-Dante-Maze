#!/bin/bash
# generator_solver.sh

if test "$#" -ne 4 && test "$#" -ne 3 && test "$#" -ne 2; then
 echo -e "Generator_Solver:\nArguments:\n\t[graphical]: \
 optional argument, print with interface or not\n\tX: \
 Size x\n\tY: Size Y\n\t[perfect]: optional argument, \
 make the maze perfect (or imperfect if no argument)"
elif [ $1 = "graphical" ]; then
    ./generator_bonus $2 $3 $4
    ./solver_bonus map_output
    rm map_output
else
    if [ "$#" -eq 2 ]; then
        ./generator $1 $2 > .tmp
    else
        ./generator $1 $2 $3 > .tmp
    fi
    ./solver .tmp > .tmp2
    cat .tmp2 | GREP_COLORS='mt=38;5;160;48;5;160' grep --color=always 'o' |
    GREP_COLORS='mt=38;5;30;48;5;30' grep --color=always 'X' |
    GREP_COLORS='mt=38;5;80;48;5;80' grep --color=always '*'
    cat .tmp2
    rm .tmp
    rm .tmp2
fi