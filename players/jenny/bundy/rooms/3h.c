inherit "/players/jenny/room";
#include "/players/jenny/define.h"
realm() { return "NT"; }
reset(arg) {
if(!present("Ike"))  {
MOCO("/players/jenny/bundy/mobs/ike.c"),this_object()); }
    if(arg) return;
    set_light(1);
     set_smell(""+YEL+"It smells like stale beer."+NORM+"\n");
     set_search(""+BOLD+"You notice a stage, with some dancers on it."+NORM+"\n");
     set_listen(""+RED+"You hear upbeat music."+NORM+"\n");
short_desc=(""+MAG+"The Jiggly Room"+NORM+"");
long_desc=
"This is the best section of the Jiggly Room.  You are right in\n"+
"front of the stage, and have the best view of the dancers.  If\n"+
"you are a good tipper, maybe you will get an article of clothing\n"+
"or two tossed your way.\n";

items = ({
"stage","Maybe you could 'climb' onto the stage",
"dancers","The dancers smile at you and wink",
});

dest_dir = ({
"/players/jenny/bundy/rooms/3g","north",
"/players/jenny/bundy/rooms/2h","west",
"/players/jenny/bundy/rooms/4h","east",
});
}
init() { 
    ::init(); 
   this_player()->set_fight_area();
add_action("stage","climb");
}
stage(arg) { 
if(!arg) { return 0; }
if(arg == "stage") {
write("You climb onto the stage to shake your booty with the dancers.\n");
TP->move_player("onto the stage#players/jenny/bundy/rooms/3i.c");
return 1; }
}
