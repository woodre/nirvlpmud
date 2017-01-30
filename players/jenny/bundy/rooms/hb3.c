inherit "/players/jenny/room";
#include "/players/jenny/define.h"
realm() { return "NT"; }
reset(arg) {
if(!present("peg bundy"))  {
MOCO("/players/jenny/bundy/mobs/peg.c"),this_object()); }
    if(arg) return;
    set_light(1);
set_smell(""+BOLD+"The smell of failure hangs in the air."+NORM+"\n");
set_search(""+BOLD+"You notice a closet."+NORM+"\n");
set_listen(""+BOLD+"You hear sounds coming from inside the closet."+NORM+"\n");
short_desc=(""+CYN+"The Bundy's House"+NORM+"");
long_desc=
"This is the living room of the Bundy's house.  It is not\n"+
"very well decorated.  It is obvious that this family does\n"+
"not have a lot of money or taste.  A television sits prominently\n"+
"in the center of the room, not far from the couch.\n";
items = ({
"couch","There is a massive indentation from where Peg sits all day",
"television","Peg watches this constantly.  Oprah is on right now",
"closet","Perhaps you can enter closet",
});
dest_dir = ({
 "/players/jenny/bundy/rooms/ha3","north",
 "/players/jenny/bundy/rooms/hb2","west",
 "/players/jenny/bundy/rooms/u1b","upstairs",
 "/players/jenny/bundy/rooms/bas","basement",
 "/players/jenny/bundy/rooms/3a","out",
});
}
init() { 
    ::init(); 
   this_player()->set_fight_area();
add_action("closet","enter");
}
closet(arg) { 
if(!arg) { return 0; }
if(arg == "closet") {
write("You enter the Bundy's closet.\n");
TP->move_player("into the closet#players/jenny/bundy/rooms/cst.c");
return 1; }
}
