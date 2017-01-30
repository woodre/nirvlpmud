inherit "obj/monster";
reset(arg){
  object gold;
   ::reset(arg);
   if(arg) return;
   set_name("cashmere");
   set_race("human");
   set_short("Cashmere");
   set_long(
   "    This is your basic 7-eleven employee.  He speaks in tongue that\n"+
   "you can barely understand, and he's here all the time.\n");
   set_level(9);
   set_hp(135);
   set_ac(7);
   set_wc(13);
   set_al(100);
   gold=clone_object("obj/money");
   gold->set_money(400);
   move_object(gold, this_object());
}
