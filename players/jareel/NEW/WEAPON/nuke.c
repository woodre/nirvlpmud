inherit "obj/weapon";
#include <ansi.h>
#include "/players/jareel/define.h"
#include "/players/jareel/ansi.h"
#define CO call_other



reset(arg) {
  ::reset(arg);
     if(arg) return;
       set_class(20);
	   set_light(3);
       set_weight(1);
       set_value(4000);
       set_type("sword");
       set_alias("nuke");
       set_alt_name("blade of light");
       set_short(
	   
HIY+"NUKE"+NORM);
       
	   set_long(

	   HIY+"NUKE.\n"+NORM);

       set_hit_func(this_object());
}

query_wear() {
   return 1;
}

weapon_breaks() {
   return 1;
}

weapon_hit(attacker) {
   
   int wind;
 
  wind = random(2);
 
  if (wind==0){
      if(!attacker) return 1;
	  write("\n"+BOLD+BLINK+"   B O O M!\n "+NORM);
	  say(environment()->query_name()+" B O O M!"+NORM+"\n");
    attacker->hit_player(4000+random(500)+random(500)+random(500), "other|sami");
    return 1;
  }
}
 


