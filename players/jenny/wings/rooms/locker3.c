inherit "/players/jenny/room";
#include "/players/jenny/define.h"
int door;
realm() { return "NT"; }
reset(arg) {
door = 1;
if(!present("osgood"))  {
if(random(10) > 1) {
MOCO("/players/jenny/wings/mobs/players/osgood.c"),TO); }}
    if(arg) return;
    set_light(1);
     set_smell(BOLD+"A musty odor hangs in the air."+NORM);
long_desc=
"This is the locker room of the Detroit Red Wings.  It is a large room,\n"+      
"used by the players to change before and after games.  There are\n"+
"about thirty stalls along the outside edges of the room, with wooden\n"+
"benches in front of them.  A wooden door is all the way to the east,\n"+
"and an entrance to the showers is to the south.  The center of the room\n"+
"is open space, with only a large rug and a movable chalkboard.\n";
items = ({
"stalls","Each stall is like a big, open locker.  There are hangers and shelves\n"+
              "for street clothes and personal belongings, as well as a large storage\n"+
              "bin at the bottom for equipment",
"hangers","Each stall has thick wooden hangers for a players street clothes",
"entrance","A small entranceway on the north wall leading into the showers,\n"+
                   "toilets, etc",
"shelves","Each stall has 2 shelves, which players use to store personal belongings",
"bin","Each stall has a large, white storage bin for players to keep their\n"+
           "hockey equipment",
"benches","These are plain wooden benches with a light finish.  They run along\n"+
                 "the outside edges of the room, in front of the stalls",
"door","A wooden door with a sign on it.  You could enter the door",
"sign","The sign reads: TRAINERS ROOM",
"rug","This rug covers a large area in the center of the room.  It is red, with a\n"+
           "Detroit Red Wings logo in the center",
"logo","It is a red and white winged wheel.  The logo of the Detroit Red Wings",
"chalkboard","A two-sided black chalkboard, which sits on a wooden frame.\n"+
                       "It has small wheels, making it easy to move",
});
dest_dir = ({
 "/players/jenny/wings/rooms/locker1","north",
 "/players/jenny/wings/rooms/shower","south",
 "/players/jenny/wings/rooms/locker4","west",
});
}
short() {
return BOLD+RED+"Red Wings Locker Room"+NORM; }
init() { 
    ::init(); 
   this_player()->set_fight_area();
add_action("door","enter");
add_action("open","open");
add_action("close","close");
}
door(arg) { 
if(!arg) { return 0; }
if(arg == "door" | arg == "the door")  {
if(door == 1) {write("You must open the door first.\n");
return 1;}
else {
TP->move_player("through the door#players/jenny/wings/rooms/trainingroom.c");
return 1; }}}
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
return 1; }}
