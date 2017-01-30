#define POISON_PATH "/players/khrell/weapons/underways/poison.c"
#include "/players/khrell/ansi.h"

 inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

    set_name("weeping blade");
    set_alias("blade");
    set_short(GRN+"Wee"+HIK+"ping"+NORM+" Blade");
    set_type("sword");
    set_long("The favored weapon of Clan Eshin assassins.  A long serrated blade of\n"+
             "corrupted metal infused with warpstone and a deadly posion.\n");
    set_class(12);
    set_weight(1);
    set_value(2000);
    set_hit_func(this_object());
}

weapon_hit(attacker){
   if(wielded_by->query_attrib("dex") > random(100)) {
      object poison;

      say(wielded_by->query_name()+" slices a deep gash in "+attacker->query_name()+".\n");
      write("You slash a deep wound in "+attacker->query_name()+".\n");
      tell_room(environment(wielded_by),"The dagger leaves a "+HIK+"black"+NORM+"-"+GRN+"green"+NORM+" trail of poison.\n");

      poison = clone_object(POISON_PATH);
      move_object(poison, attacker);
      poison->begin_poison(attacker, 5, random(3) + 3, 6);
      return 3;
   }
}
