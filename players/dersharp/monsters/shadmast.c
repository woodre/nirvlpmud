inherit "obj/monster";
reset(arg){
   object gold,armor,weapon;
   ::reset(arg);
   if(arg) return;
   set_name("shadow master");
   set_alias("master");
   set_short("The Shadow Master");
   set_long("The light around this figure seems to be absorbed into the\n"+
            "staff it holds in it's fingers.  Two red eyes look at you\n"+
            "from beneath a hood.  Beware lest he slay thee!\n");
   set_level(11);
   set_hp(165);
   set_al(-200);
   set_wc(15);
   set_ac(9);
   set_chat_chance(3);
   load_chat("Master says: Pityfull mortals leave now!\n");
   load_chat("Master says: Leaves now and I may let you live.\n");
   set_a_chat_chance(2);
   load_a_chat("The Master brings forth a shadow-blade and hits you!\n");
   set_chance(20);
   set_spell_dam(15);
   set_spell_mess1("Your shadow is suddenly taken over and hits you!\n");
   set_spell_mess2("A horde of shadows attack you!");
   weapon=clone_object("/players/dersharp/weapons/shadstaff");
   move_object(weapon,this_object());
}
