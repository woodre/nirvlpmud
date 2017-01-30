#include "/players/mythos/closed/ansi.h"
inherit "obj/weapon.c";
reset(arg){
  ::reset(arg);
  if (arg) return;
  set_name("nex");
  set_alias("knife");
  set_short("Dark Knife");
  set_long("A blade of some dark material- black as dried blood.\n"+
          "It has a malicious aura.\n");
  set_class(18);
  set_weight(1);
  set_value(2500);
  set_hit_func(this_object());
}

query_save_flag() { return 0;}

query_gsave() { return 1;}

cleanup() { fix_weapon(); misses = 0; hits = 0; }

weapon_hit(attacker){
  if(random(3)==0) {
    write("The knife flares for a second!\n");
    command("scream",attacker);
  return 7;}
   return 0;
}
