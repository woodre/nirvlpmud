inherit "obj/monster.c";
reset(arg) {
   ::reset(arg);
   if(!arg) {
      object armor;
      armor = clone_object("players/sandman/ARMORS/sash");
      move_object(armor, this_object());
      set_name("temple guard");
      set_alias("guard");
      set_short("Temple Guard");
      set_long("A swift angle of death, his sole desire is to protect the\n"+
               "temple from intruders. He is swathed from head to toe\n"+
               "in black scaled armor. A red sash proclaims him as a member\n"+
               "of the rajah's elite guards.\n");
      set_ac(10);
      set_wc(18);
      set_race("human");
      set_level(15);
      set_hp(225);
      set_al(0);
      set_chat_chance(15);
      load_chat("Temple Guard brandishes his sword at you.\n");
      load_chat("Temple Guard scowls at you menacingly.\n");
      set_spell_dam(15);
      set_chance(15);
      set_spell_mess1("The Temple Guard lands a vicious reposte.\n");
      set_spell_mess2("Temple Guard yells: For Azrah I die!!!!\n");
   }
}
