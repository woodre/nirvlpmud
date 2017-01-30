inherit "room/room";
#include "DEFS.h"

reset(arg) {
  if(arg) return;
if(!present("trashcan")) {
  move_object(clone_object("players/eurale/VAMPIRES/OBJ/trashcan"),TO); }
set_light(0);

short_desc = HIK+"Sleezy Sofa Lounge"+NORM;
long_desc =
  "Cut into the solid, black rock is a circular room with large chairs\n"+
  "and curved sofas lining the walls.  Small tables sit about the room\n"+
  "as if they were used to play cards or other games by people enjoying\n"+
  "the company of one another.  A curved hole in the wall houses a cozy\n"+
  "fire that provides the dim light in the room.  It also illuminates\n"+
  "the small sign on the wall by the door.\n";

items = ({
  "sign","A neatly printed sign for all to read",
  "sofas","Overstuffed leather couches with worn patches from much\n"+
            "use over the years",
  "chairs","Thick, stuffed chairs with high backs covered in dark "+
           "fabric",
  "tables","Circular stone tops on stone bases",
  "hole","A small fireplace radiating warmth",
});

dest_dir = ({
  "players/eurale/VAMPIRES/RMS/nosferatu","east",
});

}

realm() { return "NM"; }

init() {
  ::init();
  add_action("eject","eject");
  add_action("read","read");
}

eject(str) {
  object who;
if(!present("vampire fangs",TP)) {
  write("Only vampires can eject others from this room.\n");
  return 1; }

if(!str) { write("Eject who?\n"); return 1; }

who = present(str,TO);
if(!who) {
  write(capitalize(str)+" isn't here.\n");
  return 1; }

command("east",who);
write("You eject "+capitalize(str)+" from the lounge.\n");
return 1;
}

read(str) {
if(!str) { write("Read what?\n"); return 1; }
if(str == "sign") { write(
  "The sign reads:\n"+
  "  You are a guest of the Vampire Guild in the Sleezy Sofa Lounge.\n"+
  "  Any vampire can 'eject' you from the lounge for any reason so\n"+
  "  be on your best behavior and leave the lights outside, please.\n");
  return 1; }
}
