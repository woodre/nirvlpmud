inherit "obj/monster";
   object gold;

reset(arg){
   ::reset(arg);
   if(arg) return;
   set_name("wild dog");
   set_race("bug");
   set_gender("creature");
   set_alias("dog");
	set_short("A wild dog");
	set_long("A dog that had to run wild when his master couldn't take\n" +
"care of him any longer.  He looks very hungry.\n");
   set_level(19);
   set_hp(500);
   set_al(-1000);
   set_wc(18);
   set_ac(0);
	set_aggressive(0);
    gold = clone_object("obj/money");
	gold->set_money(random(300)+600);
   move_object(gold,this_object());
}
