inherit "/obj/weapon";

reset(arg) {
   ::reset(arg);
   if(arg) return;
   set_alias("rule");
   set_name("slide rule");
   set_short("A slide rule");
   set_long("\tOne of the oldest calculating devices,\n"+
            "the slide rule has gone out of vogue.  As\n"+
            "you examine it, you cut your finger on the\n"+
            "edge...I guess really is dangerous.\n");
   set_class(10);
   set_weight(2);
   set_value(150);
   set_hit_func(this_object());
}
weapon_hit(attacker) {
   if(attacker->query_name()=="omidon") {
      write("The slide rule bites into the disbeliever of science!\n");
      return 50;
   }
   return 0;
}
