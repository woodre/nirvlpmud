inherit "/players/jenny/room";
#include "/players/jenny/define.h"
realm() { return "NT"; }
reset(arg) {
if(!present("survey lady"))  {
MOCO("/players/jenny/bundy/mobs/survey.c"),this_object()); }
    if(arg) return;
    set_light(1);
     set_listen(""+BOLD+"You hear a fat lady yelling a shoe salesman to the west."+NORM+"\n");
short_desc=(""+GRN+"The Mall"+NORM+"");
long_desc=
"This is the mall where Al Bundy works.  People come from\n"+
"all over Chicago to buy things here.  The mall is not very\n"+
"busy lately.  Some shoe salesman has been doing his best to\n"+
"scare customers away.  There are businesses to the east and\n"+
"west.\n";
dest_dir = ({
"/players/jenny/bundy/rooms/m3a","north",
"/players/jenny/bundy/rooms/m3c","south",
"/players/jenny/bundy/rooms/m2b","west",
"/players/jenny/bundy/rooms/m4b","east",
});
}
init() { 
    ::init(); 
   this_player()->set_fight_area();
}
