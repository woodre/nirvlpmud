inherit "/players/jenny/room";
#include "/players/jenny/define.h"
realm() { return "NT"; }
reset(arg) {
if(!present("fan"))  {
if(random(20) < 13) {
MOCO("/players/jenny/wings/mobs/other/mfan.c"),TO); 
MOCO("/players/jenny/wings/mobs/other/ffan.c"),TO);}}
    if(arg) return;
    set_light(1);
     set_listen(BOLD+"You can hear some players shooting the puck around on the ice."+NORM+"\n");
long_desc=
"These are the Joe Louis Arena stands.  When full, they seat\n"+      
"about 20,000 people.  The padded red and white seats look\n"+
"pretty comfortable.  This section of seats stretches all the way\n"+
"down to the plexiglass.  It provides a very good view of the\n"+
"game.  Only season ticket holders have a prayer of landing\n"+
"these seats.  The ordinary fans sit in the upper section.\n";

items = ({
"stands","These are the seats of Joe Louis Arena.  There are about 20,000 of them",
"seats","These are padded red and white seats.  They fold up when not occupied",
"plexiglass","This is a clear hard plastic material which allows fans to watch the\n"+
                     "game, while still protecting them from getting hit with pucks",
});

dest_dir = ({
"/players/jenny/wings/rooms/stands2c3","up",
"/players/jenny/wings/rooms/c3","concourse",
});
}
short() {
return BOLD+RED+"Joe Louis Arena stands"+NORM; }
init() { 
    ::init(); 
   this_player()->set_fight_area();
}
