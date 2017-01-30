inherit "obj/weapon.c";

reset(arg) {
   set_name("spear");
   set_alias("battered spear");
   set_short("A battered spear");
   set_long("A spear worn with use, but deadly all the same.\n");
   set_class(17);
   set_weight(2);
   set_value(2000);
   set_hit_func(this_object());
   set_save_flag(0);
   
}

weapon_hit(attacker) {
   if(call_other(this_player(), "query_attrib", "wis") > random(21)) {
      write("You pierce your foe with the spear!\n");
      attacker->hit_player(4);
      return 1;
   }
   return;
}
