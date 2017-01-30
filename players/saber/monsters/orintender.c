inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
   object ob, ob2, ob3;
ob2 = clone_object("/players/saber/stuff/rag.c");
move_object(ob2,this_object());
      set_name("bartender");
     set_alias("man");
      set_short("A Bartender");
     set_race( "human");
      set_long("A large black man with a friendly face.\n"+
          "You get the impression that he might be mute.\n");
     set_level(10);
     set_ac(8);
     set_wc(14);
     set_hp(150);
     set_al(150);
     set_heal(2,25);
     set_aggressive(0);
     set_chat_chance(3);
     set_a_chat_chance(15);
      load_chat("The bartender polishes a mug.\n");
      load_chat("The bartender wipes down the bar counter.\n");
     load_a_chat("Bartender glares at you.\n");
      load_a_chat("The Bartender rings a small silver bell.\n");

     set_spell_mess1("The Bartender punches you in the face.\n");
     set_spell_mess2("The Bartender punches his opponent in the face.\n");
     set_chance(20);
     set_spell_dam(9);
   }
}
