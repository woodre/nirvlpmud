#include "defs.h"
inherit "room/room";

reset(arg) {

if(!present("squaw")) {
  move_object(clone_object("players/eurale/Drygulch/NPC/squaw"),TO); }
if(!present("chief")) {
  move_object(clone_object("players/eurale/Drygulch/NPC/chief"),TO); }

  if(arg) return;
set_light(1);

short_desc = "teepee";
long_desc =
	"  You have entered one of the Indian teepees.  There is a small \n"+
	"pit in the center of the floor, bedding and personal items piled \n"+
	"along the outside wall and the smell of wood smoke that has \n"+
	"permeated the hides from many days fires lingers in the air. \n";

items = ({
	"pit","A small cavity for a warming fire on cold days or evenings",
	"bedding","Hides of various types to lay on and be used for blankets",
	"items","Clothes, rawhide strips for tying and cooking utensils",
});

dest_dir = ({
	"/players/eurale/Drygulch/dgs15.c","southeast",
});

}
