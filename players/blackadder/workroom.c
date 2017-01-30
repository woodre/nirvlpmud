#include "std.h"
object beer;
int shield, notin;
init() {
   add_action("on"); add_verb("on");
   add_action("off"); add_verb("off");
   add_action("out"); add_verb("out");
   add_action("buy"); add_verb("buy");
   add_action("buy"); add_verb("order");
   add_action("west"); add_verb("west");
   add_action("search"); add_verb("search");
   set_light( 1);
   if(this_player()->query_real_name() !="blackadder" && shield ==1) {
      write("You feel an electric shock and see a flash of green light as\n");
      write("you rebound off the defense shield.\n");
      if (notin == 1) {
         write("Blackadder is out right now, please leave a\n");
         write("message at the post office.\n");
      }
      this_player()->move_player("off the shields#/players/blackadder/entrance");
   }
}
reset(arg) {
   if (arg) return;
   move_object(clone_object("/players/blackadder/bboard/board"),this_object());
}
static on() {
   shield = 1;
   write("shields activated.\n");
   return 1;
}
static off() {
   if (call_other(this_player(),"query_real_name",0) != "blackadder") {
      write("You are not allowed to do that!!!!!!!\n");
      return 1;
   }
   shield = 0;
   notin = 0;
   write("shields deacivated.\n");
   return 1;
}
out() {
   shield = 1;
   notin = 1;
   write("shields on, out message on.\n");
   return 1;
}
west() {
   call_other(this_player(),"move_player","west#/players/blackadder/entrance");
   return 1;
}
short() {
   return "Blackadder's workroom";
}
long() {
   write(""+
      "This is Blackadder's workroom, the floor is covered with\n"+
      "empty beer cans and bottles.\n");
   write("A beer vending machine is set into the far wall.\n");
   write("Beers cost 20 coins.  Type 'Buy beer' to purchase one.\n");
   write("You may also purchase buckets of long island ice teas for 225 coins.\n");
   write("Type 'Buy bucket' to purchase one. (highly recommended)\n");
   write("     You may exit to the west.\n");
}

buy(str) {
   if (!str) {
      write("Buy what?\n");
      return 1;
   }
   if (str != "beer" && str != "bucket") {
      write("Did you want a beer or something?\n");
      return 1;
   }
   if (str == "beer") {
      if (call_other(this_player(),"query_money",0) < 20) {
         write("You can't afford a beer!\n");
         return 1;
       }
      beer = clone_object("/obj/beer");
      if (!call_other(this_player(),"add_weight",
               call_other(beer,"query_weight"))) {
         write("You can't carry that much!\n");
         return 1;
       }
      move_object(beer,this_player());
      call_other(this_player(),"add_money", -20);
      write("Ok.\n");
      return 1;
   }
   if (call_other(this_player(),"query_money",0) < 225) {
      write("You can't afford a bucket!\n");
      return 1;
   }
   beer = clone_object("/players/blackadder/bucket");
   if (!call_other(this_player(),"add_weight",
            call_other(beer,"query_weight"))) {
      write("You can't carry that much!\n");
      return 1;
   }
   move_object(beer,this_player());
   call_other(this_player(),"add_money", -225);
   write("Ok.\n");
   return 1;
}

search(str) {
   if (str == "corpse")
      return 0;
   write("You find nothing special.\n");
   return 1;
}
