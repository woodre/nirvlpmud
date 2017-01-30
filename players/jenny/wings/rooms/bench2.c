inherit "/players/jenny/room";
#include "/players/jenny/define.h"
int justonce;
realm() { return "NT"; }
reset(arg) {
   justonce = 0;
    if(arg) return;
    set_light(1);
     set_smell(BOLD+"You take in a breath of that cold air."+NORM);
     set_search(BOLD+"You notice a few broken sticks on the floor."+NORM);
long_desc=
"This is the place where the players who are not on the ice sit,\n"+      
"and the coaches stand, during games.  There is a long wooden\n"+
"bench which will seat nearly 20 players.  A ledge is on the inside\n"+
"of the boards, which gives players a place to set their water\n"+
"bottles.  A gate serves as a doorway between the bench and the\n"+
"ice surface.  There is plexiglass behind the bench, which separates\n"+
"players and coaches from the fans.\n";
items = ({
"bench","This is a long wooden bench.  It will seat about 20 players",
"gate","This gate is the only means of entering or leaving the bench,\n"+
            "other than hopping over the boards.  It has a small metal latch\n"+
            "which opens it",
"latch","A small metal latch, which is used to open the gate",
"plexiglass","This is a hard clear plastic which keeps the fans from getting\n"+
                      "hit by pucks, yet still gives a clear view of the action",
"sticks","These are hockey sticks that have been broken and discarded", 
"ledge","A ledge is inside the boards, stretching the length of the bench.\n"+
              "It is used as a shelf for players to set their water bottles on",
"boards","These boards are the barrier between the bench and the playing\n"+
                "surface",
});

dest_dir = ({
 "/players/jenny/wings/rooms/ice2","exit",
});
}
short() {
return BOLD+WHT+"The visitors bench"+NORM; }
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
        return 0;}}
