inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
  object gold;
  gold = clone_object("obj/money");
  gold->set_money(6000);
  move_object(gold,this_object());
     set_name( "troll" );
     set_short("A Troll");
     set_alt_name("supertroll");
     set_race( "troll");
     set_long("A huge, wicked looking troll with large claws.\n"+
       "It appears to have a large 'S' rune carved into its chest.\n");
     set_frog(1);
     set_level(22);
     set_heal(1, 8);
     set_ac(14);
     set_wc(22);
     set_hp(8000);
     set_al(-1000);
     set_aggressive(0);
     set_chat_chance(100);
     set_a_chat_chance(10);
     load_chat("Troll hits a child.\n");
     load_chat("Troll massacres a child to small bits.\n");
     load_chat("Troll hits child with a bone crushing sound.\n");
     load_chat("Troll kills a child.\n");
     load_chat("Troll misses a child.\n");
     load_chat("Troll hits a child.\n");
     load_a_chat("The Troll laughs at you.\n");
     load_a_chat("The Troll shrugs off your attacks.\n");
     load_a_chat("The Troll stomps on your foot.\n");
     load_a_chat("The Troll yawns.\n");
     load_a_chat("The Troll slams its fist into you.\n");

set_spell_mess1("SuperTroll slams his foe against the cavern wall.");
set_spell_mess2("SuperTroll slams you against the cavern wall.");
     set_chance(10);
     set_spell_dam(20);
   }
}
