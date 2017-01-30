inherit "room/room";
#include "/players/illarion/dfns.h"
#define CONTROLLER "/players/illarion/maze/room/vroomcon.c"
#define MASTER "/players/illarion/maze/room/dmaster.c"

object up_controller;
object down_controller;
int *up_loc;
int *down_loc;

reset(arg) {
  if(arg) return;
  
  set_light(1);
  short_desc="A small room";
  long_desc="You are standing on a twisting flight of stairs.  Down\n"+
            "will take you deeper into the dungeon, for more danger\n"+
            "and more reward.  Up will take you to a safer but less\n"+
            "rewarding level.\n";
  dest_dir=({"/room/church","up","/room/church","down"});
}

void init() {
  ::init();
  add_action("cmd_up","up");
  add_action("cmd_down","down");
}

set_up_controller(ob) {
  up_controller=ob;
  up_loc=ob->query_stairs_down();
/* We don't want this room to get cleaned, so put it inside the controller
   for the floor "above" it */
  move_object(this_object(),up_controller);
  if(!(down_controller=MASTER->query_level(up_controller->query_level_number()+1))) {
    down_controller=clone_object(CONTROLLER);
    MASTER->register_level(down_controller,up_controller->query_level_number()+1);
    down_controller->create_floorplan(up_controller->query_level_number()+1);
    down_loc=down_controller->query_stairs_up();
  }
  up_controller->set_next_level(down_controller);
}

cmd_up() {
  if(!up_controller) {
    write("Illarion broke something.  Moving you to the green.\n"+
          "Please notify him and stay out of the maze.\n");
    TP->move_player("green#/room/vill_green");
    return 1;
  }
  up_controller->move_me(TP,up_loc[0],up_loc[1],"up the stairs","down",file_name(this_object()));
  return 1;
}

cmd_down() {
  if(!down_controller) {
    write("Illarion broke something.  Moving you to the green.\n"+
          "Please notify him and stay out of the maze.\n");
    TP->move_player("green#/room/vill_green");
    return 1;
  }

  down_controller->move_me(TP,down_loc[0],down_loc[1],"down the stairs","up",file_name(this_object()));
  return 1;
}
