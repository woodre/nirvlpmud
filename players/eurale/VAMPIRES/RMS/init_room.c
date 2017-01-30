inherit "room/room";
#include "check.h"
#include "/players/eurale/defs.h"

reset(arg) {
  if(arg) return;
if(!present("book")) {
  move_object(clone_object("players/eurale/VAMPIRES/OBJ/vbook.c"),
    this_object()); }
set_light(1);

short_desc = "Gathering Room";
long_desc =
  "A pale yellow hue is emited from the semi-transparent floor of this\n"+
  "large room suspended high above Nirvana.  The vampire guild hall\n"+
  "beckons from the south.  Burning torches surround the sacred meeting\n"+
  "place.  Those who have chosen the path of darkness are invited here.\n"+
  "In the center of the room on a raised, granite pedestal sits an old\n"+
  "book.  Those who are considering the vampire guild or who have already\n"+
  "chosen the path of darkness are invited here.  A small sign is\n"+
  "attached to the pedestal.\n";

items = ({
  "sign","A small, retangular sign written in blood in some strange "+
         "language",
  "pedastal","A massive stone structure that provides a reading platform\n"+
             "for the oldest of vampire manuals",
  "floor","You gaze through the floor and can make out the streets of\n"+
          "Nirvana below with its players hustling about",
  "hall","You can just make out some indistinct features in the hall\n"+
         "to the south",
  "torches","Straw-like material, soaked in oil and bound tightly\n"+
            "together that burns with a bright, smokeless light",
});

dest_dir = ({
  "room/church.c","church",
  "players/eurale/VAMPIRES/RMS/wing_room.c","south",
});

}

init() {
  ::init();
  add_action("South","south");
  add_action("Read","read");
  add_action("Eject","eject");
}

Read(str) {
if(!str) { write("Read what?\n"); return 1; }
if(str == "sign") {
  if(!present("vampire fangs",TP)) {
    write("You cannot decypher the sign.\n");
    return 1; }
  write(RED+
    "The sign reads:\n"+
    "  This is the vampire initiation room.  Any unwanted player may\n"+
    "be ejected from here by ANY vampire family member.  This room is\n"+
    "to be used to induct new members.  If a player is not a family\n"+
    "member, just use 'eject <name>'.\n"+NORM);
  return 1; }
}

Eject(str) {
object ob;
if(!present("vampire fangs",TP)) return 0;
if(!str) { write("Eject who?\n"); return 1; }
ob = present(str,ETP);
if(!ob->is_player()) {
  write("That object is not a player.\n");
  return 1; }
if(present("vampire fangs",ob)) {
  write("A voice whispers, 'You cannot eject another family member!'\n");
  return 1; }
ob->move_player("church#room/church.c");
write("You have ejected "+capitalize(str)+" from the room.\n");
return 1;
}

South() {
object ob;
ob = present("vampire fangs",TP);
if(!ob) {
  write("A voice whispers, 'Only members of the family may pass this\n"+
        "way'... and you are pushed back.\n");
  return 1; }
else {
  TP->move_player("south#players/eurale/VAMPIRES/RMS/wing_room.c");
  return 1; }
}
