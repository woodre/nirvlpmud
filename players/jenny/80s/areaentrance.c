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
"PLEASE.  IT MUST BE!\n";
items = ({
"man","A wrinkled old man wearing a blue sports jacket and fishnet stockings",
"wrapper","Some well chewed brocolli flavored gum is stuck to the wrapper",
"bicycle","This has one huge front wheel, and two smaller wheels in the back",
"alligators","Orange fire breathing alligators you can handle, but how did they get braces?",
"ladies","Old ladies dressed in German WWI uniforms and knitting quilts",
});
dest_dir = ({
"/players/jenny/bundy/rooms/1e","bundy",
"/players/jenny/dukes/rooms/r1","hazzard",
"/players/jenny/80s/rooms/14","80s",
"/room/plane11","out",
});
}
short() {
return CYN+"Somewhere, but where?"+NORM; }
init() {        
    ::init();  
add_action("bundyenter","bundy");
add_action("dukeenter","hazzard");
add_action("eighties","80s");
}

bundyenter(arg) { 
write_file("/players/jenny/logs/bundyusage", ""+TPRN+" entered 1e.c at "+ctime()+"\n");
TP->move_player("bundy#players/jenny/bundy/rooms/1e.c");
return 1; }
dukeenter(arg) {
#include "/players/jenny/dukes/dukeinh.h"
randomduke;
write_file("/players/jenny/logs/dukesusage", ""+TPRN+" entered Hazzard at "+ctime()+"\n");
return 1; }
eighties(arg) {
write_file("/players/jenny/logs/80s", ""+TPRN+" relived the 80's on "+ctime()+"\n");
TP->move_player("bundy#players/jenny/80s/rooms/14.c");
return 1; }
