inherit "/players/jenny/room";
#include "/players/jenny/define.h"
int door;
int cash, randomchance, money;
reset(arg) {
randomchance = random(3);
money = 1;
if(!present("agent"))  {
MOCO("/players/jenny/80s/mobs/agent2.c"),this_object()); }
if(!present("mikhail gorbachev"))  {
MOCO("/players/jenny/80s/mobs/gorbie.c"),this_object()); }
if(!present("george bush"))  {
MOCO("/players/jenny/80s/mobs/bush.c"),this_object()); }
door = 1;
    if(arg) return;
    set_light(1);
set_listen(BOLD+"You hear shredding noises coming from behind a door."+NORM);
long_desc=
"This room appears to be a den.  It has a beautiful hardwood floor,\n"+
"which is partially covered by an antique Persian rug.  The walls are\n"+
"made of wood paneling, giving the den a cabin like feel.  The\n"+
"bookcases along the wall hold thousands of books, most of which\n"+
"appear never to have been opened.  An antique walnut desk sits\n"+
"over by the window.\n";
short_desc=(HIW+BOLD+"Den"+NORM);
items = ({
"door","A door sits over by the far wall.  It leads to another room.\n"+
"You could enter it",
"window","This large window gives a nice view of the back yard",
"rug","This is a beautiful red, black, and yellow Persian rug.  The designs\n"+
              "on it are awe inspiring",
"desk","This is a beautiful antique desk made from walnut.  It has a dark\n"+
       "finish, which is polished so well, you can see your reflection",
"yard","The 10 acre back yard is majestic.  The grass is green and beautiful,\n"+
            "while dozens of trees provide plenty of shade",
"grass","The plush green grass looks like something you'd find on one of\n"+
              "America's finest golf courses",
"trees","Dozens of trees, of many varieties, dot the yard.  There are some ash,\n"+
            "oak, willow, elm, walnut, and apple trees", 
"paneling","This solid oak paneling has a dark finish.  It highlights the grain of the wood",
"floor","The floor is made of hardwood.  It has an antique Persian rug\n"+
"covering part of it",
"walls","The walls are made of solid oak paneling",
"books","Thousands of books on various subjects.  Most of them have never been opened",
"bookcases","Three antique bookcases, made out of mahogany, cover the far wall.  It\n"+
"would take a lifetime to actually read all of these books",
});
dest_dir = ({
 "/players/jenny/80s/rooms/4","west",
});
}
init() { 
    ::init(); 
add_action("door","enter");
add_action("open","open");
add_action("close","close");
add_action("coins","search");
}
door(arg) { 
if(!arg) { return 0; }
if(arg == "door" | arg == "the door")  {
if(door == 1) {write("You must open the door first.\n");
return 1;}
else {
TP->move_player("through the door#players/jenny/80s/rooms/ollie.c");
return 1; }}}
coins(arg)  {
int cash;
cash = 45+random(20);
if(money == 1 && randomchance == 1) {
write(BOLD+"You find "+cash+" coins."+NORM+"\n");
TP->add_money(cash);
money = 2;
return 1;  }
}
open(arg) { 
if(!arg) { return 0; }
if(arg == "door" | arg == "the door")  {
write("You open the door.\n");
say(TPN+" opens the door.\n");
door = 2;
return 1; }}
close(arg) { 
if(!arg) { return 0; }
if(arg == "door" | arg == "the door")  {
write("You close the door.\n");
say(TPN+" closes the door.\n");
door = 1;
return 1; }
}
