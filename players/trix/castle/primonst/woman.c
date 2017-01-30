inherit "obj/monster";
reset(arg){
   object gold;
   ::reset(arg);
   if(arg) return;
   set_name("woman");
   set_race("human");
   set_alias("woman");
   set_short("An old woman");
   set_long("An old woman.  You shouldn't disturb her while she's praying.\n");
   set_level(4);
   set_hp(60);
   set_al(200);
   set_wc(8);
   set_ac(4);
   set_aggressive(0);
   set_chat_chance (10);
   load_chat("Old woman says: Amen.\n");
   load_chat("Old woman says: Oh, my god!\n");
   load_chat("Old woman says: I'm only a poor old woman!\n");
   load_chat("Old woman says: Do you know how to treat a poor old woman?\n");
   gold=clone_object("obj/money");
   gold->set_money(140 + random(10));
   move_object(gold,this_object());
}
