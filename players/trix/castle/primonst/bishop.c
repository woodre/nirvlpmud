/* Changed spell chance to 40 from 10. spell damage to random(20)+ 15
   from random(5)+5  -snow */
inherit "obj/monster";
reset(arg){
   object gold,ring,habit,mitre,crosier;
   ::reset(arg);
   if(arg) return;
   set_name("bishop");
   set_race("human");
   set_alias("bishop");
   set_short("A proud bishop");
   set_long(
"This is the bishop of the cathedral.  It's obvious that he hurts a\n"+
"lot.\n");
   set_level(20);
   set_hp(500);
   set_al(1000);
   set_wc(30);
   set_ac(17);
   set_aggressive(0);
   set_chat_chance (15);
   load_chat("Bishop says: May God bless you.\n");
   load_chat("Bishop says: In nomine Christi!\n");
   load_chat("Bishop says: Kirie eleison, kirie eleison, kirie eleison.\n");
   load_chat("Bishop raises his hands to the sky and mumbles holy words.\n");
   set_chance(40);
   set_spell_dam(random(20)+15);
   set_spell_mess1("Bishop points his finger at you , and you feel weaker.");
   set_spell_mess2("Bishop makes a gesture and forces you to kneel down.");
   gold=clone_object("obj/money");
   gold->set_money(1450 + random(50));
   move_object(gold,this_object());
   ring=clone_object("players/trix/castle/primonst/ring.c");
   move_object(ring,this_object());
   habit=clone_object("players/trix/castle/primonst/habit.c");
   move_object(habit,this_object());
   mitre=clone_object("players/trix/castle/primonst/mitre.c");
   move_object(mitre,this_object());
   crosier=clone_object("players/trix/castle/primonst/crosier.c");
   move_object(crosier,this_object());
}
