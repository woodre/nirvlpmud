inherit "obj/weapon.c";

reset(arg) {
   set_name("collar");
   set_alias("collar");
  set_short("A diamond studded collar");
   set_long("A magical diamond studded collar, but deadly all the same.\n");
   set_class(10);
   set_weight(1);
   set_value(20000);
   set_hit_func(this_object());
   set_save_flag(0);
   
}

weapon_hit(attacker) {
   if(call_other(this_player(), "query_attrib", "wis") > random(21)) {
      write("Your foe is strangled by the collar!\n");
      attacker->hit_player(4);
      return 1;
   }
   return;
}
