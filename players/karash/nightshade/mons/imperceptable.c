inherit "obj/monster";

reset(arg){
   object gold,wep,weapon;
   ::reset(arg);
   if(arg) return;
set_name("imp");
set_short();
   set_alias("imp");
   set_level(4);
   set_hp(60);
   set_al(100);
   set_wc(8);
   set_ac(4);
   gold=clone_object("obj/money");
   gold->set_money(150);
   move_object(gold,this_object());
}
