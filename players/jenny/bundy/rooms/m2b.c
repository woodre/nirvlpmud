inherit "/players/jenny/room";
#include "/players/jenny/define.h"
realm() { return "NT"; }
reset(arg) {
if(!present("al bundy"))  {
MOCO("/players/jenny/bundy/mobs/al.c"),this_object()); }
if(!present("fat lady"))  {
MOCO("/players/jenny/bundy/mobs/fatl.c"),this_object()); }
    if(arg) return;
    set_light(1);
     set_smell(""+YEL+"It smells like feet in here."+NORM+"\n");
short_desc=(YEL+"Gary's"+MAG+" Shoe "+YEL+"Store"+NORM );

long_desc=
"Welcome to Gary's Shoes.  Al has worked in this shoe store\n"+
"since he was in high school.  Not many customers shop here,\n"+
"only the occasional fat lady comes in to bother poor Al.  The\n"+
"store is kind of drab, a cash register sits near the back.\n"+
"There is also a bench in the center, where customers sit to\n"+
"try on shoes.\n";

items = ({
"register","It has cob webs on it",
"bench","Fat ladies sit on this bench to try on shoes.  Al tries not to look up their dresses",
});

dest_dir = ({
"/players/jenny/bundy/rooms/m3b","east",
});
}
init() { 
    ::init(); 
   this_player()->set_fight_area();
}
