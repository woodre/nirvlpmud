#include "/players/linus/def.h"
#define NAME HBWHT+RED+"S"+BLU+"oldier"+BLU+" F"+RED+"ield"+NORM+" (Bears "+bscore+" vs. "+opponent+" "+oscore+")"
inherit "/players/vertebraker/closed/std/room.c";
string opponent;
int oscore,bscore;
reset(arg) {
 if(!arg) {
 set_light(1);
 set_long(
"To change scores: 'bscore' sets the bears score and 'oscore' sets the opponents\n"+
"You can set the opposing teams name by 'name' the opposing team name.\n");
add_item("blah","blah blah blah");
}
}
short() { return NAME; 
}
init() {
::init();
 add_action("name_opp","name");
 add_action("south","south");
 add_action("set_bscore","bscore");
 add_action("set_oscore","oscore");
}
name_opp(string str) {
if(!str) { notify_fail("Usage: name <team>\n");
return 0; }
return opponent = capitalize(str);
return 1;
}
set_bscore(int x) {
 return bscore = x;
return 1;
}
set_oscore(int x) {
 return oscore = x;
return 1;
}
south() {
 TP->move_player("south#/players/linus/workroom.c");
return 1;
}
