inherit "obj/weapon.c";

reset(arg) {
   set_name("claw");
   set_alias("tigerclaw");
  set_short("Tiger's Claw");
  set_long("This is the claw of a massive tiger. The claws are\n"+
           "jagged and drawn. The razor sharpness will slice\n"+
           "through your opponent with ease.\n");
   set_class(13);
   set_weight(4);
   set_value(2000);
   set_hit_func(this_object());
   set_save_flag(0);
   
}

weapon_hit(attacker) {
   if(call_other(this_player(), "query_attrib", "wis") > random(50)) {
      write("Your foe is strangled by the collar!\n");
      attacker->hit_player(4);
      return 1;
   }
   return;
}
