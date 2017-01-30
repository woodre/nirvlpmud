/* Gives a view of a players room. Randomly chooses the player. */



#include "/players/jaraxle/ansi.h"



#define USER this_player()



id(str){ return str == "potion"; }

short() { return "Potion of "+HIM+"Vision"+NORM; }  

long(){

   write(

" This potion holds a purplish liquid that seems to\n"+

"bubble and swirl as you watch it. It has been known\n"+

"to give you visions of far away places and people.\n"+

"All you need to do is 'drink potion of vision' to use\n"+

"it.\n");

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

object *ppl;

object *ppl2;

int booya;

int i;

if(str == "potion of vision"){

if(environment(this_object()) != this_player()) return 0;

  

  ppl = users();

  for(i = 0; i < sizeof(ppl); i++){

   if(environment(ppl[i]) && ppl[i]->query_level() < 20){

      if(!ppl2) ppl2 = ({ ppl[i] });

      else ppl2 += ({ ppl[i] });

      }

   }

booya = random(sizeof(ppl2));

tell_object(USER, "As you drink the potion you receive a vision.\n\n");

   tell_object(USER,
BLK+BOLD+"["+HIM+ppl2[booya]->query_name()+NORM+" is located at"+BLK+BOLD+"]\n"+NORM);
    tell_object(USER,
environment(ppl2[booya])->long()+"\n\n");
tell_object(USER, "The vision fades...\n");  

 

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

