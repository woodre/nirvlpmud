/* Help provided by The Great Jaraxleio */
#include "/open/ansi.h"
#define TP this_player()
#define TPN this_player()->query_name()
inherit "/players/vertebraker/closed/std/room";
int SEARCH;

reset(arg) {
SEARCH = 0;
  if(arg) return;

if (!present("queen ant")) {
  move_object(clone_object("/players/pestilence/amity/mob/queen.c"),
        this_object()); }

long_desc =
  "    This is a large chamber where the Queen Ant usually resides.\n"+
  "The chamber is very large and open, while the tunnel only goes back\n"+
  "to the north.  In this chamber the queen seems to be protecting\n"+
  "something.  There is some blood splattered on the on the dirt floor.\n"+
  "Some of the dirt on the floor seems to be loose rather than the\n"+
  "well packed dirt in the other parts of the tunnel.\n";
set_light(0);
add_property("NT");

items = ({
"wall","Is made of dirt",
"floor","The dirt is well packed except a small part of lose dirt, maybe your could search the dirt",
"dirt","Normal brown dirt, maybe you could search it",
"path","A path leading to the north",
"tunnel","A dirt tunnel leading back to the north",
"blood","A "+RED+"blood"+NORM+" trail on the dirt floor, leading to the north",
"chamber","A large chamber where the Queen Ant resides",
"area","A large open area where the guards for the queen are usually stationed",
});

dest_dir = ({
"/players/pestilence/amity/room/tunsw2.c","north",
});
}

short() {
    return ""+YEL+"Queen's Chamber"+NORM+"";
}


init() {
  ::init();
  add_action("search","search");
  add_action("jump_down","jump");  
}

search(arg){          
  if(SEARCH == 1){ write("The dirt has already been searched and moved.\n"); return 1; }
  if(arg == "dirt"){
    write("You search through the dirt, exposing a hidden chamber.\n"+
          "Maybe you could 'jump down' to the chamber.\n");        
SEARCH +=1;return 1; }
    write("Search what?\n");
return 1; }

jump_down(arg){
  if(SEARCH == 0){ write("Jump where?\n"); return 1; }

    if(!arg) { notify_fail("Jump where?\n");
       return 0;}
  if(arg == "down"){
    write("You jump down into the chamber.\n");
    say(TPN+" jumps into the lower chamber!\n");
 move_object(this_player(), "/players/pestilence/amity/room/eggchamber.c");  
return 1; }
else
{
       notify_fail("You may only jump down.\n");
       return 0;
}
}
