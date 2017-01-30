
/*
 * MORDRAKE SWORD (3/8/94)
 * Does extra damage against evil creatures, no damage against good
 * Cloned in /players/molasar/rowan/mtn/lair.c
 */

inherit "obj/weapon";

reset(arg) {
   if(arg) return;
   set_short("A steel two-handed sword");
   set_long("The metal feels warm in your hands. You can't\n"+
            "find the slightest nick or scratch on the blade.\n"+
            "The leather straps around the hilt have decayed\n"+
            "making it hard to read the word embroided in\n"+
            "gold.  You can just make out:\n"+
            "              ? - ? - R - ? - R - A - ? - E\n");
   set_class(18);
   set_weight(2);
   set_hit_func(this_object());
   set_value(10000);
}

weapon_hit(attacker) {
   if(attacker->query_alignment() <= 0) {
     write("Your sword flashes brightly.\n");
     return 4;
   }
   return -18;  /* no good against good players */
}


