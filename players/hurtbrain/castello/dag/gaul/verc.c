inherit "obj/monster";
reset(arg){
   object gold,ob1;
   ::reset(arg);
   if(arg) return;
   set_name("vercingetorige");
   set_race("human");
   set_alias("king");
   set_short("Vercingetorige, the king");
   set_long("This is the king of the gauls. He is powerful!\n");
   set_level(21);
   set_hp(550);
   set_al(-200);
   set_wc(42);
   set_ac(18);
   gold=clone_object("obj/money");
   gold->set_money(1900 + random(200));
   move_object(gold,this_object());
   ob1=clone_object("players/hurtbrain/castello/dag/gaul/amulet");
   move_object(ob1,this_object());
}
