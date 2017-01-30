inherit "/players/jenny/room";
#include "/players/jenny/define.h"
realm() { return "NT"; }
reset(arg) {
    if(arg) return;
     set_smell(BOLD+"A mild stench is in the air."+NORM);
     set_search(BOLD+"You find an old notebook next to the broken table."+NORM);
set_light(0);
long_desc=
"This is small laboratory, which clearly has not been used in years.\n"+      
"The cement floor is littered with broken glass, and the rafters are\n"+
"covered with cobwebs.  A large table, in the center of the lab, is\n"+
"overturned and broken in half.   Large wooden cabinets cover one\n"+
"of the walls, while rows of long shelves are on the other three.\n"+
"There is a sink on the counter along the back wall.\n";
short_desc=(BOLD+"laboratory"+NORM);

items = ({
"cabinets","Large, homemade wooden cabinets cover one of the walls.  They\n"+
                  "are darkly stained,  A wooden handle hangs from a chain at one end",
"handle","This is small wooden handle which hangs from a chain.  It must be\n"+
                "pulled to rotate the cabinets and exit",
"floor","The dirty, grey, cement floor.  It is littered with broken beakers and\n"+
            "test tubes",
"notebook","There is lots of writing in this old notebook.  You could try reading it",
"sink","The basin of this sink is a large, badly stained, plastic tub, with a rusty\n"+
           "spigot hanging over it.  A few broken test tubes and beakers line the\n"+
           "bottom",
"rafters","This is the underside of the first floor.  A proper ceiling was never\n"+
               "installed.  The wooden beams are filled with cobwebs",
"beams","Wooden beams which are used to support the first floor",
"cobwebs","Cobwebs have formed in the rafters",
"spigot","A rusty metal spigot which hangs over the sink.  There are two small\n"+
              "knobs next to it for turning the water on",
"knobs","Two plain metal knobs, which look almost like bars.  They can be turned",
"counter","A black counter, which runs along the back wall.  Beakers and test tubes\n"+
                "are scattered along it.  The counter also has a sink in the center",
"table","This large wooden table looks like it was homemade.  It has 2x4's for legs,\n"+
             "which are crudely nailed to a plywood top.  The table has been broken\n"+
             "in half and overturned",
"glass","Broken beakers and test tubes are all over the place",
"shelves","Long wooden shelves, which run along three of the walls.  They are filled\n"+
                "with dusty beakers, test tubes, boxes, and even a few cages",
"beakers","There are plenty of dusty old glass beakers around the lab",
"skeletons","The remains of two dead rats",
"chain","A metal chain, attached to a small wooden handle",
"cages","There are a few metal rat cages on the shelves.  One of them has two small\n"+
             "skeletons in it",
"test tubes","There are plenty of dusty old glass test tubes around the lab",
"boxes","There are several plain brown boxes on the shelves",

});
}
init() { 
    ::init(); 
   this_player()->set_fight_area();
add_action("lableave","pull");
add_action("sink","turn");
add_action("notebook","read");
}
lableave(arg) {
if(!arg) {return 0;}
if(arg == "handle" | arg == "the handle" | arg == "chain" | arg == "the chain") {
write("You pull the handle and watch as the cabinet rotates, revealing the\n"+
         "secret exit.\n");
say(TPN+" pulls the handle and you watch as the cabinet rotates, revealing the\n"+
       "secret exit.\n");
TP->move_player("through the secret exit#players/jenny/house/rooms/cellar.c");
return 1; }
}
sink(arg) {
if(!arg) {return 0; }
if(arg == "knobs" | arg == "the knobs" | arg == "knob" | arg == "the knob") {
write("You turn the knobs, but no water comes out.\n");
return 1 ;}}
notebook(arg) {
if(!arg) {return 0;}
if(arg == "notebook" | arg == "the notebook") {
write("It is written in some form of shorthand which you don't understand.\n");
return 1; }}
