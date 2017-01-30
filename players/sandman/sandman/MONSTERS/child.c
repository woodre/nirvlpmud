inherit "obj/monster.c";
reset(arg) {
   ::reset(arg);
   if(!arg) {
      object gold;
      gold = clone_object("obj/money");
      gold->set_money(random(50));
      move_object(gold, this_object());
      set_name("child");
      set_alias("kid");
      set_short("Bratty child");
      set_long("One of those bratty little kids you always wished you\n"+
      "could kick the sh*t out of!\n");
      set_ac(4);
      set_wc(7);
      set_race("human");
      set_level(3);
      set_hp(45);
      set_al(-100);
      set_chat_chance(15);
      load_chat("bratty kid says: Hey! Your mom dresses you funny!\n");
      load_chat("bratty kid says: Euuuwww you've got cooties!\n");
      set_a_chat_chance(20);
      load_a_chat("Bratty kid screams in exagerated pain!\n");
   }
}
