inherit "obj/monster";

reset(arg){
   object gold,wep,weapon;
   ::reset(arg);
   if(arg) return;
   set_name("imp");
   set_alias("imp");
set_short("Imperial");
set_long("This hoss is tryin to imitate an Imperial Guard. He looks and acts like one but does not fight like one.\n");
   set_level(3);
   set_hp(45);
   set_al(100);
   set_wc(7);
   set_ac(4);
   gold=clone_object("obj/money");
   gold->set_money(100);
   move_object(gold,this_object());
}
