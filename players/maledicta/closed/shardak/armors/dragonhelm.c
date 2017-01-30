/*  
Made from 2 red dragon scales + any ac 2 helm.
*/
#define USER environment()
#include "/players/maledicta/ansi.h"
inherit "obj/armor";

reset(arg){
set_alias("helm");
set_name("dragonhelm");
set_short(RED+"D"+HIW+"ragon"+NORM+RED+"H"+HIW+"elm"+NORM);
set_long(
  "This red-mithril helm is shaped into the form of a\n"+
  "dragon's head.  Its snarling visage and deep inset\n"+
  "eye holes are fearsome to behold.  Only the most\n"+
  "brave of warriors can look upon it without a shudder.\n");
set_ac(2);
set_type("helmet");
set_params("other|fire", 1, 5, "fire_special");
set_weight(1);
set_value(1000);
}

fire_special(){
if(!random(20))
tell_object(USER, "Your helm protects you from the fires damage!\n");
return 0;
}
	
