inherit "obj/monster";
reset(arg){
   object gold,cassock,crucifix;
   ::reset(arg);
   if(arg) return;
   set_name("priest");
   set_race("human");
   set_alias("priest");
   set_short("A simple priest");
   set_long(
"You are in front of a simple priest.  He wears a black cassock and\n"+
"a huge brass crucifix.\n");
   set_level(19);
   set_hp(475);
   set_al(500);
   set_wc(28);
   set_ac(16);
   set_aggressive(0);
   set_chat_chance (15);
   load_chat("Priest says: Confess your guilts.\n");
   load_chat("Priest says: I'll absolve you, child!\n");
   load_chat("Priest says: Just tell me.  What did you do?\n");
   load_chat("Priest makes a cross gesture with his right hand.\n");
   set_chance(10);
   set_spell_dam(random(5)+2);
   set_spell_mess1("Priest throws his crucifix against you.");
   set_spell_mess2("Priest blames you.");
   gold=clone_object("obj/money");
   gold->set_money(900+ random(100));
   move_object(gold,this_object());
   cassock=clone_object("players/trix/castle/primonst/cassock.c");
   move_object(cassock,this_object());
   crucifix=clone_object("players/trix/castle/primonst/crucifix.c");
   move_object(crucifix,this_object());
}
