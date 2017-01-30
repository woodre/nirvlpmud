inherit "/players/jenny/room";
#include "/players/jenny/define.h"
realm() { return "NT"; }
reset(arg) {
    if(arg) return;
    set_light(1);
set_search(BOLD+"You notice a door, which leads to a stairwell."+NORM);
long_desc=
"This is a narrow hallway which wraps around the upper section\n"+      
"of Joe Louis Arena.  A thin red carpet covers the cement floor,\n"+
"and the plain tile walls look very dirty.  This hallway, which is\n"+
"used to provide access to the various media booths, makes a\n"+
"sharp curve around the far end of the arena.  Along the wall,\n"+
"there is a door with an exit sign painted over it.\n";

items = ({
"hallway","This hallway is used to provide access to the television and radio\n"+
                  "announcer's booths, as well as cameraman's booths, and the press box",
"carpet","This is cheap thin red carpet which is very worn.  It has many dark\n"+
               "stains from spilled food",
"stains","Many dark stains which are splattered on the carpet",
"sign","The sign reads "+RED+"EXIT"+NORM+"",
"door","This door leads to a stairwell.  You could enter the door and\n"+
             "use the stairs",
"floor","A hard cement floor which is covered with cheap red carpet",
"wall","This wall is lined with dirty white tiles.  There is an exit sign\n"+
"painted over the door",
"walls","These walls are lined with plain white tile.  They could stand to\n"+
               "be washed a little more often",
"booths","Small booths that provide a view of the game, and a place for\n"+
               "the media to work",
});

dest_dir = ({
"/players/jenny/wings/rooms/off-ice","north",
"/players/jenny/wings/rooms/2h5","northwest",
"/players/jenny/wings/rooms/2h3","northeast",
});
}
short() {
return BOLD+WHT+"A hallway"+NORM; }
init() { 
    ::init(); 
   this_player()->set_fight_area();
add_action("stairwell","enter");
}
stairwell(arg) {
if(!arg) {return 0;}
if(arg == "stairwell" | arg == "door") {
TP->move_player("through the door#players/jenny/wings/rooms/stairs2.c");
return 1; }
}
