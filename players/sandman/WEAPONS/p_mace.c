inherit "players/sandman/paladin/obj/weapon";

reset(arg) {
   set_name("mace");
   set_alias("steel mace");
   set_short("Steel Mace");
   set_long("The weapon of choice for the warrior-priest's of Azrah, this\n"
+           "mace is made of high temperature forged steel. However it\n"
+           "takes great strength to wield effectively.\n");
   set_class(16);
   set_weight(3);
   set_value(1500);
   set_weapon_type("mace");
   set_hit_func(this_object());
   
}

weapon_hit(attacker) {
   if(call_other(this_player(), "query_attrib", "str") > random(50)) {
      write("Your mace slams into your opponent's skull with a thwak!\n");
      return 5;
   }
   return;
}
