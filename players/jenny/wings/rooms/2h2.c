inherit "/players/jenny/room";
#include "/players/jenny/define.h"
realm() { return "NT"; }
reset(arg) {
    if(arg) return;
    set_light(1);
     set_search(BOLD+"You notice drinking fountain."+NORM+"\n");
long_desc=
"This is a narrow hallway which wraps around the upper section\n"+      
"of Joe Louis Arena.  A thin red carpet covers the cement floor,\n"+
"and the plain tile walls look very dirty.  This hallway is used\n"+
"to provide access to the various media booths.  The booth for\n"+
"Red Wings local radio announcers is to the west.\n";

items = ({
"hallway","This hallway is used to provide access to the television and radio announcer's\n"+
                  "booths, as well as cameraman's booths, and the press box",
"carpet","This is cheap thin red carpet which is very worn.  It has many dark\n"+
               "stains from spilled food",
"stains","Many dark stains which are splattered on the carpet",
"floor","A hard cement floor which is covered with cheap red carpet",
"walls","These walls are lined with plain white tile.  They could stand to\n"+
               "be washed a little more often",
"booths","Small booths that provide a view of the game, and a place for\n"+
               "the media to work",
"fountain","This is a drinking fountain which is attached to the wall.  You\n"+
                  "could get a drink of water if you like",
"drinking fountain","This is a drinking fountain which is attached to the wall.  You\n"+
                  "could get a drink of water if you like",
});

dest_dir = ({
"/players/jenny/wings/rooms/2h1","north",
"/players/jenny/wings/rooms/2h3","south",
 "/players/jenny/wings/rooms/wingsradio","west",
});
}
short() {
return BOLD+WHT+"A hallway"+NORM; }
init() { 
    ::init(); 
   this_player()->set_fight_area();
   add_action("water","drink");
}
water(arg) {
if(!arg) {return 0;}
if(arg == "water") {

if(!TP->drink_soft(10)) { write("You couldn't possibly drink any more water.\n"); return 1; }
write("Ahhhhhhhhhhhhhh.  That was some refreshing "+HIB+"water."+NORM+"\n");
TP->heal_self(1);
return 1; }}
