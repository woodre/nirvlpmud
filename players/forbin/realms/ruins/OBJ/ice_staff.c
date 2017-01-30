#include "/players/forbin/define.h"
inherit "obj/weapon.c";

id(str) { return (::id(str) || str == "collectable_bounty_object"); }

reset(arg){
  ::reset(arg);
  if(arg) return;
  set_name("staff");
  set_alt_name("collectable_obj_ice");
  set_alias("icebrand");
  set_short(HIK+"Chu'Sarth Staff"+HIW+" ["+HIC+"Icebrand"+HIW+"]"+NORM);
  set_long(
    "  Looking at this powerful weapon you see a spectre of what the\n"+
    "owner must have been like. Cold, deadly, and evil. The weapon\n"+
    "is covered with a light frost which never seems to diminish,\n"+
    "even at the touch of warmth.\n");
  set_type("staff");  
  set_class(15);
  set_weight(1);
  set_value(3000+random(1000));
  set_hit_func(this_object());
}

init() {
  int cobj;
  ::init();
  if(cobj = present("collectable_obj_fire")) {
   	tell_room(environment(environment()),
      format("The "+(string)this_object()->short()+
 	    " shatters as it comes too close to a weapon of flame!\n"));
 	  move_object(this_object(), "/room/void");
    destruct(this_object());
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
  say("\t\t"+BOLD+""+BLK+""+user+"'s Staff spins wickedly summoning a\n\n"+
      ""+HIC+"                                        CYCLONE OF FROST "+NORM+"\n\n"+
      "\t"+BOLD+""+BLK+"which engulf's its victim with tendrils of pure pain!"+NORM+"\n");

  write(
  "\t\t"+BOLD+""+BLK+"Your Staff spins wickedly summoning a"+NORM+"\n\n"+
  ""+HIC+"                        CYCLONE OF FROST"+NORM+"\n\n"+
  "\t"+BOLD+""+BLK+" which engulf's your foe with tendrils of pure pain!"+NORM+"\n");
  return 7;
   }
if(W>9)  {
  say(""+BOLD+""+BLK+""+user+"'s Staff drives into it's victim slamming them with"+
  " shards of "+HIC+"ICE!"+NORM+"\n");

  write(
  ""+BOLD+""+BLK+"Your Staff drives into your foe sending shards of"+HIC+" ICE"+NORM+""+
  ""+BOLD+""+BLK+" digging into their flesh!"+NORM+"\n");
  return 3;
   }
return;
}
