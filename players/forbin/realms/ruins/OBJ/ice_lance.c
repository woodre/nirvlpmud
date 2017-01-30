#include "/players/forbin/define.h"
inherit "players/maledicta/weapon/weapon.c";

id(str) { return (::id(str) || str == "collectable_bounty_object"); }

reset(arg){
  ::reset(arg);
  if(arg) return;
  set_name("lance");
  set_alt_name("collectable_obj_ice");
  set_alias("icebrand");
  set_short(HIK+"Chu'Sarth Lance"+HIW+" ["+HIC+"Icebrand"+HIW+"]"+NORM);
  set_long(
    "  Looking at this long powerful weapon you see a spectre of\n"+
    "what the owner must have been like. Cold, deadly, and evil.\n"+
    "The weapon is covered with a light frost which never seems\n"+
    "to diminish, even at the touch of warmth.\n");
  set_type("spear");  
  set_class(19);
  set_weight(6);
  set_value(4500+random(1000));
  add_special_chance(10);
  add_special_chance(30);
  add_special_message(
    "\t$H$K$Holding the Lance before you, you summon forth a$N$\n\n"+
    "$H$C$                        CYCLONE OF FROST$N$\n\n"+
    "\t\t$H$K$ which engulf's your foe with tendrils of pure pain!$N$\n");
  add_special_rmessage(
        "\t$H$K$UN$ holds the Lance before"+
        " $UOB$ summoning forth a\n\n"+
        "$H$C$                                        CYCLONE OF FROST $N$\n\n"+
        "\t\t$H$K$which engulf's its victim with tendrils of pure pain!$N$\n");
  add_special_message(
   "$H$K$Your Lance drives into your foe sending shards of$H$C$ ICE"+NORM+""+
   "$H$K$ digging into their flesh!$N$\n");
  add_special_rmessage(
   "$H$K$UN$'s Lance drives into it's victim slamming them with"+
   " shards of $H$C$ICE!$N$\n");
  add_special_damage(7);
  add_special_damage(4);
  set_two_handed_wep(1);
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
