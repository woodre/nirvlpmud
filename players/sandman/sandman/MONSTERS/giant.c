inherit "obj/monster.c";
reset(arg) {
   ::reset(arg);
   if(!arg) {
      object gold;
      gold = clone_object("obj/money");
      gold->set_money(random(200));
      move_object(gold, this_object());
      set_name("giant");
      set_alias("frost giant");
      set_short("Frost Giant");
      set_long("A powerfully built Frost Giant\n");
      set_ac(16);
      set_wc(20);
      set_race("giant");
      set_level(17);
      set_hp(425);
      set_al(-100);
      set_chat_chance(10);
      load_chat("Giant grumbles: Well come on, have at you!\n");
      load_chat("Giant says: I don't have all day, let's go!\n");
      set_chance(30);
      set_spell_mess1("Giant picks you up, and slams you to the mat!\n");
      set_spell_mess2("Giant puts you in a painful head lock!\n");
      set_spell_dam(35);
   }
}
