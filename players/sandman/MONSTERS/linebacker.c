inherit "obj/monster.c";
reset(arg) {
   ::reset(arg);
   if(!arg) {
      object gold;
      gold = clone_object("obj/money");
      gold->set_money(random(100));
      move_object(gold, this_object());
      set_name("linebacker");
      set_alias("jock");
      set_short("Linebacker");
      set_long("A big husky line backer. Alas he has no brain.\n");
      set_ac(4);
      set_wc(8);
      set_race("human");
      set_level(4);
      set_hp(60);
      set_al(100);
      set_chat_chance(10);
      load_chat("Linebacker says: Duh, you want we should mush this guy?\n");
      load_chat("A linebacker trips over his own feet.\n");
      set_a_chat_chance(20);
      load_a_chat("Linebacker growls at you.\n");
   }
}
