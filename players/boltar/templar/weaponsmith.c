#include "std.h"
init() {
if(set_light(0)==0)
    set_light(1);
   add_action("fix","fix");
   add_action("south","south");
 }
short() { return "The weapon smith's shop";
   }
long() {
   write("You are in the weapon smith's shop. Here you can have your"+
    "\nweapons fixed for the low, low price of 500 coins.\n"+
     "Just use 'fix <weapon name>' and your weapon will be repaired.\n");
    write("Please make sure your weapon is unwielded,or the repair may not have full effect\n");
    write("The only exit is to the south.\n");
   }
south() {
    call_other(this_player(), "move_player", "south#players/boltar/templar/armory.c");
    return 1;
  }
fix(str) {
int cost;
object ob;
   if (!str) return 0;
    ob=present(str,this_player());
      if(!ob) ob = present(str,this_object());
      if(!ob) {
     write("That is not here.\n");
    return 1;
     }
   if(!ob->fix_weapon()) {
     write("It is not broken.\n");
     return 1;
    }
    cost = ob->query_value()/5;
   cost = 500;
    if (this_player()->query_money() < cost) {
        ob->re_break();
        write("You do not have enough money.\n");
        return 1;
        }
    this_player()->add_money(-500);
    write("The weapon smith fixes your "+str+" and it costs you "+cost+" coins\n");
return 1;
     }
