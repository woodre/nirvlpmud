inherit "room/room";
#include "/players/illarion/dfns.h"

reset(arg) {
  if(arg) return;

  set_light(1);
  short_desc="The back entrance to the dojo";
  long_desc=
"You stand in a tiny alcove at the northeastern end of a loft apartment.\n"+
"There is really nothing here except a set of stairs leading down, lit by\n"+
"a single bare bulb, and a metal railing following the stairs.\n";
  items= ({
    "alcove","Almost claustrophobic..",
    "apartment","For a loft, it looks very nice",
    "stairs","Wooden, and solid, but narrow and not very inviting",
    "railing","Metal, cold, and dented in a few places",
    "bulb","An old incandescent bulb, with some affliction that makes it\n"+
           "flicker occasionally",
  });
  dest_dir= ({
    HROOM+"lbed","north",
    HROOM+"bank","down",
  });
}
init() {
  ::init();
  add_action("down","down");
}
down() {
  write("As you walk down the stairs, the air waves in front of you in\n"+
        "a strage wave-like pattern.  The wooden stairs and\n"+
        "building dissolve away.\n");
  say("As "+TPN+" walks down the stairs, "+TP->query_pronoun()+
      " seems to waver and vanish.\n");
  return 0;
}
