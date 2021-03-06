#include "/players/maledicta/ansi.h"
#include "/players/maledicta/inherit/angel_inherit.c"
inherit "obj/weapon.c";

reset(arg){
  ::reset(arg);
  if (arg) return;
set_collect(random(500) + 1500);
set_name("spear");
set_alt_name("collectable_obj_fire");
set_alias("firebrand");
set_short(""+BOLD+""+BLK+"Chu'Tath Spear"+RED+" [Firebrand]"+NORM+"");
set_long(
  "This is the weapon favored by the Archangels of Fire. It's \n"+
  "steel tip head seems to glow with an inner light, mimicking the\n"+
  "power of its late owner. It is tinted black as if from heat.\n");

set_type("spear");  
set_class(16);
set_weight(2);
set_value(200);
set_hit_func(this_object());
}

   init(){
    ::init();
    if(present("collectable_obj")){
    	write("The weapon of ice shatters as it comes too close to a weapon of flame!\n");
    	destruct(present("collectable_obj"));
    	return 1;
    	}
add_action("collect_reward", "collect");
     }



weapon_hit(attacker){
int W;
object user;
user = environment(this_object())->query_name();
W = random(19);

if(W>16)  {
  say(""+BOLD+""+BLK+""+user+"'s Spear discharges a stream of"+RED+" Flame "+NORM+""+
  ""+BOLD+""+BLK+"which engulf's its victim!"+NORM+"\n");

  write(
  ""+BOLD+""+BLK+"Your Spear discharges a stream of "+BOLD+""+RED+"FLAME"+NORM+""+
  ""+BOLD+""+BLK+" which engulf's your foe!"+NORM+"\n");
  return 7;
   }
if(W>9)  {
  say(""+BOLD+""+BLK+""+user+"'s Spear pulses with a bright"+RED+" Aura of Flame"+NORM+""+
  ""+BOLD+""+BLK+" as it pierce's its foe!"+NORM+"\n");

  write(
  ""+BOLD+""+BLK+"Your Spear pulses with a "+BOLD+""+RED+"Flaming Aura"+NORM+""+
  ""+BOLD+""+BLK+" as you pierce your foe!"+NORM+"\n");
  return 3;
   }
return;
}
