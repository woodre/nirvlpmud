inherit "obj/monster.c";
reset(arg) {
   ::reset(arg);
   if(!arg) {
      object weapon, armor;
      weapon = clone_object("players/sandman/WEAPONS/odin_spear");
      armor = clone_object("players/sandman/ARMORS/patch");
      move_object(weapon, this_object());
      move_object(armor, this_object());
      set_name("odin");
      set_alias("one eye");
      set_short("Odin, One Eye");
      set_long("The grimm father of all the gods\n");
      set_aggressive(0);
      set_ac(17);
      set_wc(30);
      set_race("immortal");
      set_level(20);
      set_hp(500);
      set_al(0);
      set_chance(15);
      set_spell_mess1("Odin inpales you with his spear!\n");
      set_spell_mess2("Odin throws you to the ground!\n");
      set_spell_dam(40);
   }
}
