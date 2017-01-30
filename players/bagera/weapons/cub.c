inherit "obj/weapon.c";

reset(arg) {
   set_name("bone");
   set_alias("bone");
  set_short("An old chew bone");
   set_long("A gnawed on chew bone. The edges are sharp and jagged.\n");
   set_class(1);
   set_weight(1);
   set_value(20);
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
