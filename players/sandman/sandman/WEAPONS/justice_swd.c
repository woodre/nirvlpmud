inherit "obj/weapon.c";

reset(arg) {
   set_name("sword of justice");
   set_alias("sword");
   set_short("Sword of Justice");
   set_long("This is a long sword gleaming with blue light!\n");
   set_class(17);
   set_weight(3);
   set_value(2500);
   set_hit_func(this_object());
   set_save_flag(0);
   
}

weapon_hit(attacker) {
   if(this_player()->query_alignment() > 100) {
      write("The sword glows with white fire!\n");
      write("You hear Valkyries singing in the distance!\n");
      attacker->hit_player(7);
      return 1;
   }
   write("The sword burns in your hand, sending a shiver into your unclean soul.\n");
   this_player()->hit_player(3);
   return;
}
