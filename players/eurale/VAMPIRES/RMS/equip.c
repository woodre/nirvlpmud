inherit "room/room";
#include "check.h"
#include "/players/eurale/defs.h"

object dagger, tuxedo, this_guy;
int set_max;
string str;

reset(arg) {
  if(arg) return;
if(!present("egor")) {
  move_object(clone_object("players/eurale/VAMPIRES/NPC/golem.c"),
    this_object()); }
set_light(0);

short_desc = "Vampire Supply Room";
long_desc =
  "This is a well stocked supply room.  Long shelves line the walls\n"+
  "with large bins underneath them. A large desk sits against the rear\n"+
  "wall along with an old wooden chair. A sign is attached to the front\n"+
  "of the desk.\n";

items = ({
  "shelves","Wooden platforms holding daggers, tuxedos and bags",
  "bins","Pockets built into the walls that hold more equipment",
  "shelf","A wooden platform coverd with bags, daggers and tuxedos",
  "daggers","Short blades, all black, with a wrapped handle",
  "tuxedos","Black tuxedos with long tails in various sizes",
  "bags","Large, black silk bags",
  "equipment","Tuxedoes, bags and daggers to help you fight",
  "desk","A square, wooden desk that has seen much use. The top is\n"+
         "uncluttered as if whoever sits here has nothing to do",
  "chair","A straight-backed wooden chair with a slat missing",
  "sign","A tarnished brass sign with red lettering still legible",
});

dest_dir = ({
  "players/eurale/VAMPIRES/RMS/wing_room","north",
  "players/eurale/VAMPIRES/RMS/shop","south",
  "players/eurale/VAMPIRES/RMS/vguild_hall","east",
  "players/eurale/VAMPIRES/RMS/mirrors","west",
});

}

realm() { return "NT"; }

init() {
  ::init();
  add_action("read","read");
/*
  check_membership(TP);
*/
}

read(str) {
if(!str) { write("Read what?\n"); return 1; }
if(str == "sign") { write(HIR+
  "    ******************************************************\n"+
  "    *                                                    *\n"+
  "    *                 Vampire Supply Room                *\n"+
  "    *                                                    *\n"+
  "    *   If you are small and in need of assistance, all  *\n"+
  "    *  you need to do is ask the supply golem for some   *\n"+
  "    *  help.  Just type 'equip me' and he will see that  *\n"+
  "    *  you get a couple of items to get you started.     *\n"+
  "    *                                                    *\n"+
  "    *        Good Luck and have an enjoyable outting.    *\n"+
  "    *                                                    *\n"+
  "    *                     Eurale, the Supreme Vampire    *\n"+
  "    *                                                    *\n"+
  "    ******************************************************\n"+
  NORM+"\n");
  return 1; }
}
