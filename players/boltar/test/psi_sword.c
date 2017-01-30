inherit "players/sandman/paladin/obj/weapon";

reset(arg) {
   set_name("psi sword");
   set_alias("sword");
   set_short("Psi Sword");
   set_long("This weapon is truely awesome to behold. A long and dangerous\n"
+           "longsword with a difference, its blade burns with holy fire.\n"
+           "The holy fire that lines your blade is the product of your\n"
+           "faith. As long as you are true, so shall it set evil a fire!\n");
   set_class(0);
   set_weight(2);
   set_value(50);
   set_buy_value(100);
   set_weapon_type("sword");
   set_hit_func(this_object());
   
}

weapon_hit(attacker) {
    object blah;
      write("Your sword cleanses your opponent with the fire of God!\n");
      blah=this_player()->query_attack();
      blah->heal_self(-40);
      return 0;
}

drop(silently) {
   if(wielded) {
      command("unwield sword", this_player());
      if(!silently)
         write("You drop your Psi Sword.\n");
   }
   write("The Psi Sword hits the ground, flickers and dissappears.\n");
   destruct(this_object());
   return 1;
}
