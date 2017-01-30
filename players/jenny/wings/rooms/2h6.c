inherit "/players/jenny/room";
#include "/players/jenny/define.h"
realm() { return "NT"; }
reset(arg) {
    if(arg) return;
    set_light(1);
long_desc=
"This is a narrow hallway which wraps around the upper section\n"+      
"of Joe Louis Arena.  A thin red carpet covers the cement floor,\n"+
"and the plain tile walls look very dirty.  This hallway is used\n"+
"to provide access to the various media booths.  A camera\n"+
"booth is to the east.\n";

items = ({
"hallway","This hallway is used to provide access to the television and radio\n"+
                  "announcer's booths, as well as cameraman's booths, and the press box",
"carpet","This is cheap thin red carpet which is very worn.  It has many dark\n"+
               "stains from spilled food",
"stains","Many dark stains which are splattered on the carpet",
"floor","A hard cement floor which is covered with cheap red carpet",
"walls","These walls are lined with plain white tile.  They could stand to\n"+
               "be washed a little more often",
"booths","Small booths that provide a view of the game, and a place for\n"+
               "the media to work",
});

dest_dir = ({
"/players/jenny/wings/rooms/2h7","north",
"/players/jenny/wings/rooms/2h5","south",
"/players/jenny/wings/rooms/hniccamera","east",
});
}
short() {
return BOLD+WHT+"A hallway"+NORM; }
init() { 
    ::init(); 
   this_player()->set_fight_area();
}
