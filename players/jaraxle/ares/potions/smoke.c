/* Smoke bomb. Makes the room -10 light for 5-9 hbs */



#include "/players/jaraxle/ansi.h"



#define USER this_player()



id(str){ return str == "potion"; }

short() { return "Potion of "+BOLD+"Smoke"+NORM; }  

long(){

   write(

"  This small vial holds a smokey substance that is constantly\n"+

"churning about. You can 'toss' it to the ground to break the\n"+

"glass and release the smoke into the room.\n"); 

 }



query_value(){ return 200; }

query_save_flag(){ return 1; }



reset(arg){

  if(arg) return;

  }

  

init(){

   add_action("use_kit", "toss");

   }

   

use_kit(str){

string blah;

if(str == "potion" || str == "vial"){

if(environment(this_object()) != this_player()) return 0;

if(environment(USER)->realm() == "NM"){

  write("You cannot throw the potion down here.\n");

  return 1; 

  }

if(sscanf(file_name(environment(USER)), "room/%s", blah) == 1){

  write("You cannot toss it down here! Shame on you for trying. =(\n");

  return 1; 

  }

  move_object(clone_object("/players/jaraxle/ares/potions/smoke_obj.c"), environment(USER));

	write(

	"You toss the potion to the ground and watch as it cracks...\n"+

      "A thick smoke fills the room!\n");

      tell_room(environment(USER),

      USER->query_name()+" throws a vial to the ground!\n");

	this_object()->set_weight(0);

	call_other(this_player(), "recalc_carry");

        destruct(this_object());

      return 1;

      }	

return;

}





get(){ return 1; }

query_weight(){ return 1; }	

