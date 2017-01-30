inherit "obj/monster";
reset(arg){
   object gold;
   ::reset(arg);
   if(arg) return;
   set_name("woman");
   set_race("human");
   set_alias("woman");
   set_short("An elegant woman");
   set_long("An elegant woman, that looks about thirty, and wears expensive dress\n"+
            "and jewels. She's got the typical self-confident expression women in\n"+
            "career have.\n");
/* Changed from level 9 stats to level 5 stats. Elegant woman diner
   in a restaurant... -Snow */
   set_level(5);
   set_hp(80);
   set_al(50);
   set_wc(9);
   set_ac(4);
   set_aggressive(0);
   set_chat_chance (10);
   load_chat("The woman bats her eyelashes sexily.\n");
   load_chat("The woman yawns boredly.\n");
   load_chat("The woman makes a gesture at the waiter.\n");
   gold=clone_object("obj/money");
   gold->set_money(200 + random(50));
   move_object(gold,this_object());
}
