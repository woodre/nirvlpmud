inherit "/obj/treasure.c";
#include "/players/zeus/closed/all.h"

int i;

reset(arg){

  set_id("shadow_dragon_spell");
  set_short(0);
  set_long(0);
  set_alias(0);
  set_weight(0);
  set_value(0);
  set_heart_beat(1);
  i = 0;
}


drop(){  return 0; }
prevent_insert(){ return 1; }

void heart_beat(){
   if(!environment()->is_player()){
           destruct(TO);
   }
   if(i > 6+random(10)){
	   tell_object(ENV, RED+
	   "The shadowy flames disappear from around your body.\n"+NORM);
	   destruct(TO);
   }
   else if(ENV->query_hp() > 300){
	   tell_object(ENV, RED+
		   "Shadowy flames rise up around you!\n"+NORM);
	   ENV->hit_player(30+random(35));
   }
   else if(ENV->query_hp() > 200 && !random(3)){
	   tell_object(ENV, RED+
"You writhe in agony as the flames burn your body!\n"+NORM);
		ENV->hit_player(25+random(25));
   }
   else if(ENV->query_hp() > 200 && !random(3)){
	   tell_object(ENV, RED+
		   "The shadowy flames drain your energy!\n"+NORM);
	   ENV->add_spell_point(-25-random(40));
   }
   else if(!random(3)){
	   tell_object(ENV, RED+
	"Shadowy flames dance across your body!\n"+NORM);
	   ENV->hit_player(5+random(30));
   }
   i++;
}
