inherit "/players/jenny/room";
#include "/players/jenny/define.h"
realm() { return "NT"; }
reset(arg) {
    if(arg) return;
     set_smell(BOLD+"The air is damp and musty."+NORM);
     set_search(BOLD+"You notice a few broken bottles on the floor."+NORM);
set_light(0);
long_desc=
"This is a cold, damp wine cellar.  The dirty cement floor, and\n"+      
"cobwebs in the rafters indicate this cellar has not been cared for\n"+
"in quite some time.  There are racks along each wall, which hold\n"+
"hundreds of dusty bottles of wine.  A single lightbulb hangs\n"+
"overhead, with a string dangling from it.\n";
short_desc=(BOLD+"wine cellar"+NORM);

items = ({
"racks","There are dark wooden wine racks along each wall.  They hold\n"+
              "hundreds of dusty bottles of wine.  Cob webs have formed over\n"+
               "many of the bottles.  The rack along the back wall has a handle\n"+
               "on the side of it",
"handle","This is just a small wooden handle carved into the side of a wine\n"+
                "rack.  It looks possible to pull it",
"floor","The dirty, grey, cement floor has a drain in the middle of it",
"drain","A small metal grated drain used to help prevent flooding",
"rafters","This is the underside of the first floor.  A proper ceiling was never\n"+
               "installed.  The wooden beams are filled with cob webs",
"beams","Wooden beams which are used to support the first floor",
"cobwebs","Cobwebs have formed in the rafters and on the wine racks, making\n"+
               "it appear this cellar has not been cared for in quite some time",
"lightbulb","A broken lightbulb hangs overhead",
"light","A broken lightbulb hangs overhead",
"string","A plain piece of string which dangles from a broken light bulb",
"bottles","There are a few broken bottles on the floor, but no spilled wine",
"wine","Hundreds of bottles of wine are stacked in the racks.  Most of\n"+
             "the bottles have dust and cobwebs on them",
});

dest_dir = ({
 "/players/jenny/house/rooms/bas","out",
});
}
init() { 
    ::init(); 
   this_player()->set_fight_area();
add_action("labenter","pull");
add_action("lightbulb","pull");
}
labenter(arg) {
if(!arg) {return 0;}
if(arg == "handle" | arg == "the handle") {
write("You pull the handle and watch in amazement as the wine rack rotates, revealing\n"+
         "a secret entrance into another room.\n");
say(TPN+" pulls the handle and you watch in amazement as the wine rack rotates,\n"+
       "revealing a secret entrance into another room.\n");
TP->move_player("through the secret entrance#players/jenny/house/rooms/lab.c");
return 1; }
}
lightbulb(arg) {
if(!arg) {return 0; }
if(arg == "string" | arg == "the string") {
write("You pull the string, but nothing happens.\n");
return 1 ;}}
