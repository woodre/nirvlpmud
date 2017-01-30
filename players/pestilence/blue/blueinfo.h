                        Blues Clues area outline
______________________________________________________________________________

                              I.  Theme
                             II.  Monsters
                            III.  Objects
                             IV.  Rooms
                              V.  Map
______________________________________________________________________________ 

I.  THEME -

     This area is based on the Nickjr children's television show called Blue's
Clues.  Most of the characters from the show are in this area, other than a few
lesser known ones.  The area is basically for very small level players, as there
is very little challenge in killing the mobs.  There are a few hidden exits
that play off of the show, where blue and steve skidoo into pictures.
______________________________________________________________________________ 


II.  MONSTERS - /players/vertebraker/ed/ed/mob/

                                 chart      [ ! means random ]
                                            [ * means turns after combat starts ]

+-----------------+--------+------------+--------+------+----------------+
|     Name        |   HP   |   Level    |   WC   |  AC  |  Items         |
+-----------------+--------+------------+--------+-----------------------+
|   Blue          |  60    |     4      |   8    | 5    |  bcollar       |
|   blue.c        |        |            |        |      |                |
+-----------------+--------+------------+--------+------+----------------+
|   magenta       |  120   |     8      |  12    | 7    |  mcollar       |
|   magenta.c     |        |            |        |      |                |
+-----------------+--------+------------+--------+------+----------------+
|   mailbox       |  30    |     2      |  6     |  3   |  letter        |
|   mailbox.c     |        |            |        |      |                |
+-----------------+--------+------------+--------+------+----------------+ 
|   tickety       |  60    |     4      |  8     |  5   |  hands         | 
|   tickety.c     |        |            |        |      |                |
+-----------------+--------+------------+--------+------+----------------+
|   steve         |  120   |     8      |  12    |  7   |  crayon        |
|   steve.c       |        |            |        |      |                |
+-----------------+--------+------------+--------+------+----------------+ 
|   pig           |  90    |     6      |  10    |  5   |  paper         |
|   student1.c    |        |            |        |      |                |
+-----------------+--------+------------+--------+------+----------------+ 
|   gopher        |  90    |     6      |  10    |  5   |  pen           |
|   student2.c    |        |            |        |      |                |
+-----------------+--------+------------+--------+------+----------------+ 
|   porcupine     |  90    |     6      |  10    |  5   |  quill         |
|   student3.c    |        |            |        |      |                |
+-----------------+--------+------------+--------+------+----------------+ 
|   table         |  60    |     4      |  8     |  5   |  notebook      |
|   table.c       |        |            |        |      |                |
+-----------------+--------+------------+--------+------+----------------+
|   salt          |  60    |     4      |  9     |  4   |  grain of salt |
|   salt.c        |        |            |        |      |                |
+------------------------------------------------------------------------+
|   pepper        |  60    |     4      |  9     |  4   | grain of pepper|
|   pepper.c      |        |            |        |      |                |
+------------------------------------------------------------------------+
|   paprika       |  45    |     3      |  7     |  4   | dash of paprika|
|   paprika.c     |        |            |        |      |                |
+------------------------------------------------------------------------+
|   pail          |  60    |     4      |  8     |  4   |  sand          |
|   pail.c        |        |            |        |      |                |
+------------------------------------------------------------------------+
|   shovel        |  60    |     4      |  8     |  4   |  sand          |
|   shovel.c      |        |            |        |      |                |
+------------------------------------------------------------------------+
|   slippery      |  30    |     2      |  6     |  3   |  bubbles       |
|   slippery.c    |        |            |        |      |                |
+------------------------------------------------------------------------+
|   rabbit        |  60    |     4      |  8     |  5   |  bhelmet       |
|   rabbit.c      |        |            |        |      |  tricycle      |
+------------------------------------------------------------------------+
     All of the monsters are animals or objects that aren't normally alive
so it would not make sense for them to carry coins.  Only Steve carries any
coins.  The rest carry mostly treasure/obj that seem to fit the theme.

______________________________________________________________________________

III.  OBJECTS - /players/vertebraker/ed/ed/obj/

   1 bcollar.c    1 dpaprika.c    1 mcollar.c     1 pgrain.c    1 tricycle.c 
   1 bubbles.c    1 hands.c       1 notebook.c    1 sand.c 
   1 crayon.c     1 letter.c      1 paper.c       1 sgrain.c

bcollar.c
 a collar for blue, for the reason blue carrying coins wouldn't make sense
value 300
weight 1

bubbles.c
 bubbles from slippery soap, once again soap wouldn't be carrying coins,
but bubbles seemed thematic
value 20+random200
weight1

crayon.c
 a crayon that steve uses in the show, i thought it would be nice to 
have on him since it's on the show
value 50
weight 3

dpaprika.c
 a dash of paprika, being a small shaker of paprika it seemd fitting
to recieve some of the paprika upon it's death
value 100
weight 1

hands.c
 hands from the clock tickety, once again an object to take the place 
of coins that fit the theme more
value 300
weight 1

letter.c
 this is a letter from the mailbox. Seems self explanitory.
value 100
weight 1

mcollar.c
 A collar from magenta the dog.  I made this one an actual piece of armor
for the reason there is little armor in this area
value 250
weight 1

notebook.c
 The notebook is from the table, on the show that is the place where Steve
keeps his notebook
value 300
weight 1

paper.c
 This is a piece of homework found on student1.c, that is the pig and she is
found in the school thus the reason for the homework.
value 150+random100
weight 1

pgrain.c
 This is a grain of pepper that comes from Mrs. Pepper.  I thought it seemed
an obvious treasure from this mob.
value 150
weight 1

sgrain.c
 This is a grain of salt that comes from Mr. Salt.  Once again i thought it was
obvious
value 150
weight 1

sand.c
 A grain of sand that came from the sandbox that was left on the shovel and 
pail.
value 150
weight 1

tricycle.c
 Rabbit is riding the tricycle on the racetrack, so it seemed to be a good 
treasure item from this mob.
value 250
weight 3

bikehelmet.c
 Rabbit needs to be safe while riding the tricycle
value 50
weight 1
ac 0

pen.c
 Student2.c has a pen.  Gopher is at school, and a pen seemed to fit in nicely.
This pen is also a weapon.
value 250
weight 2
wc 14

quill.c
 Student3.c has this item.  Student3.c is a porcupine thus the quill.
The quill is a weapon.
value 250
weight 2
wc 14




______________________________________________________________________________





IV.  ROOMS - /players/pestilence/blue/rooms/
    Basically these rooms are based from the television show and take place
at Blue and Steve's house.

front.c
 This is the front walk before the house.

tree.c
 This is another spot in front of the house with a tree.

room1.c
 This is the entrance to the house and opens up into the living room.

hall.c
 This is the hall from living room leading to the bathroom and Steve's bedroom

sroom.c
 This is Steve's bedroom.

bath.c
 This is the bathroom.

closet.c
 A closet of from Steve's bedroom.

kitchen.c
 The kitchen of the house.

backyard.c
 The backyard, which you can get to through the back door in the kitchen.

broom.c
 Blue's bedroom.

bplace.c
 Blue's special place.

track.c
 A race track that you can skidoo to from a picture in the living room.

school.c
 A school room that you can skidoo to from a picture in Blue's special place.

______________________________________________________________________________

V.  MAP -
                       @2school.c

                       @1track.c


                   backyard.c
                    |
                   kitchen.c
                    |
bplace.c@2-broom.c-room1.c@1---------hall.c----sroom.c
                    |                  |         |
                 front.c---tree.c    bath.c    closet.c
                      
   
@2 = skidoo
@1 = skidoo
$ = start
- = direction
