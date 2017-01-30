/* Cures Poison */

#include "/players/maledicta/ansi.h"

#define USER this_player()

id(str){ return str == "potion"; }
short() { return "Potion of "+HIG+"Curing"+NORM; }  
long(){
   write(
"This small potion contains a green liquid that will\n"+
"cure you of toxins in your body. To use this potion\n"+
"'drink potion of curing'.\n"); 
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
object poison, next;
string a,b;

if(str == "potion of curing"){
if(environment(this_object()) != this_player()) return 0;
  
   poison = first_inventory(USER);
   while (poison) {
      next = next_inventory(poison);
      if (sscanf(file_name(poison),"%spoison%s",a,b) == 2 ||
            poison->id("poison")) {
         destruct(poison);
         }
      poison = next;
      }
 
	write(
	"You drink the potion quickly and feel a soothing relief as toxins in\n"+
      "your body dissipate...\n");
      tell_room(environment(USER),
      USER->query_name()+" drinks a potion.\n", ({ USER }));
	this_object()->set_weight(0);
	call_other(this_player(), "recalc_carry");
        destruct(this_object());
      return 1;
      }	
return;
}


get(){ return 1; }
query_weight(){ return 1; }	
