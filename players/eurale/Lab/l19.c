#include "DEFS.h"
inherit "room/room";

reset(arg) {
  if(arg) return;
if(!present("guardian")) {
  move_object(clone_object("/players/eurale/Lab/NPC/yugoloth.c"),TO); }
set_light(0);

short_desc = "Labyrinth";
long_desc =
  "  The rocky tunnel is much lighter to the west.  Soft, green moss clings\n"+
  "to the tunnel sides here. There are small patches of weeds growing up\n"+
  "from dirt that has accumulated in pockets in the rough rock.\n";

items = ({
  "tunnel","A hole cut through the rock disappearing into darkness\n"+
           "to the northeast",
  "moss","Almost irridescent in the soft light, this growing mass\n"+
         "seems to shimmer as if moving",
  "weeds","Rough leaves with small nettles on them and in the center\n"+
          "a stem with a dark, purple flower",
  "dirt","Rich, brown dirt that seems oddly out of place",
});

dest_dir = ({
  "players/eurale/Lab/l5.c","northeast",
  "players/eurale/Lab/l22.c","west",
});

}

realm() { return "NT"; }

init() {
  ::init();
  add_action("Search","search");
  add_action("Drop","drop");
}

Search(str) {
if(!str) { write("What?\n"); return 1; }
if(str == "pocket" || str == "pockets") {
  write("As you search the rough "+str+" you discover a hole leading\n"+
        "down.  There seems to be no way down unless you were to drop\n"+
        "to the surface below.\n");
  return 1; }
write("You search the "+str+" but find nothing of interest.\n");
return 1;
}

Drop(str) {
 if(str)
 { 
   this_player()->cmd_drop(str);
 }
 if(!str)
 {
   write("\nYou take a breath and jump into the hole.....\n\n"+
      "You hit the ground with hard THUD!\n\n");
   TP->move_player("into the dark#/players/eurale/Lab/l20.c");
   return 1; 
 }
}
