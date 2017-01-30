#include "defs.h"

inherit "obj/weapon.c";

/* Full reset() declaration should be the following: */
void reset(status arg) 
{
    ::reset(arg);
    if (arg) return;

    set_name("weeping blade");
    set_alias("blade");
    set_short(GRN+"Weeping"+NORM+HIK+" Blade"+NORM);
    set_type("sword");
    set_long(
"The favored weapon of Clan Eshin assassins.  A long serrated blade of\n\
corrupted metal infused with warpstone that weeps deadly posion.\n");
    set_class(17);
    set_weight(1);
    set_value(5000);
    set_hit_func(this_object());
}

/* Always try to use full function names */
int weapon_hit(object attacker)
{
   if(environment()->query_attrib("dex") > random(100)) {
      object poison;

      tell_room(environment(attacker),
         environment()->query_name()+" slices a deep gash in "+attacker->query_name()+".\n", ({ environment() }));
      tell_object(environment(),
       "You slash a deep wound in "+attacker->query_name()+".\n");
      tell_room(environment(attacker),
        "The blade leaves a "+HIK+"black"+NORM+"-"+GRN+"green"+NORM+" trail of poison.\n");

      if (!(poison = present(POIS_ID, attacker)))
      {
        poison = clone_object(POISON_PATH);
        move_object(poison, attacker);
        poison->begin_poison(attacker);
      }
      else
        poison->add_poison();
        
      return 3;
   }
}
