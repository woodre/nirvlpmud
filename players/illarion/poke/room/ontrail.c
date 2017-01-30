inherit "players/illarion/room";
#include "/players/illarion/dfns.h"

void reset(status arg){
  if(arg) return;
  
  set_light(1);
  set_short("The bottom of a steep trail");
  set_long(
"A long, sloped earthen trail comes to an end here outside a small wooden "+
"building.  Lining the trail is a thick copse of trees, although the trail "+
"is strangely clear of roots and other impediments.");
   add_item("building","This simple wooden building exudes a feeling of "
                      +"safety and welcome.  A small sign is mounted "
                      +"above the door.");
   add_item("sign","The sign reads: Pokemon rest area.");
   add_item("trail","The earthen trail slopes upward through the trees "
                   +"and quickly disappears from sight.  You could "
                   +BLD("climb")+" it away from the building if you wished.");
   add_item("trees","Green-leaved trees with tall, graceful trunks, and "
                   +"growing too close to the side of the trail to "
                   +"afford a way to leave it.");
   add_exit("enter",PROOM+"restarea");
  add_exit("west","/players/illarion/guild/room/clearing");
}
void init() {
  ::init();
  add_action("cmd_climb","ascend");
  add_action("cmd_climb","climb");
  add_action("west_check","west");
}
int cmd_climb(string str) {
  if(str != "trail") return 0;
  write("You climb the trail back up to the plateau.\n");
  this_player()->move_player("up the trail#room/mount_top2");
  return 1;
}
status west_check() {
  if(!TP || (int)TP->query_level()<21) {
    write("This area is not yet open to players.\n");
    return 1;
  }
}
