#include "/players/maledicta/ansi.h"
#include "/players/maledicta/inherit/angel_inherit.c"
inherit "players/maledicta/weapon/weapon2.c";

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

set_type("spear");  
set_class(17);
set_weight(6);
set_value(200);
add_special_chance(10);
add_special_chance(30);
add_special_message(
  "\t$H$K$Holding the Lance before you, you summon forth a$N$\n\n"+
  "$H$B$                        CYCLONE OF FROST$N$\n\n"+
  "\t\t$H$K$ which engulf's your foe with tendrils of pure pain!$N$\n");
add_special_rmessage(
      "\t$H$K$UN$ holds the Lance before"+
      " $UOB$ summoning forth a\n\n"+
      "$H$B$                                        CYCLONE OF FROST $N$\n\n"+
      "\t\t$H$K$which engulf's its victim with tendrils of pure pain!$N$\n");
add_special_message(
 "$H$K$Your Lance drives into your foe sending shards of$H$B$ ICE"+NORM+""+
 "$H$K$ digging into their flesh!$N$\n");
add_special_rmessage(
 "$H$K$UN$'s Lance drives into it's victim slamming them with"+
 " shards of $H$B$ICE!$N$\n");
add_special_fun("/players/maledicta/weapon/powers/death.c");
add_special_fun("/players/maledicta/weapon/powers/nova.c");
add_special_damage(7);
add_special_damage(4);

set_two_handed_wep(1);
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


