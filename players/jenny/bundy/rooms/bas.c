inherit "/players/jenny/room";
#include "/players/jenny/define.h"
realm() { return "NT"; }
reset(arg) {
if(!present("cockroach"))  {
MOCO("/players/jenny/bundy/mobs/roach.c"),this_object()); 
MOCO("/players/jenny/bundy/mobs/roach.c"),this_object());
MOCO("/players/jenny/bundy/mobs/roach.c"),this_object()); 
MOCO("/players/jenny/bundy/mobs/roach.c"),this_object()); }
    if(arg) return;
    set_light(1);
short_desc=("The Bundy's basement");
long_desc=
"This is the basement of the Bundy's home.  It is very messy.\n"+
"There are clothes everywhere, since Peg rarely does the laundry.\n"+
"There are some old costumes hanging up on a rack, and a stack\n"+
"of magazines in the corner.\n";
items = ({
"rack","A rack with some costumes hanging from it",
"clothes","These clothes will never be washed",
"costumes","These are the many costumes Bud has wore in his failed attempts to attract women",
"magazines","This is Al's prized collection of BIG-UNS",
});
dest_dir = ({
 "/players/jenny/bundy/rooms/hb3","upstairs",
});
}
init() { 
    ::init(); 
   this_player()->set_fight_area();
}
