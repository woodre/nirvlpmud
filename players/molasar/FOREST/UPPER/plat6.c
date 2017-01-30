
#define COST1 300
#define COST2 20
#define COST3 20

#include "std.h"

reset(arg) {
   if(!arg)
     set_light(1);
}

object bolt, arrow, oint;
int money;
string me;

init() {
   add_action("buy","buy");
   add_action("northwest","northwest");
   add_action("southwest","southwest");
}

northwest() {
   this_player()->move_player("northwest#players/molasar/FOREST/UPPER/plat7");
   return 1;
}

southwest() {
   this_player()->move_player("southwest#players/molasar/FOREST/UPPER/plat5");
   return 1;
}

buy(str) {
   me = this_player()->query_name();
   money = this_player()->query_money();

   if(str == "ointment") {
     if(money < COST1) {
       write("You do not have enough money.\n");
       return 1;
     }
     oint = clone_object("players/molasar/OBJ/red_oint");
     move_object(oint, this_player());
     write("You pay "+COST1+" for a bottle of red ointment.\n");
     say(capitalize(me)+" buys a bottle of red ointment.\n");
     this_player()->add_money(-COST1);
     return 1;
   }
   if(str == "arrow") {
     if(money < COST2) {
       write("You do not have enough money.\n");
       return 1;
     }
     arrow = clone_object("players/molasar/WEAPONS/arrow");
     move_object(arrow, this_player());
     write("You pay "+COST2+" gold coins for an arrow.\n");
     say(capitalize(me)+" buys an arrow.\n");
     this_player()->add_money(-COST2);
     return 1;
   }
   if(str == "bolt") {
     if(money < COST3) {
       write("You do not have the money.\n");
       return 1;
     }
     bolt = clone_object("players/molasar/WEAPONS/bolt");
     move_object(bolt, this_player());
     write("You pay "+COST3+" gold coins for a crossbow bolt.\n");
     say(capitalize(me)+" buys a crossbow bolt.\n");
     this_player()->add_money(-COST3);
     return 1;
   }
}

short() { return "A elven shop"; }

long() {
   write("You have entered the local shop of the city.\n");
   write("There are various items for sale.\n");
   write("\n");
   write("<~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~>\n"+
         "<  Bottle of red ointment.........300 gp        >\n"+
         "<  An arrow........................20 gp        >\n"+
         "<  A Crossbow bolt.................20 gp        >\n"+
         "<_______________________________________________>\n");
   write("\n");
   write("   There are two obvious exits:  northwest and southwest\n");
}

