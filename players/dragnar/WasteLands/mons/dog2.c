inherit "obj/monster";
   object gold;

reset(arg){
   ::reset(arg);
   if(arg) return;
   set_name("Wild dog");
   set_race("dog");
   set_alias("dog");
	set_short("A wild dog");
	set_long("A dog that had to run wild when his master couldn't take\n" +
"care of him any longer.  He looks very hungry.\n");
   set_level(19);
   set_hp(475);
   set_al(-1000);
   set_wc(28);
   set_ac(16);
	set_aggressive(1);
    gold = clone_object("obj/money");
	gold->set_money(random(50)+800);
   move_object(gold,this_object());
}
