#include "/players/forbin/define.h"
inherit "obj/weapon.c";

#define user environment(this_object())

id(str) { return (::id(str) || str == "collectable_bounty_object"); }

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("whip");
  set_alt_name("collectable_obj_ice");
  set_alias("shadows");
  set_short(HIM+"Whip "+HIK+"of "+NORM+MAG+"Shadows"+NORM);
  set_long(
    "  This weapon was once wielded by the Archangel of Shadows.  It is made\n"+
    "from some unknown material that seems extremely strong and very capable\n"+
    "when dealing damage. The handle is wrapped in a fine red leather, and a\n"+
    "small strap dangles from its hilt. The end is set with a large adamantium\n"+
    "barb, weighted perfectly for flaying flesh.\n"); 
  set_type("whip");
  set_class(18);
  set_weight(2);
  set_value(3000+random(3000));
  set_hit_func(this_object());
}

query_archangel_reward() { return 1; }

weapon_hit(attacker) {
 int chance;
  chance = random(100);
if(chance < 30){ 
 
write(
""+BOLD+""+BLK+"You lash out at "+attacker->query_name()+""+NORM+"\n"+             
""+HIR+"\n\n\n"+              
"                                 .             .         \n"+                            
"                               /             /          \n"+
"                      /      /      /      /         /\n"+
"                     /      /      /      /         /\n"+   
"                    /      /      /      /         /\n"+
"                         /             /\n"+
""+NORM+"\n"+
""+BOLD+""+BLK+"                                Flaying their flesh!"+NORM+"\n");                                                  
say(
""+BOLD+""+BLK+""+user->query_name()+" lashes out at "+attacker->query_name()+""+NORM+"\n");             
say(""+HIR+""+              
"                                 .             .         \n");                            
say("                               /             /          \n");
say("                      /      /      /      /         /\n");
say("                     /      /      /      /         /\n");   
say("                    /      /      /      /         /\n");
say("                         /             /            \n");
say("                       .             .             \n");
say(""+NORM+"\n");
say(""+BOLD+""+BLK+"                                Flaying their flesh!"+NORM+"\n");                                                  
 return 9;
 }
return;
}

/* Added so BF can't choose these as a coin cheat. Fred [08.06.06] */
query_nonchoose(){ return 1; }
