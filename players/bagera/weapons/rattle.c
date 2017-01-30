inherit "obj/weapon.c";

reset(arg) {
   set_name("snakeskin");
   set_alias("skin");
  set_short("Snakeskin");
  set_long("The skin of the tail of a deadly rattlesnake.\n");
   set_class(5);
   set_weight(2);
   set_value(200);
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
