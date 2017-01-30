inherit "/obj/weapon.c";
#include "/players/zeus/closed/all.h"

reset(arg) {
   ::reset(arg);
   if (arg) return;

  set_name("steel knife");
  set_short("A steel knife");
  set_type("knife");
  set_long(
"This steel dagger is very well crafted.  It is about a foot and a half\n"+
"long, with a gripped hilt and a very narrow blade.  This is a very\n"+
"dangerous, and easily concealable dagger.\n");
  set_value(500);
  set_weight(2);
  set_class(16);
  set_save_flag(1);
  set_hit_func(TO);
}

int weapon_hit(object target){
  if(random(100)<=10) {
  tell_object(environment(),"You slash your enemy with the knife!\n");
  tell_room(environment(environment()),environment()->query_name()+
          " slashes "+environment()->query_possessive()+" enemy with "+
	  environment()->query_possessive()+" dagger!\n");
return 4; }
}

