inherit "obj/weapon.c";

reset(arg) {
   set_name("spear");
   set_alias("guardian spear");
   set_short("Guardian Spear");
   set_long("This is the Spear of Guarding, given to Hemidal by Oden.\n");
   set_class(15);
   set_weight(3);
   set_value(2000);
   set_hit_func(this_object());
   set_save_flag(0);
   
}

weapon_hit(attacker) {
   if(call_other(this_player(), "query_attrib", "int") > random(21)) {
      write("The spear flies from you hand!\n");
      write("It strikes your enemy and returns to your hand.\n");
      attacker->hit_player(4);
      return 1;
   }
   return;
}
