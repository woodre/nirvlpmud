inherit "/players/jenny/room";
#include "/players/jenny/define.h"
realm() { return "NT"; }
reset(arg) {
    if(arg) return;
    set_light(1);
     set_smell(""+RED+"You smell a mongoose and nutmeg pie cooling in a far away window."+NORM+"\n");
      set_search(""+CYN+"You find a gum wrapper once thrown away by a guy who\n"+
"met Andy Griffith."+NORM+"\n");
     set_listen(""+MAG+"You hear schoolgirls complaining about the lack of polka music on MTV."+NORM+"\n");
short_desc=(""+CYN+"Somewhere, but where?"+NORM+"");
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
"/room/plane11","out",
});
}
init() {        
    ::init();  
add_action("bundyenter","bundy");
add_action("dukeenter","hazzard");
}

bundyenter(arg) { 
write_file("/players/jenny/bundy/usage", ""+TPRN+" entered 1e.c at "+ctime()+"\n");
TP->move_player("bundy#players/jenny/bundy/rooms/1e.c");
return 1; }
dukeenter(arg) {
#include "/players/jenny/dukes/dukeinh.h"
randomduke;
write_file("/players/jenny/dukes/usage", ""+TPRN+" entered Hazzard at "+ctime()+"\n");
return 1; }
