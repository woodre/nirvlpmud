#include "/players/mythos/closed/ansi.h"
inherit "obj/weapon.c";
reset(arg){
  ::reset(arg);
  if (arg) return;

  set_name("lysis");
  set_alias("knife");
  set_short("Crystal Knife");
  set_long("A blade of purest crystal flashes before your eyes.\n"+
          "Deep within the crystal a flame of blue burns.\n");
  set_class(10);
  set_weight(1);
  set_value(10);
  set_hit_func(this_object());
}
query_save_flag() { return 1;}

query_gsave() { return 1;}

cleanup() { fix_weapon(); misses = 0; hits = 0; }

init() {
  ::init();
  if(random(3)==0) {
    tell_object(this_player(),"The FIRE in the crystal "+HIC+"FLARES!"+NORM+"\n");
    this_object()->set_class(21);
    this_player()->heal_self(-1-random(30));
    tell_object(this_player(),"The blade quivers, you feel brief pain, and the knife is stronger!\n");
    }  else {
    tell_object(this_player(),"The fire in the crystal dies...\n");
    this_player()->heal_self(-1-random(20));
    this_object()->set_class(10);
    tell_object(this_player(),"You feel brief pain...\n");
    }
}

weapon_hit(attacker){
if(random(50) < this_player()->query_attrib("int")) {
  if(class_of_weapon == 21) {
    this_player()->hit_player(random(10));
  }
  tell_room(environment(this_player()),"The knife flares!!!\n"+
  BOLD+"\n\n------------------->"+HIR+"*"+NORM+BOLD+"<-------------------\n\n\n"+NORM);  
   }
   return;
}
