inherit "/players/jenny/room";
#include "/players/jenny/define.h"
int dooropen;
realm() { return "NT"; }
reset(arg) {
dooropen = 1;
    if(arg) return;
     set_smell(BOLD+"It smells like rotting flesh."+NORM);
     set_listen(BOLD+"You hear faint laughing, but can't tell where it's coming from."+NORM);
set_light(0);
long_desc=
"This is just a plain room within the cold damp basement.  It has plain\n"+      
"brick walls, and cobwebs in the exposed floor joints.  The outline of\n"+
"a 6x6 foot hatch is above you, and a steel door is on one of the walls.\n"+
"A skeleton lays in the corner.\n";
short_desc=(BOLD+"A room in the basement"+NORM);

items = ({
"walls","They are made of large, grey, unpainted bricks",
"floor","The dirty, grey, cement floor",
"bones","A pile of bones that make up a skeleton.  A leg bone seems broken",
"clothes","These are the tattered remains of someone's clothes",
"floor joints","This is the underside of the first floor.  A proper ceiling was never\n"+
               "installed.  The wooden beams are filled with cobwebs",
"beams","Wooden beams which are used to support the first floor",
"cobwebs","Cobwebs have formed in the exposed floor joints",
"bricks","Large grey bricks, used for the basement walls",
"skeleton","This is the skeleton of a male human.  It must have been here a long\n"+
                  "time, the flesh has rotted away, and now it's just a pile of bones, and\n"+
                   "the remains of some clothes",
"door","This is a sturdy steel door.  There is no handle.  If the door were\n"+
            "open, you could leave through it",
"outline","This is the outline of a 6x6 foot trap door.  There does not appear to\n"+
                "be a way to open it from here",
"hatch","This is the outline of a 6x6 foot trap door.  There does not appear to\n"+
                "be a way to open it from here",
});
}
init() { 
    ::init(); 
   this_player()->set_fight_area();
add_action("leave","leave");
add_action("door","open");
}
leave() {

if(dooropen > 1) {
write("You leave through the open door.\n");
TP->move_player("through the open door#players/jenny/house/rooms/bas.c");
return 1; }}
door(arg) {
if(!arg) {return 0; }
if(arg == "door" | arg == "the door") {
write("Since there is no handle or knob, trying to open it is an exercise in futility.\n");
return 1 ;}}
