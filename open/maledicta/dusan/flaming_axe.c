#include "/players/maledicta/ansi.h"
#include "/players/maledicta/inherit/angel_inherit.c"
inherit "obj/weapon.c";

reset(arg){
  ::reset(arg);
  if (arg) return;
set_collect(random(500) + 1500);
set_name("battleaxe");
set_alt_name("collectable_obj_fire");
set_alias("firebrand");
set_short(""+BOLD+""+BLK+"Chu'Tath Battleaxe"+RED+" [Firebrand]"+NORM+"");
set_long(
  "This is the weapon favored by the Archangels of Fire. It's huge\n"+
  "blade seems to glow with an inner light, mimicking the power of\n"+
  "its late owner. It is tinted black as if from heat.\n");

set_type("axe");  
set_class(17);
set_weight(3);
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
  say(""+BOLD+""+BLK+""+user+"'s Battleaxe discharges a stream of"+RED+" Flame "+NORM+""+
  ""+BOLD+""+BLK+"which engulf's its victim!"+NORM+"\n");

  write(
  ""+BOLD+""+BLK+"Your Battleaxe discharges a stream of "+BOLD+""+RED+"FLAME"+NORM+""+
  ""+BOLD+""+BLK+" which engulf's your foe!"+NORM+"\n");
  return 7;
   }
if(W>9)  {
  say(""+BOLD+""+BLK+""+user+"'s Axe pulses with a bright"+RED+" Aura of Flame"+NORM+""+
  ""+BOLD+""+BLK+" as it strikes at its foe!"+NORM+"\n");

  write(
  ""+BOLD+""+BLK+"Your Axe pulses with a "+BOLD+""+RED+"Flaming Aura"+NORM+""+
  ""+BOLD+""+BLK+" as you strike your foe!"+NORM+"\n");
  return 3;
   }
return;
}
