
/*
 * WEAK MACE (3/8/94)
 * Does extra damage against monsters of lower level than wielder
 * Cloned in /players/molasar/rowan/drake/sewer/sewer1_6
 */

inherit "players/sandman/paladin/obj/weapon";

reset(arg) {
   if(arg) return;
   set_name("mace");
   set_alias("bugbear_mace");
   set_short("A large metal mace");
   set_long("A large metal mace.\n"+
            "Written near the the handle is:\n"+
            "    The weaker the foe, the greater its woe!\n");
   set_class(14);
   set_hit_func(this_object());
   set_weight(1);
   set_value(1600);
   set_weapon_type("mace");
}

weapon_hit(attacker) {
   int lvl, att_lvl;

   lvl = this_player()->query_level();
   att_lvl = attacker->query_level();
   if(lvl > att_lvl) {
     write("You smash your weaker opponent with your mace!\n");
     return 6;
   }
   return 0;
}


