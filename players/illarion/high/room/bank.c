inherit "players/illarion/room";
#include "/players/illarion/dfns.h"

void reset(int arg) {
  if(arg) return;

  set_light(1);
  set_short("Along the Seine");
  set_long("\
A broad stone courtyard stretches out between the eastern bank of a river on one \
side and a retaining wall on the other.  Along the edge of the bank, \
several metal posts provide the tie-ups for the large black barge that \
floats just off the bank, to the west.  A few iron rings are set along the retaining \
wall at regular intervals, except where a staircase along the wall leads up.");

  add_item("courtyard","A sort of platform beside the river, oddly picturesque "
                      +"despite its lack of decoration.");
  add_item("bank","The side of a river.  This one is made entirely of stone.");
  add_item("river","The water looks deep, and reflects the opposite bank "
                  +"nicely, but it looks slightly polluted.");
  add_item("posts","The metal posts have ropes from the barge wrapped around "
                  +"them and tied off securely.");
  add_item("barge","A large black barge, with a few portholes in the side, but "
                  +"otherwise enigmatic.");
  add_item("rings","The rings are large, and slightly rusted.");
  add_item("staircase","Broad stone steps leading up to the top of the "
                      +"retaining wall.");

  add_exit("up",HROOM+"alcove");
  add_exit("west",HROOM+"bargetop");
}
void init() {
  ::init();
  add_action("cmd_up","up");
}
int cmd_up() {
  write("As you walk up the stairs, they seem to dissolve before your eyes.\n");
  say(TPN+" starts to walk up the stairs, shimmers, and vanishes.");
  return 0;
}
