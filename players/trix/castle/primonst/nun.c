inherit "obj/monster";
reset(arg){
   object gold,dress;
   ::reset(arg);
   if(arg) return;
   set_name("nun");
   set_race("human");
   set_alias("nun");
   set_short("A nun");
   set_long("A nun dressed in black and white, praying to God.\n");
   set_gender("female");
   set_level(5);
   set_hp(75);
   set_al(300);
   set_wc(9);
   set_ac(5);
   set_aggressive(0);
   set_chat_chance (15);
   load_chat("Nuns pray.\n");
   set_chance(10);
   set_spell_dam(random(1)+1);
   set_spell_mess1("Nun slaps you.");
   set_spell_mess2("Nun points her finger at you!");
   gold=clone_object("obj/money");
   gold->set_money(random (20)+100);
   move_object(gold,this_object());
   dress=clone_object("players/trix/castle/primonst/dress.c");
   move_object(dress,this_object());
}
