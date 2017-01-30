inherit"obj/weapon";
reset(arg) {
   ::reset(arg);
   if(arg) return;
   set_name("Pole");
   set_alias("pole");
   set_short("Pole");
   set_long(
      "A large pole that was once used to measure the depth of the sea.  The\n"
      + "monkey king shrank the pole with his magic, and stores it in his ear.\n"
      + "When he needs it, he pulls it out and enlarges it to any size he wants.\n"
      + "Unfortinately, you do not know how he did this.\n");
   set_value(10000);
   set_weight(1);
   set_class(18);
   set_hit_func(this_object());
}
weapon_hit(attacker) {
   if(random(100) < 100) {
      write("The pole crushes "+attacker->query_name()+".\n");
      say("The pole smushes "+attacker->query_name()+".\n");
      return 0;
   }
}
