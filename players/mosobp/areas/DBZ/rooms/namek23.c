inherit "room/room";
#include "/players/nelk/define.h"
reset(arg){
    if(arg) return;
set_light(1);
set_short("A royal hallway");
set_long(
"This is a long hallway leading to the powerful King Vegeta. Fair warning: do no
t pick a fight with him, he is very powerful.  Strung along this end of the hall
way are the trophies prince Vegeta has won at competitions for strength and batt
le.");
add_item("trophies","Various awards for valor in combat and strength and ability
 that Prince vegeta has won.");
add_exit("/players/gohan/namek/namek26.c","south");
add_exit("/players/gohan/namek/namek28.c","north");
add_object("/players/gohan/learning/pguard2.c");
add_object("/players/gohan/learning/pguard2.c");
}
