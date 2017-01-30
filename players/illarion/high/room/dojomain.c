inherit "room/room";
#include "/players/illarion/dfns.h"

reset(arg) {
  object cor;
  if(cor=present("ill_imm_body",this_object())) {
    tell_room(this_object(),
      cor->short()+"suddenly begins to stir!\n"+
      "In less than a minute, the body heals and is whole and standing.\n");
    destruct(cor);
  }
  if(!present("Richie Ryan",this_object()))
    move_object(HMON+"richie",this_object());
  if(arg) return;

  set_light(1);
  short_desc="A modern martial arts dojo";
  long_desc=
"An odd mix of eastern and western surrounds you, all of it slightly old,\n"+
"but in good condition.  In one corner of the room a weight bench and a\n"+
"punching bag sit next to a rack that holds a number of wooden weapons and\n"+
"two full fencing suits.  In the center of the room is what looks like a\n"+
"gymnastics mat, but gives the feeling of something else.  The southern\n"+
"wall is almost entirely windows, with a door on one end, and an elevator\n"+
"on the other.  In the northwest corner of the room, a doorway leads to a\n"+
"hall, right next to a stairway leading up.\n";

  items= ({
    "bench","Just like what you'd find in any other weight room",
    "bag","It looks like it sees a lot of skillful use\n",
    "rack","A large wood assembly stacked with practice equipment from a\n"+
           "variety of sources.  Nearly hidden among all the mock items\n"+
           "is a single shining blade",
    "blade","A weapon of fine manufacture, throwing off capitivating glints\n"+
            "from the light in the room.  You wince slightly as one of them\n"+
            "catches you in the eye",
    "glint","Your eye seems drawn to the glint, and would "+BLD("gaze")+"\n"+
            "steadily at it if you let it",
    "weapons","Simply made items used to show the use of those made with\n"+
              "more of a deadly intent",
    "suits","White suits for practice duelling with foils",
    "mat","Although it looks like a normal mat, it somehow gives a feeling\n"+
          "of being more.  You can almost "+BLD("hear")+
          "the thud of thrown bodies",
    "windows","The windows give an office a view of the room",
    "door","A simple wooden door leading to an office",
    "elevator","A freight elevator with a metal gate for a door",
    "gate","The gate is closed, and on closer examination, padlocked",
    "doorway","A doorway with more windows around it, leading to the hall\n"+
              "leading to the main door",
    "hall","A wood-floored hall",
    "stairway","A wooden flight of stairs leading south and up",
  });
  dest_dir= ({
    HROOM+"hallw","north",
    HROOM+"office","south",
    HROOM+"loftent","up",
  });
}
init() {
  ::init();
  add_action("cmd_gaze","gaze");
}
cmd_gaze(string str) {
  if(!str || str != "at glint") FAIL("Gaze at what?\n");
  write("You stare at the glint until your eyes water, then turn away,\n"+
        "still not satisfied, but clueless.\n");
  say(TPN+" studies a blade on the weapon rack.\n");
  return 1;
}
