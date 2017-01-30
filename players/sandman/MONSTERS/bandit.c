inherit "obj/monster.c";
reset(arg) {
   ::reset(arg);
   if(!arg) {
      object weapon;
      weapon = clone_object("players/sandman/WEAPONS/scimitar");
      move_object(weapon, this_object());
      set_name("bandit");
      set_alias("scum");
      set_short("A Bandit");
      set_long("A wiry man covered from head to foot in black robes. His\n"+
      "cause him to blend in with the black shifting sands. His red eyes burn\n"
+     "from above his vail, there is no mercy in those eyes.\n");
      set_ac(8);
      set_wc(15);
      set_race("human");
      set_level(10);
      set_hp(110);
      set_al(-300);
      set_chat_chance(10);
      load_chat("The Bandit scowls at you.\n");
      load_chat("Bandit growls: mind your own business outlander.\n");
      set_a_chat_chance(20);
      load_a_chat("Bandit slices you with his sword!\n");
   }
}
