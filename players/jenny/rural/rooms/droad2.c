inherit "/players/jenny/room";
#include "/players/jenny/define.h"
realm() { return "NT"; }
reset(arg) {
    if(arg) return;
    set_light(1);
    set_search(BOLD+"You search along the edges of the woods, but find nothing of interest."+NORM);
    set_listen(BOLD+"You hear the leaves rustling in the wind."+NORM);
    set_smell(BOLD+"You take in a breath of that crisp, fresh autumn air."+NORM);
long_desc=
"This is a narrow dirt road winding through the northern woods.\n"+      
"It stretches as far as the eye can see to the east and west.  Thick\n"+
"woods, full of trees showing off their beautiful fall colors, are on\n"+
"both sides of the road.\n";

items = ({
"road","A narrow dirt road that stretches east to west.  It is partially covered by\n"+
            "leaves which have fallen from the trees",
"leaves","Fallen leaves are everywhere, on the road and blanketing the floor of the woods",
"woods","The woods seem to endlessly stretch in every direction.  They are full of trees,\n"+
               "showing off their fall colors",
"trees","There is a good mix of hardwood trees, their leaves are colored bright shades\n"+
            "of yellow, red, and brown",
});

dest_dir = ({
"/players/jenny/rural/rooms/droad1","west",
"/players/jenny/rural/rooms/droad3","east",
});
}
short() {
return "A Dirt Road."; }
init() { 
    ::init(); 
   this_player()->set_fight_area();
}
