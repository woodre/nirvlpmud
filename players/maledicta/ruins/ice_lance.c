#include "/players/maledicta/ansi.h"
#include "/players/maledicta/inherit/angel_inherit.c"
inherit "players/maledicta/weapon.c";

reset(arg){
  ::reset(arg);
  if (arg) return;
set_collect(random(500) + 1500);
set_name("lance");
set_alt_name("collectable_obj");
set_alias("icebrand");
set_short(""+BOLD+""+BLK+"Chu'Sarth Footman's Lance"+HIB+" [Icebrand]"+NORM+"");
set_long(
  "  Looking at this long powerful weapon you see a spectre of\n"+
  "what the owner must have been like. Cold, deadly, and evil.\n"+
  "The weapon is covered with a light frost which never seems\n"+
  "to diminish, even at the touch of warmth.\n");
set_two_handed_wep(1);
set_no_break(1);
set_type("spear");
add_special_chance(50);
add_special_chance(50);
add_special_chance(50);
add_special_damage(10);
add_special_damage(10);
add_special_damage(10);
add_special_message("1 works $H$$R$ $AN$ $APO$ $APR$ $UPO$ $UPR$ $UOB$ $UN$ $N$!\n");  
add_special_message("2 works!\n");
add_special_message("3 works!\n");
add_special_rmessage("1 works!\n");  
add_special_rmessage("2 works!\n");
add_special_rmessage("3 works!\n");

set_class(17);
set_weight(6);
set_value(200);
set_hit_func(this_object());
}

init(){
    ::init();
    if(present("collectable_obj_fire")){
    	write("The Lance Shatters as it comes too close to a weapon of flame!\n");
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
  say("\t"+BOLD+""+BLK+""+user+" holds the Lance before"+
      " "+this_player()->query_objective()+" summoning forth a\n\n"+
      ""+HIB+"                                        CYCLONE OF FROST "+NORM+"\n\n"+
      "\t\t"+BOLD+""+BLK+"which engulf's its victim with tendrils of pure pain!"+NORM+"\n");

  write(
  "\t"+BOLD+""+BLK+"Holding the Lance before you, you summon forth a"+NORM+"\n\n"+
  ""+HIB+"                        CYCLONE OF FROST"+NORM+"\n\n"+
  "\t\t"+BOLD+""+BLK+" which engulf's your foe with tendrils of pure pain!"+NORM+"\n");
  return 7;
   }
if(W>9)  {
  say(""+BOLD+""+BLK+""+user+"'s Lance drives into it's victim slamming them with"+
  " shards of "+HIB+"ICE!"+NORM+"\n");

  write(
  ""+BOLD+""+BLK+"Your Lance drives into your foe sending shards of"+HIB+" ICE"+NORM+""+
  ""+BOLD+""+BLK+" digging into their flesh!"+NORM+"\n");
  return 4;
   }
return;
}
