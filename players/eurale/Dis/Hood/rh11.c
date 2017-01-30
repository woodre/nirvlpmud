#include "DEFS.h"
inherit "room/room";

reset(arg) {

if(!present("marian")) {
  move_object(clone_object("players/eurale/Dis/Hood/NPC/marian"),TO); }

  if(arg) return;
set_light(1);

short_desc = GRN+"Sherwood Forest"+NORM;
long_desc =
	"  You are in Sherwood Forest.  The huge, old hardwoods have\n"+
	"grown uncontested for decades.  Their massive trunks and\n"+
	"sprawling branches provide both protection and cover for the\n"+
	"many forest inhabitants.\n";

items = ({
	"hardwoods","Oak, Walnut, Hickory and Ask",
	"trunks","Mammoth-sized with large, scaley bark",
});

dest_dir = ({
	"players/eurale/Dis/Hood/rh14.c","south",
	"players/eurale/Dis/Hood/rh13.c","southwest",
	"players/eurale/Dis/Hood/rh10.c","west",
	"players/eurale/Dis/Hood/rh9.c","northwest",
});

}

init() {
  ::init();
  add_action("south","south"); }

south() {
object ob;
  ob = present("marian");
if(ob) {
  write("Marian pleads: Please don't leave me....\n");
  say("Marian begins to cry....\n");
  return 1; }
}
