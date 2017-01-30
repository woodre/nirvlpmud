inherit "obj/monster.c";
reset(arg) {
   ::reset(arg);
   if(!arg) {
      object weapon;
      weapon = clone_object("players/sandman/WEAPONS/h_mace");
      move_object(weapon, this_object());
      set_name("hogun");
      set_alias("hogun the grim");
      set_short("Hogun the Grim");
      set_long("The somber faced member of the Warriors Three.\n");
      set_ac(12);
      set_wc(20);
      set_race("immortal");
      set_level(15);
      set_hp(225);
      set_al(0);
      set_chat_chance(10);
      load_chat("Hogun scowls at Volstagg.\n");
      load_chat("Hogun sighs.\n");
      set_a_chat_chance(20);
      load_a_chat("Hogun's mace slams into you!\n");
   }
}
