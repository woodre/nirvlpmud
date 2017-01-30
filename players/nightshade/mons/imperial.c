inherit "obj/monster";

reset(arg){
   object gold,wep,weapon;
   ::reset(arg);
   if(arg) return;
   set_name("imp");
   set_alias("imp");
set_short("Imperial");
set_long("A member of the imperial guard, this guy is one of the\n"+
"hardest ones here. Be careful.\n");
   set_level(6);
   set_hp(90);
   set_al(100);
   set_wc(10);
   set_ac(5);
   gold=clone_object("obj/money");
   gold->set_money(250);
   move_object(gold,this_object());
}
