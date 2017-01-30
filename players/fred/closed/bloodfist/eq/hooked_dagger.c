inherit "/obj/weapon.c";
#include "/players/fred/ansi.h"

reset(arg) {
   ::reset(arg);
   if (arg) return;

  set_name("hooked dagger");
  set_long(
"This dagger curves around at the end almost causing it to resemble a\n"+
"hook.  Both edges of the blade are serrated and deathly sharp.  The\n"+
"weapon could clearly tear through anything soft with virtual ease.\n");
  set_type("dagger");
  set_value(700);
  set_weight(2);
  set_class(18);
  set_hit_func(this_object());
}

short(){
  if(::query_wear() > 100)
    short_desc = "A hooked dagger "+RED+"<bloody>"+NORM;
  else
    short_desc = "A hooked dagger";
  return (::short());
}

int weapon_hit(object target){
  if(random(100) <= 10)
  {
    tell_object(environment(),
      "\nYou rip into "+target->short()+" with your hooked dagger.\n\t\t"+
      RED+"Blood drips from the wound.\n\n"+NORM);
    tell_room(environment(target), environment()->query_name()+
      " rips into "+target->short()+" drawing "+RED+"blood.\n"+NORM,
      ({ environment() }));
    return 6; 
  }
  else if(!random(3))
  {
    tell_room(environment(target), environment()->query_name()+
      " slashes "+target->short()+" with "+environment()->query_possessive()+
      " hooked dagger.\n", ({ environment() }));
    tell_object(environment(),
      "You slash "+target->short()+" with your hooked dagger.\n");
    return 2;
  }
}
