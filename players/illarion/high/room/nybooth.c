inherit "room/room";
#include "/players/illarion/dfns.h"

reset(arg) {
  if(arg) return;

  set_light(1);
  short_desc="A New York City phone booth";
  long_desc=
"You stand in a typical big city phone booth, facing the phone.  Oddly,\n"+
"the phone itself seems to be reasonably intact; the cord is attached\n"+
"to the receiver, and all the buttons are still there.  An empty phone book\n"+
"cover hangs down under the phone.  The windows are too dirty to look out,\n"+
"but you can see a street out the open door.\n";
  items= ({
  "phone",
    "A metal pay phone, ostensibly made by some phone company to be long-\n"+
    "lasting, with a coins slot, the usual buttons, and a receiver on the\n"+
    "hook.  Even though the receiver looks nasty, you are overcome with\n"+
    "an urge to "+BLD("lift")+" it",
  "receiver",
    "A truly nasty looking piece of the phone, yet you want to "+BLD("lift")+" it",
  "street",
    "Asphault, strewn with garbage.  A big city street",
  "booth",
    "The structure you are currently standing inside",
  "cover",
    "Predictably, the phone book has been stolen from inside it",
  "windows",
    "Glass, covered with dirt.  You refuses to look closer",
  "cord",
    "A metal sheathed cord, further protected by dirt and germs",
  });
  dest_dir= ({
    HROOM+"nystreet","out",
  });
}
void init() {
  ::init();
  add_action("cmd_lift","lift");
}
cmd_lift(str) {
  if(!str) FAIL("Lift what?\n");
  if(str != "receiver") FAIL("You cannot lift that.\n");
  write("You lift the phone, and feel reality wrench around you briefly,\n"+
        "then settle back into place.\n");
  say(TPN+" lifts the phone.  A rift in reality opens.\n");
  TP->move_player("into a rift in reality#"+HROOM+"booth");
  return 1;
}
