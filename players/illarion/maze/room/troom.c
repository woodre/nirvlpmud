inherit "room/room";
#include "/players/illarion/dfns.h"
#define CONTROLLER "/players/illarion/maze/room/vroomcon.c"
#define MASTER "/players/illarion/maze/room/dmaster.c"


object controller;

void reset(status arg) {
  if(arg) return;

  set_light(1);
  short_desc="Undermountain Entrance";
  long_desc="This wide stone staircase leads down into the interior of the\n"
        +"plateau.  Below you'll find monsters, treasure, and danger.\n";
  dest_dir=({"/room/mount_top2","up","/room/church","down"});
}

void init() {
  if(!(controller=(mixed)MASTER->query_level(1))) {
    controller=clone_object(CONTROLLER);
    controller->create_floorplan(1);
    controller->set_theme("goblin");
    MASTER->register_level(controller,1);
  }
  ::init();
  add_action("cmd_enter","down");
  add_action("cmd_enter","d");
}

status cmd_enter(string str) {
  int *enter;
  enter=(mixed)controller->query_stairs_up();
  controller->move_me(TP,enter[0],enter[1],"into a hole","up",file_name(this_object()));
  return 1;
}