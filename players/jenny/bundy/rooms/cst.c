inherit "/players/jenny/room";
#include "/players/jenny/define.h"
realm() { return "NT"; }
reset(arg) {
set_no_clean(1);
if(!present("seven"))  {
MOCO("/players/jenny/bundy/mobs/seven.c"),this_object()); }
    if(arg) return;
    set_light(0);
set_smell(""+BOLD+"The stench of death hangs in the air.  It could be coming from that pair of shoes on the floor."+NORM+"\n");
set_search(""+BOLD+"You notice a baseball bat."+NORM+"\n");
short_desc=("a closet");
long_desc=
"This is a storage closet where the Bundy's keep all of their junk.\n"+
"Your eyes are taken aback by all of this clutter.  Two things that\n"+
"catch your eye are a record and an old jersey.\n";
items = ({
"clutter","Junk that most people would just throw away",
"record","Yodeling Andy's greatest hits",
"jersey","Al Bundy's old football Jersey from Polk High",
"shoes","An old smelly pair of bowling shoes.",
"bat","Al used this bat to hit a game winning home run for his softball team",
});
dest_dir = ({
 "/players/jenny/bundy/rooms/hb3","out",
});
}
init() { 
    ::init(); 
   this_player()->set_fight_area();
}
