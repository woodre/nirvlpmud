inherit "obj/monster";
   object gold;
reset(arg){
   object tunic;
   ::reset(arg);
   if (arg) return;
   set_name("emperor");
   set_race("human");
   set_alias("emperor");
   set_short("The Emperor");
   set_long("The Emperor Diocletian was an able organizer and administrator. \n"+
            "He tried to bring peace and stability in the Roman Empire after \n"+
            "50 years of civil war and anarchy. He restructured the bureacracy,\n"+
            "boosted the economy, reorganized the politics and the finance.\n"+
            "Yet, his reign was marred by persecutions of Christians and other \n"+
            "religious groups when he attempted to restore the pagan Roman gods.\n"+
            "He is wearing a sumptuous white tunic with red borders.\n");
   set_level(20);
   set_hp(650);
   set_al(-100);
   set_wc(33);
   set_ac(16);
   set_heal(11,2);
   set_ac_bonus(3);
   set_chance(20);
   set_spell_mess2("Help!! Help!! Guards!! Guards!!");
   set_spell_mess1("The Emperor screams:  You wont escape my bodyguards!!");
   set_spell_dam(60);
 gold = clone_object("obj/money");
 gold->set_money(40+random(700));
 move_object(gold,this_object());
/* tunic = clone_object("/players/francesco/roma/items/tunic.c");
 move_object(tunic,this_object());
*/
}