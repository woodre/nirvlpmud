inherit "obj/weapon.c";
init() {
   add_action("drop","drop");
}


reset(arg) {
   set_name("safety sword");
   set_alias("sword");
   set_short("Safety Sword");
   set_long("Remember the old safety scissors? well this is a safety sword!\n");
   set_class(10);
   set_weight(1);
   set_value(0);
   set_hit_func(this_object());
   set_save_flag(0);
   
}

weapon_hit(attacker) {
   if(this_player()->query_level() > 5) {
      write("You are not a newbie, you can not use this.\n");
      destruct(this_object());
      return 1;
   }
   return;
}
