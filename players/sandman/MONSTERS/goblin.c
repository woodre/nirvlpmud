inherit "obj/monster.c";
reset(arg) {
   ::reset(arg);
   if(!arg) {
      object gold;
      gold = clone_object("obj/money");
      gold->set_money(random(200)+150);
      move_object(gold, this_object());
      set_name("deep goblin");
      set_alias("goblin");
      set_short("Deep Goblin");
      set_long("No one is quite sure how the deep goblins came to be.\n"+
               "Some say they were created by the dark and powerful things\n"+
               "of the earth, but others say they were once men. After\n"+
               "thousands of generations in the deep dark, they are now\n"+
               "mindless, deformed, blood thirsty slaves.\n");
      set_ac(9);
      set_wc(15);
      set_race("humanoid");
      set_level(12);
      set_hp(150);
      set_aggressive(1);
      set_al(-200);
      set_chat_chance(15);
      load_chat("A Goblin rushes at you screaching.\n");
      load_chat("A Goblin screams: Kill for Master! KILL KILL KILL!!!\n");
      set_a_chat_chance(10);
      load_a_chat("A Goblin swipes at you with a rusty sword.\n");
      load_a_chat("A Goblin gibbers insanely.\n");
   }
}
