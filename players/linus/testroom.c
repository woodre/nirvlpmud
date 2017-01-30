#include "/players/linus/def.h"
#define NAME RED+"S"+BLU+"oldier"+BLU+" F"+RED+"ield"+NORM+" (Go Bears!)"
inherit "/players/vertebraker/closed/std/room.c";
reset(arg) {
 if(!arg) {
 set_light(1);
 set_long(
"blah blah blah blah blah blah \n\
blah blah blah blah blah blah blah \n\blha blah blah \n");
add_item("blah","blah blah blah");
}
}
short() { return NAME; 
}
init() {
 ::init();
add_action("heavenorhell","pass");
}
heavenorhell() {
if(this_player()->query_alignment()>=0) {
 this_player()->move_player("into the light#/players/linus/Plains/room/r1.c");
return 1;

}
else
this_player()->move_player("into the bowels of hell#/players/linus/workroom.c");
return 1;
}
