inherit "obj/weapon";

reset(arg) {
   ::reset(arg);
   set_id("growl");
   set_name("GRRROWL");
   set_class(13);
   set_weight(2);
   set_value(250);
   set_alt_name("growl");
   set_hit_func(this_object());
   set_short("Tigger's Growl");
   set_long("The mighty roar of Tigger is a handy weapon to\n"+
            "fight off attackers.  ROAR!!!\n");
}

weapon_hit(attacker) {
   if(!random(5)) {
      write("You ROAR with all your breathy might at "+attacker->query_name()+".\n");
      say(this_player()->query_name()+" lets forth a mighty ROAR at "+attacker->query_name()+".\n");
      return 4;
   }
}
