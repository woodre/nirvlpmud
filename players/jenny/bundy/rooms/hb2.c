inherit "/players/jenny/room";
#include "/players/jenny/define.h"
realm() { return "NT"; }
reset(arg) {
if(!present("yvette"))  {
MOCO("/players/jenny/bundy/mobs/yvt.c"),this_object()); }
    if(arg) return;
    set_light(1);
set_search(""+BOLD+"You find some oil stains on the floor."+NORM+"\n");
short_desc=(""+CYN+"The Bundy's Garage"+NORM+"");
long_desc=
"This is the Bundy's garage.  Al uses it to park his mighty\n"+
"dodge, and to hold his NO'MAM meetings.  It is one of the\n"+
"only places where he can go to get away from his nagging\n"+
"wife and leaching kids.\n";
items = ({
"stains","The dodge must leak a lot of oil",
"oil stains","The dodge must leak a lot of oil",
});
dest_dir = ({
 "/players/jenny/bundy/rooms/hb3","house",
 "/players/jenny/bundy/rooms/hb1","bathroom",
});
}
init() { 
    ::init(); 
   this_player()->set_fight_area();
}
