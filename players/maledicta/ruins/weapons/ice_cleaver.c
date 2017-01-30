#include "/players/maledicta/ansi.h"
#include "/players/maledicta/inherit/angel_inherit.c"
inherit "obj/weapon.c";

reset(arg){
  ::reset(arg);
  if (arg) return;
set_collect(random(500) + 1500);
set_name("cleaver");
set_alt_name("collectable_obj");
set_alias("icebrand");
set_short(""+BOLD+""+BLK+"Chu'Sarth Cleaver"+HIB+" [Icebrand]"+NORM+"");
set_long(
  "  Looking at this cruel weapon you see a spectre of what the\n"+
  "owner must have been like. Cold, deadly, and evil. The weapon\n"+
  "is covered with a light frost which never seems to diminish,\n"+
  "even at the touch of warmth.\n");

set_type("dagger");  
set_class(16);
set_weight(1);
set_value(200);
set_hit_func(this_object());
}

init(){
    ::init();
    if(present("collectable_obj_fire")){
    	write("The Cleaver Shatters as it comes too close to a weapon of flame!\n");
    	destruct(this_object());
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
  say("\t"+BOLD+""+BLK+""+user+" holds the cleaver before"+
      " "+this_player()->query_objective()+" summoning forth a\n\n"+
      ""+HIB+"                             CYCLONE OF FROST "+NORM+"\n\n"+
      "\t\t"+BOLD+""+BLK+"which engulf's its victim with tendrils of pure pain!"+NORM+"\n");

  write(
  "\t"+BOLD+""+BLK+"Holding the cleaver before you, you summon forth a"+NORM+"\n\n"+
  ""+HIB+"                        CYCLONE OF FROST"+NORM+"\n\n"+
  "\t\t"+BOLD+""+BLK+" which engulf's your foe with tendrils of pure pain!"+NORM+"\n");
  return 7;
   }
if(W>9)  {
  say(""+BOLD+""+BLK+""+user+"'s Cleaver drives into it's victim slamming them with"+
  " shards of "+HIB+"ICE!"+NORM+"\n");

  write(
  ""+BOLD+""+BLK+"Your Cleaver drives into your foe sending shards of"+HIB+" ICE"+NORM+""+
  ""+BOLD+""+BLK+" digging into their flesh!"+NORM+"\n");
  return 3;
   }
return;
}
