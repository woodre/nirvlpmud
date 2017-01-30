inherit "obj/monster.talk";

object gold;
reset(arg) {
   ::reset(arg);
   if(!arg) {
      set_name("bartender");
      set_alias("barkeep");
      set_short("A Fat Greasy Barkeep");
      set_race("keep");
      set_long(
         "  This is the 'cheery' barkeep that every bar is supposed to have.  This\n"+
         "one is steadily pouring drink after drink for the esteemed Mr. Bundy and\n"+
         "spit shining the glasses to look real nice.  He carries all the money for the\n"+
         "bar, but I wouldn't advise attacking him.  You can type <list> and <buy #> if\n"+
         "you are foolish enough to drink here.  But I wouldn't advise that either.\n");
      gold = clone_object("obj/money");
      gold -> set_money (random (10000) + 10000);
      move_object(gold, this_object());
      set_level(20);
      set_hp(10000);
      set_ac(50);
      set_wc(100);
      set_al(-300);
      set_chance(20);
      set_spell_dam(75);
      set_spell_mess2("The Barkeep destroys you!\nRun!\n");
      set_spell_mess1("The barkeep is forced to get all rogish with his foe.\n");
      set_aggressive(0);
      set_a_chat_chance(10);
      set_chat_chance(10);
      load_chat("Barkeep says: Here's your drink loser.\n");
      load_chat("Barkeep spits in a glass and wipes it.\n");
      load_chat("Barkeep says: What do you want?\n");
      load_chat("Barkeep says: Don't even think about it.\n");
      load_a_chat("Barkeep says: You should run.\n");
   }
}
