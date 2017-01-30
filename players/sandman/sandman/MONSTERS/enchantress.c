inherit "obj/monster.c";
reset(arg) {
   ::reset(arg);
   if(!arg) {
      object item;
      item = clone_object("players/sandman/OBJ/enchant_ring");
      move_object(item, this_object());
      set_name("enchantress");
      set_alias("witch");
      set_short("The Enchantress");
      set_long("An evil succumbus. Temptress of the god's\n");
      set_aggressive(1);
      set_ac(16);
      set_wc(28);
      set_race("immortal");
      set_level(19);
      set_hp(475);
      set_al(-1000);
      set_chance(50);
      set_spell_mess1("The Enchantress electricutes you!\n");
      set_spell_mess2("The Enchantress casts a charm spell!\n");
      set_spell_dam(50);
   }
}
