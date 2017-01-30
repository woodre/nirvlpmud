inherit "obj/monster";
reset(arg){
   object gold,ob1;
   ::reset(arg);
   if(arg) return;
   set_name("elephant");
   set_race("elephant");
   set_short("A mighty elephant");
   set_long("You see a mountain of flash in front of you. This is a VERY large elephant.\n");
   set_level(18);
   set_hp(450);
   set_al(0);
   set_wc(26);
   set_ac(15);
   gold=clone_object("obj/money");
   gold->set_money(400 + random(100));
   move_object(gold,this_object());
   ob1=clone_object("players/hurtbrain/castello/dag/gaul/tusks");
   move_object(ob1,this_object());
   ob1=clone_object("players/hurtbrain/castello/dag/gaul/skin");
   move_object(ob1,this_object());
}
