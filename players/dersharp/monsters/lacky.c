inherit "obj/monster";
reset(arg){
   object gold,armor,weapon;
   ::reset(arg);
   if(arg) return;
   set_name("lacky");
   set_race("human");
   set_alias("lacky");
   set_short("A Citadel Lacky");
   set_long("These lackies have long been the source of internal strife in\n"+
            "Greyhawk.  The authorities would probably help you kill them.\n");
   set_level(10);
   set_hp(150);
   set_wc(14);
   set_ac(6);
   set_al(-100);

   set_chat_chance(2);
   load_chat("The lacky looks as if he has a scheme up his sleeve\n");
   load_chat("Lacky says: Hey, what are you doin here!?\n");
   gold=clone_object("obj/money");
   gold->set_money(random(100)+20);
   move_object(gold,this_object());
   weapon=clone_object("/players/dersharp/weapons/redtape.c");
   move_object(weapon,this_object());
}
