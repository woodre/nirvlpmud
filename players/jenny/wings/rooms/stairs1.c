inherit "/players/jenny/room";
#include "/players/jenny/define.h"
realm() { return "NT"; }
reset(arg) {
if(!present("fan"))  {
if(!random(7)) {
MOCO("/players/jenny/wings/mobs/other/mfan.c"),TO); }}
    if(arg) return;
    set_light(1);
     set_search(BOLD+"You notice some cigarette butts on the ground"+NORM+"\n");
     set_smell(BOLD+"This stairwell has a terrible smell.  It seems as if someone\n"+
                                   "has relieved themselves here."+NORM+"\n");
long_desc=
"This is a dimly lit stairwell, which allows passage from ice\n"+      
"level, all the way up to the suites.  A red hand railing is on\n"+
"each side of the stairwell, to help keep people from slipping.\n"+
"The grey concrete stairs feel hard and sticky, adding to the\n"+
"unpleasant atmosphere.\n";
items = ({
"stairs","These stairs are made of grey concrete, and are very sticky.  Spilled\n"+
              "beer, coke, cigarette buts, and god knows what else litter this\n"+
               "stairwell",
"railing","This is a red hand railing that you can grab to provide balance",
"cigarette butts","These are cigarette butts, which were littered by smokers who\n"+
                           "were too lazy to go outside",
});

dest_dir = ({
"/players/jenny/wings/rooms/stairs2","up",
 "/players/jenny/wings/rooms/stairsb","down",
"/players/jenny/wings/rooms/c4","exit",
});
}
short() {
return BOLD+"A stairwell"+NORM; }
init() { 
    ::init(); 
   this_player()->set_fight_area();
}
