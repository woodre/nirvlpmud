inherit "obj/weapon.c";

reset(arg) {
   set_name("foot ball");
   set_alias("ball");
   set_short("Foot Ball");
   set_long("A regulation football. A deadly weapon in the right hands.\n");
   set_class(12);
   set_weight(2);
   set_value(750);
   set_hit_func(this_object());
   set_save_flag(0);
   
}

weapon_hit(attacker) {
   if(random(20) > 5) {
      write("You throw the ball hitting your foe in the head.\n");
      write("It bounces back into your hands.\n");
      return 1;
   }
   return 1;

}

