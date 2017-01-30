inherit "obj/monster.c";
reset(arg) {
   ::reset(arg);
   if(!arg) {
      object item,item2;
      item = clone_object("players/sandman/OBJ/orb");
      move_object(item, this_object());
      set_name("loki");
      set_alias("trickster");
      set_short("Loki");
      set_long("Loki, Prince of Lies!\n");
      set_aggressive(1);
      set_ac(16);
      set_wc(20);
      set_race("immortal");
      set_level(19);
      set_hp(475);
      set_al(-1000);
      set_chance(65);
      set_spell_mess1("Loki crooks his finger and you age!\n");
      set_spell_mess2("Blue fire courses through your body!\n");
      set_spell_dam(65);
   }
}
