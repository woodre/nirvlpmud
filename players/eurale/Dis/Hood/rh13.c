#include "DEFS.h"
inherit "room/room";

reset(arg) {

if(!present("john")) {
  move_object(clone_object("players/eurale/Dis/Hood/NPC/ljohn"),TO); }

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
	"players/eurale/Dis/Hood/rh10.c","north",
	"players/eurale/Dis/Hood/rh11.c","northeast",
	"players/eurale/Dis/Hood/rh14.c","east",
	"players/eurale/Dis/Hood/rh17.c","southeast",
	"players/eurale/Dis/Hood/rh16.c","south",
	"players/eurale/Dis/Hood/rh15.c","southwest",
	"players/eurale/Dis/Hood/rh12.c","west",
});

}

init() {
  ::init();
  add_action("east","east"); }

east() {
object ob;
  ob = present("john");
if(ob) {
  write("John says: Sorry, can't go that way!\n");
  say("Little John says 'Can't go that way!'\n");
  return 1; }
}
