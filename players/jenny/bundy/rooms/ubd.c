inherit "/players/jenny/room";
#include "/players/jenny/define.h"
realm() { return "NT"; }
reset(arg) {
if(!present("isis"))  {
MOCO("/players/jenny/bundy/mobs/isis.c"),this_object()); }
if(!present("big-uns"))  {
MOCO("/players/jenny/bundy/items/biguns.c"),this_object()); }

    if(arg) return;
    set_light(1);
short_desc=(""+CYN+"Under Bud's bed."+NORM+"");
long_desc=
"Why would anyone crawl under Bud's bed?  Well, for some reason\n"+
"you've decided to do so.  This is where Bud keeps the stuff he\n"+
"doesn't want his parents to see.\n";
dest_dir = ({
 "/players/jenny/bundy/rooms/u2a","back",
});
}
init() { 
    ::init(); 
   this_player()->set_fight_area();
}
