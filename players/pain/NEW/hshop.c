

#include "room.h"

#undef EXTRA_RESET
#define EXTRA_RESET keep_reset();

init(){

::init();
add_action("buy","buy");
}


ONE_EXIT( "players/pain/NEW/square", "east",
	  "The Bigelow Heal Shop",
	  "A brightly lit shop smelling of herbs and chemicals.\n"+
	  "A sign reads:\n\n"+
	  " =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=  \n"+
	  "\n"+
	  "  [1]     A standard heal [20]         1200 coins         \n"+
	  "  [2]     A standard heal [40]         2400 coins         \n"+
	  "  [3]     A standard heal [80]         4800 coins         \n"+
	  "  [4]     A standard heal [full]      10000 coins         \n"+
	  "\n"+
	  " =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= \n"+

	  "\n"+
	  " What would you like to buy?\n" , 1)
  buy(str){
   int strength,x,cost;
   object heal;
   string sht;

   if (!str){
	write("What would you like to buy?\n"+
	  "Syntax: buy < number >\n");
	   return 1;
	}
   if (sscanf(str,"%d", x) != 1) {
     write("Syntax: buy < number >\n");
     return 1;
   }
   switch(x){
   case 1:
    strength = 20;
    cost = 1200;
    sht = "A standard heal";
    break;
   case 2:
    strength = 40;
    cost = 2400;
    sht = "A standard heal";
    break;
   case 3:
    strength = 80;
    cost = 4800;
    sht = "A standard heal";
    break;
   case 4:
    strength = 350;
    cost = 10000;
    sht = "A standard heal";
    break;
     }
if((x>4)||(x<1)){
    write("You must select an item. (1-4)\n");
    return 1;
    }
    if(this_player()->query_money() < cost){
     write("You can't afford it.\n");
     return 1;
     }
/*
    if(!call_other(this_player(),"add_weight",1)){
      write("You can't carry that much.\n");
      return 1;
      }
*/
    call_other(this_player(),"add_money",-cost);
    heal = clone_object("/players/pain/NEW/heal/heal");
    heal->set_strength(strength);
    heal->set_short(sht);
    move_object(heal, this_player());
write("You bought "+sht+".\n");
    return 1;
    }
keep_reset() {
if(!present("keeper"))
move_object(clone_object("/players/pain/NEW/mon/skeeper"),this_object());
}
