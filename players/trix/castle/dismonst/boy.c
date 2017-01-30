inherit "obj/monster";
reset(arg){
   object gold;
   ::reset(arg);
   if(arg) return;
   set_name("boy");
   set_race("human");
   set_alias("boy");
   set_short("A lustful boy");
   set_long("A lustful boy , he's turned on and on and on.\n");
   set_level(14);
   set_hp(210);
   set_al(100);
   set_wc(18);
   set_ac(11);
   set_aggressive(0);
   set_chat_chance (15);
   load_chat("The boy looks at a girl.\n");
   load_chat("The boy groans.\n");
   set_chance(10);
   set_spell_dam(random(2)+1);
   set_spell_mess1("The boy tackles you to the ground.");
   set_spell_mess2("The boy knocks you down.");    
   gold=clone_object("obj/money");
   gold->set_money(800 + random(50));
   move_object(gold,this_object());
}
