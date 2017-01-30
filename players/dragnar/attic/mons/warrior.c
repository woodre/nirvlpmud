inherit "obj/monster";
   object gold;

reset(arg){
   ::reset(arg);
   if(arg) return;
   set_name("warrior");
   set_race("warrior");
   set_alias("warrior");
	set_short("A training warrior");
	set_long("The warrior is 7 feet tall and in superior condition. His face\n"+
"seems to look a great deal like the old man however...\n");
   set_level(20);
   set_hp(500);
   set_al(-1000);
   set_wc(30);
   set_ac(17);
	set_aggressive(1);
    gold = clone_object("obj/money");
	gold->set_money(random(500)+600);
   move_object(gold,this_object());
}
