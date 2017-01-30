inherit "obj/monster";
reset(arg){
   object gold,armor,weapon;
   ::reset(arg);
   if(arg) return;
   set_name("chert");
   set_alias("barbarian");
   set_short("Chert the Barbarian");
   set_long("This burly companion of Gord came out of his forest community\n"+
            "to find adventure and wealth.  He is a large man, close to six\n"+
            "feet tall and is very muscular.  His axe, which he never leaves\n"+
            "hangs at his side ready for combat.\n");
   set_level(25);
   set_hp(750);
   set_al(100);
   set_wc(40);
   set_ac(22);
   set_chance(20);
   set_spell_dam(random(20));
   set_spell_mess1("Chert yells a battle cry and punishes you severely!\n");
   set_spell_mess2("Chert yells loudly and wounds you deeply!\n");
   set_chat_chance(2);
   load_chat("Chert says: There is evil afoot!\n");
   load_chat("Chert yawns deeply and looks around.\n");
   set_a_chat_chance(3);
   load_a_chat("Chert yells: BRUUL!!!!!!!!!!!!!!!\n");
   load_a_chat("Chert says: Poor little fool!\n");
   weapon=clone_object("/players/dersharp/weapons/daxe");
   move_object(weapon,this_object());
}
