inherit "/players/jenny/room";
#include "/players/jenny/define.h"
realm() { return "NT"; }
reset(arg) {
    if(arg) return;
    set_light(1);
    set_search(BOLD+"You search along the edges of the woods, but find nothing of interest."+NORM);
    set_listen(BOLD+"You hear the leaves rustling in the wind and the creek running under the bridge."+NORM);
    set_smell(BOLD+"You take in a breath of that crisp, fresh autumn air."+NORM);
long_desc=
"This is a narrow dirt road winding through the northern woods.\n"+      
"It stretches as far as the eye can see to the east and west.  A small\n"+
"wooden bridge takes the road over a little creek.  Thick woods,\n"+
"full of trees showing off their beautiful fall colors, are on both\n"+
"sides of the road.\n";

items = ({
"road","A narrow dirt road that stretches east to west.  It is partially covered by\n"+
            "leaves which have fallen from the trees",
"leaves","Fallen leaves are everywhere, on the road and blanketing the floor of the woods",
"bridge","A small wooden bridge which takes the road over the creek below.  It has\n"+
               "guardrails on each side.  The wood is very weathered, and some of the boards\n"+
                "are starting to rot",
"guardrails","Simple guardrails, a board running between two posts, are on each side of\n"+
                    "of the bridge.  One of the rails has a symbol carved into it",
"symbol","A pentagram is carved deep into the wooden guardrail",
"posts","Two log posts support each guardrail",
"boards","The floor of the bridge is made up of boards of wood.  Many of them are starting\n"+
                "to rot, due to being exposed to the weather over the decades",
"creek","A small creek runs under the bridge, and off into the woods.  It is a few feet\n"+
             "wide with a rocky bottom and a fast current.  The water looks safe to drink",
"woods","The woods seem to endlessly stretch in every direction.  They are full of trees,\n"+
               "showing off their fall colors",
"trees","There is a good mix of hardwood trees, their leaves are colored bright shades\n"+
            "of yellow, red, and brown",
});

dest_dir = ({
"/players/jenny/rural/rooms/droad2","west",
"/players/jenny/rural/rooms/droad4","east",
});
}
short() {
return "A Dirt Road."; }
init() { 
    ::init(); 
   this_player()->set_fight_area();
   add_action("water","drink");
}
water(arg) {
if(!arg) {return 0;}
if(arg == "water") {

if(!TP->drink_soft(10)) { write("You couldn't possibly drink any more water.\n"); return 1; }
write("You cup your hands and drink some "+HIB+"water"+NORM+" from the creek.\n");
TP->heal_self(1);
return 1; }}
