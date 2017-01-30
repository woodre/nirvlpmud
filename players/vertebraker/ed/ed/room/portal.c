#include "/players/vertebraker/define.h"
#include "/players/vertebraker/ed/paths.h"
inherit ROOM;
reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "A dark catacomb";
  long_desc =
"     A pillar stands in the middle of the room, with the Necronomicon lying on\n"+
"top of the stone table.  Darkness enshrouds the rest of the room - You can't\n"+
"make out any significant features.\n";
  items = ({
"pillar","The stone pillar only rises to about five feet",
"necronomicon","The Book of the Dead waits for someone to open it...",
});

}

init() {
  ::init();
  add_action("open","open");
  }

open(arg) {
  if(!arg) { write("Open what?\n"); return 1; }
  if(arg == "book" || arg == "necronomicon") {
    write("You open up the book....\n\n"+
  HIY+"-= GOLDEN LIGHT BRINGS YOU TO THE VILLAGE GREEN =-\n\n"+NORM);
  say(TPN+" opens the book and golden light shoots forth!\n"+
   TPN+" disappears and the book closes.\n");
 move_object(TP, "/room/vill_green");
  tell_room(ENV(TP),HIY+TPN+" arrives in a flash of light!\n"+NORM,({TP}));
  command("look",TP);
  return 1; }
}

realm() { return "NT"; }
