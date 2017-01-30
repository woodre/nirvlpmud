inherit "obj/monster";
reset(arg){
   object gold,ob1;
   ::reset(arg);
   if(arg) return;
   set_name("assurancenturix");
   set_race("human");
   set_alias("bard");
   set_short("Assurancenturix, the bard");
   set_long("You see a little man playing a lyre. What an horrible sound!\n");
   set_level(19);
   set_hp(475);
   set_al(50);
   set_wc(28);
   set_ac(16);
   set_chat_chance (30);
   load_chat("Assurancenturix says : 'You want to listen this beautiful sound?'\n");
   load_chat("Assurancenturix plays his lyre.\n");
   load_chat("Assurancenturix clears his throath ad starts to sing.\n");
   set_chance(10);
   set_spell_dam(random(10)+20);
   set_spell_mess1("Assurancenturix starts to play his lyre. You plug your ears.\n");
   set_spell_mess2("The bard plays his lyre on you and hurts your ears.\n");
   gold=clone_object("obj/money");
   gold->set_money(500 + random(50));
   move_object(gold,this_object());
   ob1=clone_object("players/hurtbrain/castello/dag/gaul/lyre");
   move_object(ob1,this_object());
}
