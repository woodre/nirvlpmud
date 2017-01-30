inherit "obj/monster";

reset(arg){
   object gold,wep,weapon;
   ::reset(arg);
   if(arg) return;
   set_name("imp");
   set_alias("imp");
set_short("Impenetrable");
set_long("Another hard bastard. Be careful. Hes as tough as Imperial.\n");
   set_level(7);
   set_hp(105);
   set_al(100);
   set_wc(11);
   set_ac(6);
   gold=clone_object("obj/money");
   gold->set_money(300);
   move_object(gold,this_object());
}
