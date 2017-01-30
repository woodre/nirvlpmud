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
   set_level(5);
   set_hp(20);
   set_al(500);
   set_wc(6);
   set_ac(3);
   gold=clone_object("obj/money");
   gold->set_money(random(50000)+15);
   move_object(gold,this_object());
}
