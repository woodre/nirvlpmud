 inherit "/obj/monster";
  reset(arg) {
    ::reset(arg);
    if (!arg) {
  object ob;
  ob = clone_object("/players/arrina/armor/bedsheet.c");
 move_object(ob,this_object());
       set_name("man");
      set_short("A Sick Man");
      set_race( "human");
      set_long("This poor man is suffering from some unknown illness. \n"
  +     "His once-powerful body is emaciated, and he looks incurable.\n");
      set_level(13);
      set_ac(10);
      set_wc(17);
      set_hp(195);
      set_al(-250);
      set_aggressive(0);
      set_chat_chance(20);
      set_a_chat_chance(25);
       load_chat("Man says: I was once the most powerful man in the land.\n");
      load_chat("Man says: The evil ones here have taken my strength.\n");
      load_chat("Man says: I must regain my strength, but I cannot.\n");
      load_chat("Man says: Only death lurks here.\n");
      load_a_chat("Man says: If you kill me, who will fix this mess?\n");
      load_a_chat("Man says: Please reclaim the castle from the dark ones.\n");
    }
 }
