inherit "/players/jenny/room";
#include "/players/jenny/define.h"
realm() { return "NT"; }
reset(arg) {
if(!present("brat"))  {
MOCO("/players/jenny/bundy/mobs/brat.c"),this_object()); }
if(!present("mall walker"))  {
MOCO("/players/jenny/bundy/mobs/walker.c"),this_object()); }
    if(arg) return;
    set_light(1);
     set_listen(""+BOLD+"You hear the general chatter of people shopping."+NORM+"\n");
short_desc=(""+GRN+"The Mall"+NORM+"");
long_desc=
"This is the mall where Al Bundy works.  People come from\n"+
"all over Chicago to buy things here.  The mall is not very\n"+
"busy lately.  Some shoe salesman has been doing his best to\n"+
"scare customers away.\n";
dest_dir = ({
"/players/jenny/bundy/rooms/m3e","west",
"/players/jenny/bundy/rooms/m5e","east",
});
}
init() { 
    ::init(); 
   this_player()->set_fight_area();
}
