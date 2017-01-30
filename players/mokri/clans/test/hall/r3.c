inherit "/players/vertebraker/closed/std/room.c";
#include "../../defs.h"
#include "../../room_funcs.h"
#define DRONE_COST 1000

reset(arg) {
   if(arg) return;
   set_light(1);
   set_short("Clan Hall - drone room");
   set_long("You can 'purchase_drone' here. Cost is " + DRONE_COST + " coins.\nDrones can carry one item from you inventory back to this room.\n");
   add_property("NT");
   restore_me();
}

init()
{
   ::init();
   check_valid_entry();
   add_action("purchase_drone","purchase_drone");
}

int purchase_drone() {
   int weight;
   object drone;
   
   if(TP->query_money() < DRONE_COST) {
      write("You do not have enough coins to purchase a drone.\n");
      return 1;
   }
   
   weight = (int)call_other(TOP_DIR + "obj/drone", "query_weight");
   
   if(!TP->add_weight(weight)) {
      write("You cannot carry a drone.\n");
      return 1; }
   
   TP->add_money(-DRONE_COST);
   drone = clone_object(TOP_DIR + "obj/drone");
   move_object(drone,TP);
   drone->set_where(environment(TP));
   write("You purchase a drone.\n");
   
   return 1;
   
}
query_cost() { return 1000000; }
