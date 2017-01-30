inherit "players/sandman/paladin/obj/weapon";

reset(arg) {
   set_name("stealer");
   set_alias("soul stealer");
   set_short("Soul Stealer");
   set_long("This is a scimitar of ancient make. It's curved blade is\n"
+           "constructed of some glassy black colored metal. Along the blade\n"
+           "blood red runes flash with an eirie light. The hilt seems to\n"
+           "jump in your hand as if thousands of souls struggled for escape.\n");
   set_class(19);
   set_weight(2);
   set_value(10000);
   set_weapon_type("sword");
   set_hit_func(this_object());
   
}

weapon_hit(attacker) {
   if(this_player()->query_npc() == 1) { 
      write("The blade rejects you!!!\n");
      destruct(this_object());
      return 1;
   }
   if(this_player()->query_alignment() > -950) {
      this_player()->add_alignment(-20);
      write("Your soul feels sick as you use this evil sword\n");
   }
   if(this_player()->query_spell_point() > 5) {
      this_player()->add_spell_point(-3);
   }
   if(attacker->query_alignment() > 10) {
      write("The sword eagerly slashes into your innocent victim.\n");
      return 7;
   }
   return 0;
}
