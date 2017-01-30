inherit "/players/jenny/room";
#include "/players/jenny/define.h"
realm() { return "NT"; }
reset(arg) {
if(!present("steve rhodes"))  {
MOCO("/players/jenny/bundy/mobs/steve.c"),this_object()); }
    if(arg) return;
    set_light(1);
     set_listen(""+BOLD+"It is pretty quiet in here."+NORM+"\n");
     set_smell(""+GRN+"You can almost smell the money."+NORM+"\n");
short_desc=(""+WHT+"The Bank"+NORM+"");
long_desc=
"This is the bank where Steve Rhodes works.  They will lend\n"+
"money to anyone, even the Bundy's.  There are a couple of bank\n"+
"tellers, and a loan department.  The room is decorated with a\n"+
"few comfortable chairs, a desk, and a cheap pen.\n";

items = ({
"chairs","They look comfortable",
"tellers","Two female tellers are slowly tending to the customers",
"loan department","Steve Rhodes is the hard working employee in charge of making loans",
"desk","A cheap desk.  Made from something one step up from plywood",
"pen","It is chained to the desk.",
});

dest_dir = ({
"/players/jenny/bundy/rooms/m3b","west",
});
}
init() { 
    ::init(); 
   this_player()->set_fight_area();
}
