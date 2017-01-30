inherit "/players/jenny/rhps/room";
#include "/players/jenny/define.h"
realm() { return "NT"; }
reset(arg) {
    if(arg) return;
    set_light(1);
     set_listen(""+HIB+"You hear the rain pounding against the ground.\n"+
                      "Noises can also be heard inside the castle."+NORM+"");
short_desc=(""+RED+"~ "+NORM+""+BOLD+"The outskirts of Denton "+NORM+""+RED+"~"+NORM+"");
long_desc=
"It is a dark and rainy night.  The trees are swaying, and\n"+
"this wind is chilling you to the bone.  You have traveled\n"+
"quite a ways from the main road.  A huge castle stands\n"+
"before you.  It looks very old, yet impressive.  One cannot\n"+
"help having an eery feeling about this place. \n";
items = ({
"trees","Autumn has stripped the trees of most of their leaves",
"road","A long windy country road.  A motorcycle zooming by",
"castle","This castle belongs to Dr. Frank N. Furter.  The lights\n"+ "are on inside, and it appears safe to enter",

});
dest_dir = ({
  "/players/jenny/rhps/rooms/areaenterence.c","leave",
});
}
init() { 
    ::init(); 
if(TP->query_level() < 15) {
   this_player()->set_fight_area(); }
add_action("castle","enter");
}
castle(arg) { 
if(!arg) { return 0; }
if(arg == "castle") {
write("You boldly enter the castle.\n");
TP->move_player("into the castle#players/jenny/rhps/rooms/castle1.c");
return 1; }
}
