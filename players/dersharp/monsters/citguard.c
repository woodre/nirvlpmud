inherit "obj/monster";
reset(arg){
   object gold,armor,weapon;
   ::reset(arg);
   if(arg) return;
   set_name("citadel guard");
   set_race("human");
   set_alias("guard");
   set_short("Citadel Guard");
   set_long("This is a guard of the Citadel of Greyhawk.  He has orders\n"+
            "to kill anyone trying to enter the citadel.  He looks \n"+
            "very tough.\n");
   set_level(16);
   set_hp(400);
   set_al(0);
   set_wc(22);
   set_ac(13);
   set_chat_chance(2);
   load_chat("Guard brandishes his weapon threatenlingly\n");
   load_chat("Guard says: GRIPES!!! somebody light a match!\n");
   gold=clone_object("obj/money");
   gold->set_money(random(100)+300);
   move_object(gold,this_object());
   weapon=clone_object("/players/dersharp/weapons/gsword.c");
   move_object(weapon,this_object());
}
