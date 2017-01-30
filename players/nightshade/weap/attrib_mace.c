/* changed rnd from 41 to 50
- mythos <5-10-96> */

inherit "obj/weapon.c";

reset(arg) {
   set_name("mace");
   set_alias("black mace");
   set_short("Black Mace");
   set_long("This is a worn mace of black pitted steal.\n");
   set_class(16);
   set_weight(3);
   set_value(2000);
   set_hit_func(this_object());
   set_save_flag(0);
   
}

weapon_hit(attacker) {
   if(call_other(this_player(), "query_attrib", "str") > random(50)) {
      write("You slam the mace into your foe with greater force.\n");
      write("The clash of the mace is deffening.\n");
      return 5;
   }
   return;
}
