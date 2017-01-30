inherit "obj/monster";
reset(arg){
   object gold;
   ::reset(arg);
   if(arg) return;
   set_name("woman");
   set_race("human");
   set_alias("woman");
   set_short("An old woman");
   set_long("An old woman , u shouldn't disturb her when she's praying\n");
   set_level(9);
   set_hp(25);
   set_al(200);
   set_wc(5);
   set_ac(3);
   set_aggressive(0);
   set_chat_chance (45);
   load_chat("Old woman says: Amen.\n");
   load_chat("Old woman says: Oh , my god!!\n");
   load_chat("Old woman says: I'm only a poor little woman!\n");
   load_chat("Old woman says: Do u know how to treat a poor little woman ?\n");
   gold=clone_object("obj/money");
   gold->set_money(20 + random(10));
   move_object(gold,this_object());
}
