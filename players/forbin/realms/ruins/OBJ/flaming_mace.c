#include "/players/forbin/define.h"
inherit "obj/weapon.c";

id(str) { return (::id(str) || str == "collectable_bounty_object"); }

reset(arg){
  ::reset(arg);
  if(arg) return;
  set_name("mace");
  set_alt_name("collectable_obj_fire");
  set_alias("firebrand");
  set_short(HIK+"Chu'Tath Mace"+HIW+" ["+HIR+"Firebrand"+HIW+"]"+NORM);
  set_long(
    "This is the weapon favored by the Archangels of Fire. It's \n"+
    "steel head seems to glow with an inner light, mimicking the\n"+
    "power of its late owner. It is tinted black as if from heat.\n");
  set_type("mace");  
  set_class(15);
  set_weight(1);
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
  say(""+BOLD+""+BLK+""+user+"'s Mace discharges a stream of"+RED+" Flame "+NORM+""+
  ""+BOLD+""+BLK+"which engulf's its victim!"+NORM+"\n");

  write(
  ""+BOLD+""+BLK+"Your Mace discharges a stream of "+BOLD+""+RED+"FLAME"+NORM+""+
  ""+BOLD+""+BLK+" which engulf's your foe!"+NORM+"\n");
  return 7;
   }
if(W>9)  {
  say(""+BOLD+""+BLK+""+user+"'s Mace pulses with a bright"+RED+" Aura of Flame"+NORM+""+
  ""+BOLD+""+BLK+" as it slam's into its foe!"+NORM+"\n");

  write(
  ""+BOLD+""+BLK+"Your Mace pulses with a "+BOLD+""+RED+"Flaming Aura"+NORM+""+
  ""+BOLD+""+BLK+" as you slam your foe!"+NORM+"\n");
  return 3;
   }
return;
}
