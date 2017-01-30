inherit "/players/jenny/room";
#include "/players/jenny/define.h"
int justonce;
realm() { return "NT"; }
reset(arg) {
   justonce = 0;
    if(arg) return;
    set_light(1);
     set_smell(BOLD+"You take in a breath of that cold air."+NORM);
long_desc=
"This is one of the penalty boxes.  Players get sent here to serve\n"+      
"penalties.  There is a small bench, which will comfortably seat\n"+
"a few players.  A gate serves as a doorway between this box\n"+
"and the ice surface.  There is plexiglass behind the box,\n"+
"which provides some protection from often hostile fans.\n";
items = ({
"bench","This is a small wooden bench.  It will comfortably seat\n"+
                "a few players",
"gate","This gate is the only means of entering or leaving the penalty\n"+
            "box.  It has a small metal latch which opens it",
"plexiglass","This is a hard clear plastic which keeps the fans from getting\n"+
                      "hit by pucks, yet still gives a clear view of the action",
"latch","A small metal latch, which is used to open the gate",
});

dest_dir = ({
"/players/jenny/wings/rooms/ice2","exit",
});
}
short() {
return BOLD+RED+"penalty box"+NORM; }
init() { 
    ::init(); 
   this_player()->set_fight_area();
   add_action("pucks","search");
}
pucks() {
  if(justonce < 1) {
     write(BOLD+"You notice a puck on the floor."+NORM+"\n");
     MOCO("/players/jenny/wings/items/puck.c"),TO); 
     justonce = 5;
        return 1;}}
