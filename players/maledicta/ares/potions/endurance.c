/* Gives a view of a players room. Randomly chooses the player. */

#include "/players/maledicta/ansi.h"

#define USER this_player()

id(str){ return str == "potion"; }
short() { return "Potion of "+HIB+"Endurance"+NORM; }  
long(){
   write(
"  This magical potion holds a blue liquid that will\n"+
"completely refresh you as you travel across the great\n"+
"continent. You need to 'drink potion of endurance' to\n"+
"use it.\n");
 }

query_value(){ return 200; }
query_save_flag(){ return 1; }

reset(arg){
  if(arg) return;
  }
  
init(){
   add_action("use_kit", "drink");
   }
   
use_kit(str){
if(str == "potion of endurance"){
if(environment(this_object()) != this_player()) return 0;
if(present("endurance_object", USER)){
   present("endurance_object", USER)->reset_endurance();
   }
      tell_object(USER,
      "You drink the potion and feel refreshed!\n");
	tell_room(environment(USER),
      USER->query_name()+" drinks a potion and looks refreshed.\n", ({ USER }));
	this_object()->set_weight(0);
	call_other(this_player(), "recalc_carry");
        destruct(this_object());
      return 1;
      }	
return;
}


get(){ return 1; }
query_weight(){ return 1; }	
