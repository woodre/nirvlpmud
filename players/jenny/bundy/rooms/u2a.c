inherit "/players/jenny/room";
#include "/players/jenny/define.h"
realm() { return "NT"; }
reset(arg) {
if(!present("bud bundy"))  {
MOCO("/players/jenny/bundy/mobs/bud.c"),this_object());  }
    if(arg) return;
    set_light(1);
set_search(""+BOLD+"You see something under the bed, but can't make out what it is."+NORM+"\n");
short_desc=(""+CYN+"Bud Bundy's room."+NORM+"");
long_desc=
"This room belongs to Bud Bundy.  Bud spends a lot of time in his\n"+
"room alone.  Not many women have been in this room.  There are\n"+
"posters on the wall, and a bed by the window.\n";

items = ({
"wall","A wall, with posters on it",
"bed","Maybe you could 'crawl bed' and go under there",
"window","This window faces the Darcy's house.  Bud likes to watch Marcy undress",
"posters","Posters of pretty women",
});

dest_dir = ({
 "/players/jenny/bundy/rooms/u2b","south",
});
}
init() { 
    ::init(); 
   this_player()->set_fight_area();
add_action("bed","crawl");
}
bed(arg) { 
if(!arg) { return 0; }
if(arg == "bed") {
write("You crawl under the bed.\n");
TP->move_player("under the bed#players/jenny/bundy/rooms/ubd.c");
return 1; }
}
