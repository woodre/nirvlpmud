inherit "obj/monster.c";
reset(arg) {
   ::reset(arg);
   if(!arg) {
      object item;
      item = clone_object("players/sandman/OBJ/history");
      move_object(item, this_object());
      set_name("scribe");
      set_alias("scribe of azrah");
      set_short("Scribe of Azrah");
      set_long("This is the scribe of Azrah, he keeps the histories of his\n"
+              "dread mistress's atrocities. A blood red robe cloaks his\n"
+              "thin ancient form, and he clutches a book in his arms\n"
+              "posessively.\n");
      set_ac(5);
      set_wc(11);
      set_race("human");
      set_level(16);
      set_hp(150);
      set_al(-300);
      set_chat_chance(15);
      load_chat("Scribe hisses: Kill them!!!!!\n");
      load_chat("Scribe screeches: You may not defile our sacred text!\n");
      set_a_chat_chance(10);
      load_a_chat("Scribe screams: Azrah shall feast upon thee!!\n");
   }
}
