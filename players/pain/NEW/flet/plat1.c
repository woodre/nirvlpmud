

#include "room.h"
#include "/players/pain/color.h"
#undef EXTRA_RESET
#define EXTRA_RESET keep_reset();

init(){

::init();
add_action("buy","buy");
}


ONE_EXIT( "players/pain/NEW/flet/flet4", "west",
	  "The "+BOLD+GREEN+"Elven Flet"+END+" Fruit Stand.",
	  "A Fruit Stand carved into one of the Mallorn trees that forms\n"+
	  "the "+BOLD+GREEN+"Elven Flet"+END+". Shelves and bins hold all sorts of delicious\n"+
	  "fruits available for purchase.\n"+
	  "A sign reads:\n\n"+
	  " =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=  \n"+
	  "\n"+
	  "  [1]     A dark plum     [20]          800 coins         \n"+
	  "  [2]     A juicy peach   [40]         1600 coins         \n"+
	  "  [3]     A ripe melon    [80]         3200 coins         \n"+
	  "  [4]     A watermelon    [full]      10000 coins         \n"+
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
    cost = 800;
    sht = "A dark plum";
    break;
   case 2:
    strength = 40;
    cost = 1600;
    sht = "A juicy peach";
    break;
   case 3:
    strength = 80;
    cost = 3200;
    sht = "A ripe melon";
    break;
   case 4:
    strength = 350;
    cost = 10000;
    sht = "A watermelon";
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
    heal = clone_object("/players/pain/NEW/flet/Heal/heal");
    heal->set_strength(strength);
    heal->set_short(sht);
    move_object(heal, this_player());
write("You bought "+sht+".\n");
    return 1;
    }
keep_reset() {
if(!present("keeper"))
move_object(clone_object("/players/pain/NEW/flet/Mon/skeeper"),this_object());
}
