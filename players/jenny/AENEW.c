inherit "/players/jenny/room";
#include "/players/jenny/define.h"
realm() { return "NT"; }
reset(arg) {
if(!present("machine"))  {
MOCO("/players/jenny/general/machine.c"),this_object()); }
    if(arg) return;
    set_light(1);
     set_smell(""+RED+"You smell a mongoose and nutmeg pie cooling in a far away window."+NORM+"\n");
      set_search(""+CYN+"You find a gum wrapper once thrown away by a guy who\n"+
"met Andy Griffith."+NORM+"\n");
     set_listen(""+MAG+"You hear schoolgirls complaining about the lack of polka music on MTV."+NORM+"\n");
long_desc=
"So this is where that portal leads?  How could it be?  What\n"+
"have you done to deserve this fate?  Looking around, it is\n"+
"hard to get an idea of exactly what this place is.  You see\n"+
"purple skies, yellow rain, and blue lightning striking down\n"+

"an elderly man riding a bicycle.  Orange alligators are\n"+
"somehow flying through the sky and breathing fire on old\n"+
"ladies while they knit quilts.  This must be a bad dream.\n"+
"PLEASE.  IT MUST BE!\n"+
"       There are four ways to escape this nightmare:\n"+
"		80s\n"+
"		bundy\n"+
"		hazzard\n"+
"		wings\n"+
"		out\n";
items = ({
"man","A wrinkled old man wearing a blue sports jacket and fishnet stockings",
"wrapper","Some well chewed brocolli flavored gum is stuck to the wrapper",
"bicycle","This has one huge front wheel, and two smaller wheels in the back",
"alligators","Orange fire breathing alligators you can handle, but how did they get braces?",
"ladies","Old ladies dressed in German WWI uniforms and knitting quilts",
});
}
short() {
return CYN+"Somewhere, but where?"+NORM; }
init() {        
    ::init();   
add_action("bundyenter","bundy");
add_action("dukeenter","hazzard");
add_action("eighties","80s");
add_action("jla","wings");
add_action("getout","out");
}

bundyenter() { 
   TP->move_player("bundy#players/jenny/bundy/rooms/1e.c");
   call_other("/players/jenny/workroom.c","bundy");
   return 1; }
dukeenter() {
#include "/players/jenny/dukes/dukeinh.h"
   randomduke;
   call_other("/players/jenny/workroom.c","duke");
   return 1; }
eighties() {
   TP->move_player("bundy#players/jenny/80s/rooms/14.c");
   call_other("/players/jenny/workroom.c","eighties");
   return 1; }
jla() {
   TP->move_player("Joe Louis Arena#players/jenny/wings/rooms/c1.c");
   call_other("/players/jenny/workroom.c","redwings");
   return 1; }
getout() {
   TP->move_player("out#room/plane11.c");
   return 1; }
