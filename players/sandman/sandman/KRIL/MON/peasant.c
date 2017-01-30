inherit "obj/monster.c";
reset(arg) {
   ::reset(arg);
   if(!arg) {
      object gold;
      gold = clone_object("obj/money");
     gold->set_money(random(75));
      move_object(gold, this_object());
      set_name("peasant");
      set_alias("peasant");
      set_short("Peasant");
     set_long("This is one of the poor hard working peasants upon whose\n"
+             "backs the wealth and glory of Coral is built. He has a\n"
+             "rather mindless look about him, but then that's how the duke\n"
+             "likes his peasants, stupid and hardworking.\n");
      set_ac(5);
      set_wc(7);
      set_race("human");
      set_level(6);
      set_hp(50);
      set_aggressive(0);
      set_al(20);
     set_whimpy();
      set_chat_chance(15);
      load_chat("A peasant mills about stupidly.\n");
      load_chat("A peasant says: duh, what was I doing now??\n");
      set_a_chat_chance(10);
     load_a_chat("A peasant whines: Hey! what did I do to you??!!\n");
     load_a_chat("A peasant tries to run from your attack.\n");
   }
}
