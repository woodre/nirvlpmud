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
     set_search(BOLD+"You notice some booths along the back wall."+NORM+"\n");
     set_listen(BOLD+"You can hear some players shooting the puck around on the ice."+NORM+"\n");
long_desc=
"This is the upper section of the Joe Louis Arena stands.  When\n"+      
"full, these stands seat about 20,000 people.  There are padded\n"+
"red and white seats, which look pretty comfortable.  This section\n"+
"stretches all the way back to the far wall of the arena.  There are\n"+
"booths behind parts of these walls for the media.  The view from\n"+
"up here isn't as good as it is from the lower section, but they are\n"+
"still good seats.\n";

items = ({
"stands","These are the seats of Joe Louis Arena.  There are about 20,000 of them",
"seats","These are padded red and white seats.  They fold up when not occupied",
"window","This is a big opening in the booth, which allows the press a view of the game.\n"+
          "It has no glass, so you could easily 'crawl' through the 'window' to get inside",
"booths","The media sit in these booths while reporting the game.  You could\n"+
                "probably crawl through the window and get inside the booth",
});

dest_dir = ({
"/players/jenny/wings/rooms/stands1c1","down",
});
}
short() {
return BOLD+RED+"Joe Louis Arena stands"+NORM; }
init() { 
    ::init(); 
   this_player()->set_fight_area();
add_action("window","crawl");
}
window(arg) {
if(!arg) {return 0;}
if(arg == "window" | arg == "booth" | arg == "through window") {
TP->move_player("through the window#players/jenny/wings/rooms/hnic.c");
return 1; }
}
