inherit "obj/weapon.c";

reset(arg) {
   set_name("club of sleep");
   set_alias("club");
   set_short("Club of Sleep");
   set_long("The ancient Club of Untamo. Holding it makes you feel sleepy.\n");
   set_class(12);
   set_weight(3);
   set_value(750);
   set_hit_func(this_object());
   set_save_flag(0);
   
}

weapon_hit(attacker) {
   if(random(20) > 13) {
      write("You strike your foe, sending him to the land of dreams.\n");
      attacker->hit_player(7);
      return 1;
   }
   return 1;

}

