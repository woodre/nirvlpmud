inherit "obj/monster";
reset(arg){
   object gold;
   ::reset(arg);
   if(arg) return;
   set_name("link");
   set_race("human");
   set_short("Link");
   set_long(
   "    This is Link, the caveman from Encino.  Stony is tellin him\n"+
   "about the four basic food groups, maybe you should listen.\n");
   set_level(17);
   set_hp(425);
   set_ac(14);
   set_wc(24);
   set_al(300);
   gold=clone_object("obj/money");
   gold->set_money(950);
   move_object(gold, this_object());
}
