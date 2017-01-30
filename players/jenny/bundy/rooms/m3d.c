inherit "/players/jenny/room";
#include "/players/jenny/define.h"
realm() { return "NT"; }
reset(arg) {
if(!present("mall walker"))  {
MOCO("/players/jenny/bundy/mobs/walker.c"),this_object()); }
    if(arg) return;
    set_light(1);
     set_listen(""+BOLD+"You hear the general chatter of people shopping."+NORM+"\n");
     set_search(""+BOLD+"You notice some coins in the fountain."+NORM+"\n");
short_desc=(""+GRN+"The Mall"+NORM+"");
long_desc=
"This is the mall where Al Bundy works.  People come from\n"+
"all over Chicago to buy things here.  There is a big fountain\n"+
"in front of you.  The mall is not very busy lately.  Some shoe\n"+
"salesman has been doing his best to scare customers away.\n";
items = ({
"fountain","Al Bundy often fishes coins out of this fountain to buy lunch",
"coins","Al Bundy will be fishing these nickels and pennies out of the fountain",
});

dest_dir = ({
"/players/jenny/bundy/rooms/m3c","north",
"/players/jenny/bundy/rooms/m3e","south",
});
}
init() { 
    ::init(); 
   this_player()->set_fight_area();
}
