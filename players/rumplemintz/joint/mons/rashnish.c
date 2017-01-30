inherit "obj/monster";
reset(arg){
   object gold;
   ::reset(arg);
   if(arg) return;
   set_name("rashnish");
   set_race("human");
   set_short("Rashnish");
   set_long(
   "    This is Rashnish, Cashmere's counterpart in this business.\n"+
   "He isn't enjoying Stony's antics, and hates people who 'wease'.\n");
   set_level(10);
   set_hp(150);
   set_ac(8);
   set_wc(14);
   set_al(100);
   gold=clone_object("obj/money");
   gold->set_money(450);
   move_object(gold, this_object());
}
