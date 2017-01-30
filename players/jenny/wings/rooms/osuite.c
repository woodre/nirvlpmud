inherit "/players/jenny/room";
#include "/players/jenny/define.h"
int NUM;
realm() { return "NT"; }
reset(arg) {
NUM = random(4);
if(!present("llitch"))  {
if(NUM < 2) {
MOCO("/players/jenny/wings/mobs/staff/mrsllitch.c"),TO); }
if(NUM == 2) {
MOCO("/players/jenny/wings/mobs/staff/denise.c"),TO); }
if(NUM == 3) {
MOCO("/players/jenny/wings/mobs/staff/christopher.c"),TO); }
}
    if(arg) return;
    set_light(1);
long_desc=
"This large comfortable suite belongs to team owner Mike Ilitch.\n"+      
"It has thick red carpeting, with the team logo in the center of\n"+
"the room.  A large glass wall gives a perfect view of the ice surface.\n"+
"Four couches are arranged throughout the room, as well as a table\n"+
"and chairs, refrigerator, and big screen television.\n";
items = ({
"logo","The team logo of a winged wheel is in the center of the room",
"wall","The large glass wall is like a giant window.  It gives a perfect\n"+
              "view of the ice surface down below",
"couches","Four comfortable black leather couches are arranged throughout\n"+
                 "the room",
"table","A long wooden table that is used to serve food",
"chairs","Six padded chairs that are spread around the table",
"carpeting","The carpeting is thick, red, and well padded.  Just like you would\n"+
                    "have in a living room",
"refrigerator","A large white refrigerator that is used for storing food and drinks",
"television","A big screen television is along the wall furthest from the glass",	
});

dest_dir = ({
"/players/jenny/wings/rooms/s4","leave",
});
}
short() {
return BOLD+RED+"Owner's Suite"+NORM; }
init() { 
    ::init(); 
   this_player()->set_fight_area();
}
