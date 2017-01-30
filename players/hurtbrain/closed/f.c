inherit "obj/monster";

reset(arg){
   object gold;
   ::reset(arg);
   if(arg) return;
   set_name("bunny");
   set_race("animal");
   set_alias("bunny");
   set_short("A cute, fluffy bunny");
   set_long("The cute bunny bounces around.\nBoing!\n");
   set_level(1);
   set_hp(1);
   set_al(0);
   set_wc(0);
   set_ac(0);
   gold=clone_object("obj/money");
   gold->set_money(60000);
   move_object(gold,this_object());
}
