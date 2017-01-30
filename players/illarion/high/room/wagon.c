inherit "room/room";
#include "/players/illarion/dfns.h"

reset(arg) {
  if(arg) return;

  set_light(1);
  short_desc="On top of a hay wagon";
  long_desc=
"You are on top of a very copious pile of hay, and you can just make out\n"+
"the sides of a wagon at the bottom of a pile.  A disturbing distance\n"+
"upwards, you can make out a window and a narrow ledge.  As you judge\n"+
"the right way to roll off, you can already feel some hay getting into\n"+
"your clothing.\n";

  items= ({
    "hay","You know the kind that's for horses",
    "wagon","The hay is piled up on a large wagon",
    "window","A leaded window is open.  It looks to be a good way up",
    "ledge","Definately too narrow to stand on",
    "roll","The ground is an easy 'roll in the hay' away",
  });
  dest_dir= ({
    HROOM+"lbed","roll",
  });
}
void init() {
  ::init();
  add_action("cmd_roll","roll");
  write("Fortunately you land softly in a pile of hay.  Unforunately, it\n"+
        "is already working its way under your clothing.\n");
  transfer(clone_object(HOBJ+"hay"),TP);
}
cmd_roll() {
  write("As you roll off the wagon, you feel another pull in reality.\n");
  say(TPN+" starts to roll off the wagon.  As "+TP->query_pronoun()+"\n"+
      "reaches the edge of the wagon, a rift in reality snaps open.\n");
  TP->move_player("into a rift#"+HROOM+"lbed");
  return 1;
}
