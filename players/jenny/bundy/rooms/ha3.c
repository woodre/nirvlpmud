inherit "/players/jenny/room";
#include "/players/jenny/define.h"
realm() { return "NT"; }
reset(arg) {
if(!present("cockroach"))  {
MOCO("/players/jenny/bundy/mobs/roach.c"),this_object()); 
MOCO("/players/jenny/bundy/mobs/roach.c"),this_object()); }
    if(arg) return;
    set_light(1);
set_search(""+BOLD+"You search all over the kitchen, but find no food."+NORM+"\n");
short_desc=(""+CYN+"The Bundy's Kitchen"+NORM+"");
long_desc=
"Welcome to the Bundy's kitchen.  This is one of the most\n"+
"seldom used rooms in the house.  A table sits in the center\n"+
"of the room.  There is a refrigerator and stove along the wall.\n";
items = ({
"table","A plain kitchen table, with nothing on it",
"refrigerator",""+MAG+"*LAUGH*"+NORM+" Did you actually think there would be food in there?",
"stove","This stove looks like it has never been used.  Peg calls it the big hot thing'",
"wall","A wall.  It could stand to be washed",
});
dest_dir = ({
 "/players/jenny/bundy/rooms/hb3","south",
});
}
init() { 
    ::init(); 
   this_player()->set_fight_area();
}
