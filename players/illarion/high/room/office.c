inherit "room/room";
#include "/players/illarion/dfns.h"

reset(arg) {
  if(!present("Charlie DeSalvo"),this_object())
    move_object(HMON+"charlie",this_object());
  if(arg) return;

  set_light(1);
  short_desc="An office";
  long_desc=
"You have entered a rather old-fasioned office.  A plain wooden desk sits\n"+
"in the center of the room, facing south, toward a wall that's mostly\n"+
"windows, except for the door in the northeast corner of the room.  The\n"+
"phone hangs on the wall next to the door, above a small table with paper\n"+
"and some other items.  On the west end of the room, two large filing\n"+
"cabinets hold the dojo's records.  A clock hangs above the windows.\n";

  items= ({
    "office","That's right, you're in an office",
    "desk","A plainly made desk, neatly arranged, with a small lamp",
    "lamp","It provides light for close work on the desk.  Something about\n"+
           "the lamp "+BLD("reminds")+" you of something..",
    "door","It's made of wood, and opens and closes, like you'd expect",
    "table","The papers look to be mostly phone messages.  They and the\n"+
            "table are unremarkable.",
    "phone","Oh, look, it's a rotary dial phone!  Maybe you should give the\n"+
            "dialer a "+BLD("spin")+", for old times' sake",
    "cabinets","Unremarkable cabinets full of unremarkable papers that\n"+
               "detail the dojo's permission to exist and what it has done\n"+
               "to retain that permission",
    "clock","An accurate clock, twice a day, as it has stopped",
    "windows","A number of windows, framed in wood, allowing a good view\n"+
              "of the main room."
  });
  dest_dir= ({
    HROOM+"dojomain","north"
  });
}
init() {
  ::init();
  add_action("cmd_remind","remind");
  add_action("cmd_spin","spin");
}
cmd_remind(string str) {
  write("You try to remember, but can't bring it to mind.\n");
  return 1;
}
cmd_spin(string str) {
  int x,stop;
  if(!str || str != "dial") FAIL("Spin what?\n");
  write("You lift the reciever and give the dial a spin.\n");
  say(TPN+" lifts the reciever and gives the dial a spin.\n");
  stop=random(6)+2;
  for(x=0;x<=stop; x++)
    tell_room(this_object(),"* CLICK *\n");
  write("You hang the phone back up, satisfied.\n");
  say(TPN+" puts the reciever back, looking pleased.\n");
  return 1;
}
