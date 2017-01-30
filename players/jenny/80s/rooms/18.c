inherit "/players/jenny/room";
#include "/players/jenny/define.h"
reset(arg) {
if(!present("a boy with spiked hair"))  {
MOCO("/players/jenny/80s/mobs/sboy.c"),this_object()); 
MOCO("/players/jenny/80s/mobs/sboy.c"),this_object()); }
if(!present("a boy with spiked hair 2") && present("a boy with spiked hair"))  {
MOCO("/players/jenny/80s/mobs/sboy.c"),this_object()); }
if(!present("a boy with feathered hair"))  {
MOCO("/players/jenny/80s/mobs/fboy.c"),this_object()); 
MOCO("/players/jenny/80s/mobs/fboy.c"),this_object()); }
if(!present("a boy with feathered hair 2") && present("a boy with feathered hair"))  {
MOCO("/players/jenny/80s/mobs/fboy.c"),this_object()); }
if(!present("girl"))  {
MOCO("/players/jenny/80s/mobs/bgirl.c"),this_object()); 
MOCO("/players/jenny/80s/mobs/bgirl.c"),this_object()); }
if(!present("girl 2") && present("girl"))  {
MOCO("/players/jenny/80s/mobs/bgirl.c"),this_object()); }
    if(arg) return;
    set_light(0);
set_smell(BOLD+"The room smells like cigarette smoke."+NORM);
set_listen(BOLD+"You hear the sound of 50 video games being played at once"+NORM);
long_desc=
"This arcade is one of the most popular places for young people to hang\n"+
"out.  It is a large, dark room, lit only by rows and rows of video games.\n"+
"The floor, littered with soda cans and candy wrappers, is sticky in some\n"+
"spots.  Towards the back of the arcade, you can see an attendants booth.\n";
short_desc=(RED+"Arcade"+NORM);
items = ({
"games","This arcade has all the popular video games.  There is Pac-man, Ms.\n"+
              "Pac-man, Super Pac-man, Asteroids, Space Invaders, Centipede, Donkey\n"+
              "Kong, Frogger, Defender, Pitfall, and many other games as well",
"attendant","He smiles and waves at you",
"video games","This arcade has all the popular video games.  There is Pac-man, Ms.\n"+
              "Pac-man, Super Pac-man, Asteroids, Space Invaders, Centipede, Donkey\n"+
              "Kong, Frogger, Defender, Pitfall, and many other games as well",
"floor","The floor is made up of a grey tile, which does a good job of hiding dirt.\n"+
"It is littered with soda cans and candy wrappers",
"cans","Empty Coke, Pepsi, Mountain Dew, Orange Crush, and Jolt cans litter the floor",
"wrappers","A bunch of candy wrappers are on the floor.  Some of the brands you notice\n"+
"are: Three Musketeers, Snickers, Whatchamacallit, and Gummy Bears",
"booth","This booth is where the attendant sits.  He makes change for dollars bills,\n"+
              "and fixes the games when the quarters jam",
});
dest_dir = ({
 "/players/jenny/80s/rooms/12","north",
});
}
