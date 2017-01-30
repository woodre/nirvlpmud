inherit "obj/monster.c";
reset(arg) {
   ::reset(arg);
   if(!arg) {
      object medallion;
      medallion = clone_object("players/sandman/KRIL/OBJ/gd_pin");
      move_object(medallion, this_object());
      set_name("captain");
      set_alias("watch captain");
      set_short("Watch Captain");
     set_long("The captain of the watch has seen everything during his\n"
+             "twenty years in the duke's sevice. He watches the bustling\n"
+             "crowd with a practiced eye, his hand resting lightly on the\n"
+             "worn pommel of his trusty short sword.\n");
      set_ac(10);
      set_wc(14);
      set_race("human");
      set_level(15);
      set_hp(175);
      set_aggressive(0);
      set_al(0);
      set_chance(20);
     set_spell_mess1("Watch Captain slashes you with a viscious cut!\n");
     set_spell_mess2("Watch Captain yells for the city guard.\n");
      set_spell_dam(15);
     set_chat_chance(15);
    load_chat("Watch Captain rumbles: Be ready to pay your fee.\n");
     load_chat("Watch Captain says: Keep it orderly, or I WILL!\n");
   }
}
