inherit "obj/monster";

reset(arg){
   object gold,wep,weapon;
   ::reset(arg);
   if(arg) return;
   set_name("imp");
   set_alias("imp");
set_short("Impact");
set_long("Another one of the tough guys. He packs quite an impact *cackle* You\n"+"were warned.\n");
   set_level(5);
   set_hp(75);
   set_al(100);
   set_wc(9);
   set_ac(5);
   gold=clone_object("obj/money");
   gold->set_money(200);
   move_object(gold,this_object());
}
