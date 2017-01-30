inherit "obj/monster.c";
reset(arg) {
   ::reset(arg);
   if(!arg) {
      object armor;
      armor = clone_object("players/sandman/ARMORS/scales");
      move_object(armor, this_object());
      set_name("serpent");
      set_alias("shadow serpent");
      set_short("Shadow Serpent");
      set_long("As children, we KNOW there are indeed foul creatures who\n"+
               "lurk in the deep dark places of the world. Their very\n"+
               "exhistance offends our innocence. As we grow older, we\n"+
               "convince ourselves to forget. Here is one such creature.\n"+
               "His visage is terror, the mindless terror of a child.\n");
      set_aggressive(0);
      set_ac(15);
      set_wc(28);
      set_race("dragon");
      set_level(18);
      set_hp(700);
      set_al(-800);
      set_chance(30);
      set_spell_mess1("You are overcome with a feeling of total fear.\n");
      set_spell_mess2("The serpent strikes you, its claws drip with blood.\n");
      set_spell_dam(30);
      set_chat_chance(20);
      load_chat("Serpent whispers: Ahhhh so we meet again child.\n");
      load_chat("Serpent whispers: There is power in the dark.\n");
   }
}
