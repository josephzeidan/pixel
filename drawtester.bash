#!/bin/bash

if [[ ! -f asciidraw.c ]]
then
        echo "Error cannot locate asciidraw.c"
        exit 1
fi

gcc -o asciidraw asciidraw.c -lm


rc=$?

if [[ $rc -ne 0 ]]
then
        echo "There were errors/warnings from gcc. rc = $rc"
        exit $rc
fi

echo
echo "================================================================"
echo '				TESTER					'
echo "================================================================"


echo 
echo "WELCOME GRID"
echo
echo "================================================================"
echo '            --- TEST CASE 0: DRAW A SMILEY FACE ---                                  '
echo "================================================================"
echo
echo '
./asciidraw <<ENDOFCMDS
GRID 40 40
CIRCLE 20,20 19
CHAR +
LINE 13,27 13,27 
LINE 24,27 24,27
LINE 13,10 23,10 
LINE 23,10 27,14
END
ENDOFCMDS
'



./asciidraw <<ENDOFCMDS
GRID 40 40
CIRCLE 20,20 19
CHAR +
LINE 13,27 13,27 
LINE 24,27 24,27
LINE 13,10 23,10
LINE 23,10 27,14
END
ENDOFCMDS



echo
echo "================================================================"
echo '                    --- TEST CASE 1  ---                                  '
echo "================================================================"
echo
echo '
./asciidraw <<ENDOFCMDS
LINE 10,10 25,25
CHAR +
RECTANGLE 5,25 20,5
GRID 27 27
GRID 30 30
CHAR >
LINE 1,24 20,24
CHAR <
LINE 3,3 20,22
CHAR /
LINE 3,3 20,3
END
ENDOFCMDS
'

./asciidraw <<ENDOFCMDS
LINE 10,10 25,25
CHAR +
RECTANGLE 5,25 20,5
GRID 27 27
GRID 30 30
CHAR >
LINE 1,24 20,24
CHAR o
LINE 3,3 20,22
CHAR <
LINE 3,3 20,3
END
ENDOFCMDS



echo
echo "================================================================"
echo '                    --- TEST CASE 2  ---                                  '
echo "================================================================"
echo
echo '
./asciidraw <<ENDOFCMDS
GRID 50 50
CHAR %
LINE 5,5 5,30
CHAR #
LINE 5,30 40,30
CHAR ^
LINE 40,30 40,5
CHAR @
LINE 40,5 5,5
END
ENDOFCMDS
'

./asciidraw <<ENDOFCMDS
GRID 50 50
CHAR %
LINE 5,5 5,30
CHAR #
LINE 5,30 40,30
CHAR ^
LINE 40,30 40,5
CHAR @
LINE 40,5 5,5
END
ENDOFCMDS




echo
echo "================================================================"
echo '                    --- TEST CASE 3  ---                                  '
echo "================================================================"
echo
echo '
./asciidraw <<ENDOFCMDS
GRID 30 30
RECTANGLE 5,25 20,5
CHAR #
RECTANGLE 1,28 25,1
CHAR O
RECTANGLE 8,23 28,8
END
ENDOFCMDS
'


./asciidraw <<ENDOFCMDS
GRID 30 30
RECTANGLE 5,25 20,5
CHAR #
RECTANGLE 1,28 25,1
CHAR O
RECTANGLE 8,23 28,8
END
ENDOFCMDS





echo
echo "================================================================"
echo '                    --- TEST CASE 4  ---                                  '
echo "================================================================"
echo
echo '
./asciidraw <<ENDOFCMDS
GRID 60 60
CHAR 0
LINE 1,1 23,67
CHAR @
LINE 20,20 53,58
CHAR #
LINE 6,6 20,30
END
ENDOFCMDS
'


./asciidraw <<ENDOFCMDS
GRID 60 60
CHAR 0
LINE 1,1 23,67
CHAR @
LINE 20,20 53,58
CHAR #
LINE 6,6 20,30
END
ENDOFCMDS




echo
echo "================================================================"
echo '                    --- TEST CASE 5  ---                                  '
echo "================================================================"
echo
echo '
./asciidraw <<ENDOFCMDS
GRID 60 60
CIRCLE 30,30 5
CHAR @
CIRCLE 30,30 15
CHAR #
CIRCLE 30,30 10
CHAR ^
CIRCLE 30,30 3
END
ENDOFCMDS
'

./asciidraw <<ENDOFCMDS
GRID 60 60
CIRCLE 30,30 5
CHAR @
CIRCLE 30,30 15
CHAR #
CIRCLE 30,30 10
CHAR ^
CIRCLE 30,30 3
END
ENDOFCMDS




echo
echo "================================================================"
echo '                    --- TEST CASE 6  ---                                  '
echo "================================================================"
echo
echo '
./asciidraw <<ENDOFCMDS
GRID 20 20
CIRCLE 10,10 5
CHAR @
CIRCLE 3,3 6
CHAR #
RECTANGLE 5,25 15,15
CHAR ^
LINE 1,1 40,40
END
ENDOFCMDS
'

./asciidraw <<ENDOFCMDS
GRID 20 20
CIRCLE 10,10 5
CHAR @
CIRCLE 2,2 4
CHAR #
RECTANGLE 5,25 15,17
CHAR ^
LINE 1,1 40,40
END
ENDOFCMDS



echo
echo "================================================================"
echo '                    --- TEST CASE 7  ---                                  '
echo "================================================================"
echo
echo '
./asciidraw <<ENDOFCMDS
GRID 60 40
CHAR #
CIRCLE 10,10 85,25
CHAR @
CIRCLE 5,5 25 
CHAR ~
RECTANGLE 5,4230 5321,15
END
ENDOFCMDS
'

./asciidraw <<ENDOFCMDS
GRID 60 40
CHAR #
CIRCLE 10,10 85,25
CHAR @
CIRCLE 5,5 15
CHAR ~
RECTANGLE 5,4230 5321,15
END
ENDOFCMDS




echo
echo "================================================================"
echo '                    --- TEST CASE 8  ---                                  '
echo "================================================================"
echo
echo '
./asciidraw <<ENDOFCMDS
GRID 50 50
CHAR #
LINE 3,20 20,3
CHAR @
LINE 5,35 40,2
CHAR ~
LINE 20,45 35,20
END
ENDOFCMDS
'

./asciidraw <<ENDOFCMDS
GRID 50 50
CHAR #
LINE 3,20 20,3
CHAR @
LINE 5,35 40,2
CHAR ~
LINE 20,45 35,20
END
ENDOFCMDS



echo
echo "================================================================"
echo '                    --- TEST CASE 9  ---                                  '
echo "================================================================"
echo
echo '
./asciidraw <<ENDOFCMDS
GRID 30 30
CHAR #
RECTANGLE 0,20 20,0
CHAR @
CIRCLE 10,10 9
CHAR ~
LINE 2,20 20,2
END
ENDOFCMDS
'

./asciidraw <<ENDOFCMDS
GRID 30 30
CHAR #
RECTANGLE 0,20 20,0
CHAR @
CIRCLE 10,10 9
CHAR ~
LINE 2,20 20,2
END
ENDOFCMDS


echo
echo "================================================================"
echo '                    --- TEST CASE 10  ---                                  '
echo "================================================================"
echo
echo '
./asciidraw <<ENDOFCMDS
GRID 70 70
CHAR #
CIRCLE 35,35 20
CHAR *
RECTANGLE 23,45 48,23
RECTANGLE 26,42 44,26
CIRCLE 35,35 5
CHAR %
LINE 0,0 70,70 
LINE 0,70 70,0
END
ENDOFCMDS
'

./asciidraw <<ENDOFCMDS
GRID 70 70
CHAR #
CIRCLE 35,35 20
CHAR *
RECTANGLE 23,45 48,23
RECTANGLE 26,42 44,26
CIRCLE 35,35 5
CHAR %
LINE 0,0 70,70 
LINE 0,70 70,0
END
ENDOFCMDS



echo
echo "================================================================"
echo '                    --- TEST CASE 11  ---                                  '
echo "================================================================"
echo
echo '
./asciidraw <<ENDOFCMDS
GRID 40 40
CHAR #
CIRCLE 20,20 8
CHAR *
RECTANGLE 0,39 39,0
CHAR @
CIRCLE 5,35 8 
CIRCLE 5,5 8
CIRCLE 35,5 8
CIRCLE 35,35 8
END
ENDOFCMDS
'

./asciidraw <<ENDOFCMDS
GRID 40 40
CHAR #
CIRCLE 20,20 8
CHAR *
RECTANGLE 0,39 39,0
CHAR @
CIRCLE 5,35 8 
CIRCLE 5,5 8
CIRCLE 35,5 8
CIRCLE 35,35 8
END
ENDOFCMDS


echo
echo "================================================================"
echo '                          END OF TESTER                                  '
echo "================================================================"
