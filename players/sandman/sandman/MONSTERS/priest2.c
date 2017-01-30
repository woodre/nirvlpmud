inherit "obj/monster.c";
reset(arg) {
   ::reset(arg);
   if(!arg) {
      object weapon;
      weapon = clone_object("players/sandman/WEAPONS/p_mace");
      move_object(weapon, this_object());
      set_name("templar");
      set_alias("dark templar");
      set_short("Dark Templar");
      set_long("The bloody hand of Azrah, this is a dark templar, the muscle\n"
+              "that inflicts slavery upon the people of Meddena. The common\n"
+              "people call them the shadows because of the black enameled\n"
+              "scale mail that cloaks them.\n");
      set_ac(14);
      set_wc(18);
      set_race("human");
      set_level(17);
      set_hp(450);
      set_al(-300);
      set_aggressive(1);
      set_chance(20);
      set_spell_dam(20);
      set_spell_mess1("Templar murmurs a prayer to his dread godess\n");
      set_spell_mess2("Templar hammers you with his heavy mace.\n");
   }
}
