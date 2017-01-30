#include "/players/forbin/define.h"
inherit "obj/weapon.c";

id(str) { return (::id(str) || str == "collectable_bounty_object"); }

reset(arg){
  ::reset(arg);
  if(arg) return;
  set_name("battleaxe");
  set_alt_name("collectable_obj_fire");
  set_alias("firebrand");
  set_short(HIK+"Chu'Tath Battleaxe"+HIW+" ["+HIR+"Firebrand"+HIW+"]"+NORM);
  set_long(
    "This is the weapon favored by the Archangels of Fire. It's huge\n"+
    "blade seems to glow with an inner light, mimicking the power of\n"+
    "its late owner. It is tinted black as if from heat.\n");
  set_type("axe");  
  set_class(17);
  set_weight(2);
  set_value(3000+random(1000));
  set_hit_func(this_object());
}

init() {
  int cobj;
  ::init();
  if(cobj = present("collectable_obj_ice")) {
   	tell_room(environment(environment()),
      format("The "+(string)cobj->short()+
 	    " shatters as it comes too close to a weapon of flame!\n"));
 	  move_object(cobj, "/room/void");
    destruct(cobj);
    return 1;
  }
}

query_archangel_reward() { return 1; }

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
