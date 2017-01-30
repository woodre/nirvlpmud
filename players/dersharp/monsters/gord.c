inherit "obj/monster";
reset(arg){
   object gold,armor,weapon;
   ::reset(arg);
   if(arg) return;
   set_name("gord");
   set_alias("thief");
   set_short("Gord the Rogue");
   set_long("This man is one of the most feared in all Oerth.  Beware his\n"+
            "lightning moves can kill you quickly.  He stands slightly\n"+
            "under six feet and walks with the ease of a trained soldier.\n"+
            "However he is not a warrior, he is a thief and as such he has\n"+
            "no rival.  He has now set his mind on conquering the greatest\n"+
            "evil that has ever lived.....or die trying.\n");
   set_level(30);
   set_hp(1000);
   set_wc(50);
   set_ac(27);
   set_al(0);
   set_chance(40);
   set_spell_dam(25);
   set_spell_mess1("Gord attacks with the speed of a trained acrobat!\n");
   set_spell_mess2("You are taken back by a flurry of blows!\n");
   set_chat_chance(2);
   load_chat("Gord says: The time has come to face the evil!\n");
   load_chat("Gord says: I wish Gellor and Chert were here.\n");
   set_a_chat_chance(2);
   load_a_chat("Gord evades your blows easily.\n");
   load_a_chat("Gord says: So be it......DIE!\n");
   gold=clone_object("obj/money");
   gold->set_money(15000);
   move_object(gold,this_object());
}
