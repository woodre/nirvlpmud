inherit "obj/monster";
reset(arg){
   object gold,ob1;
   ::reset(arg);
   if(arg) return;
   set_name("cassius");
   set_race("human");
   set_short("Cassius");
   set_long("He was a roman senator.  Giulius Caesar sent him into the Gaul\n"+
   "to check the situation\n");
   set_level(19);
   set_hp(475);
  set_al(-100);
   set_wc(28);
   set_ac(16);
   gold=clone_object("obj/money");
   gold->set_money(200 + random(30));
   move_object(gold,this_object());
   ob1=clone_object("players/hurtbrain/castello/dag/tunic");
   move_object(ob1,this_object());
}
