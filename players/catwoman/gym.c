#include "std.h"
init() {
if(set_light(0)==0)
    set_light(1);
   add_action("join","join");
   add_action("west","west");
 }
short() { return "Groc's Gym"; }
long() {
 write("You have entered a run-down looking brick building.  You see before\n"+
        "you a large open area with all sorts of equipment. On the wall you\n"+
       "notice a sign that reads Groc's physical training gym, Turn yourself"+
      "\ninto a lean, mean fighting machine for only 25 coins an hour. Just join!\n"+
       "Throughout this wide open space is the lastest in physical fittness\n"+
       "equipment.\n");
   write("The only exit is west.\n");
   }
west() {
    call_other(this_player(), "move_player", "west#room/southroad2.c");
    return 1;
  }
join() {
object ob;
int kc,x;
    if(this_player()->query_pregnancy()) {
      write("You shouldn't strain yourself in your condition.\n");
      return 1;
     }
    if (this_player()->query_money() < 25) {
        ob->re_break();
        write("You do not have enough money.\n");
        return 1;
        }
    this_player()->add_money(-25);
    write("You workout for an the entire hour, you feel tired but feel better.\n");
    if(this_player()->query_phys_at(3) > 115) {
       x = call_other("/players/boltar/sprooms/daycare","count_total_kids",this_player()->query_name());
      kc = random(12) - x;
      if(kc < 0) kc = random(3);
    this_player()->add_phys_at(3, -kc);
     }
return 1;
     }
