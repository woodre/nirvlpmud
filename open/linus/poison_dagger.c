/*
     Poisoned Dagger - Written by Llew
     This won't ever be in the game, but it works nicely.
     Players would hate to not get exp if the poison kills their monster.
*/

#define POISON_PATH "/players/llew/Celts/weapons/poison.c"

 inherit "obj/weapon.c";

 reset(arg) {
    ::reset(arg);
    if (arg) return;

    set_name("poisoned dagger");
    set_alias("dagger");
    set_short("A poisoned dagger");
    set_long("A long jagged dagger dripping with dark green poison.\n"+
             "Be careful that you do not touch it.\n");
    set_class(12);
    set_weight(1);
    set_value(2000);
    set_hit_func(this_object());
}

weapon_hit(attacker){
   if(wielded_by->query_attrib("dex") > random(100)) {
      object poison;

      say(wielded_by->query_name()+" cuts a deep gash in "+attacker->query_name()+".\n");
      write("You cut a deep gash in "+attacker->query_name()+".\n");
      tell_room(environment(wielded_by),"The dagger leaves a black-green trail of poison.\n");

      poison = clone_object(POISON_PATH);
      move_object(poison, attacker);
      poison->begin_poison(attacker, 5, random(3) + 3, 6);
      return 3;
   }
}
