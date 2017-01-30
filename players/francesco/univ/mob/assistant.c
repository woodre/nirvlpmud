inherit "obj/monster";
   object gold;
reset(arg){
   object cert;
   ::reset(arg);
   set_name("assistant");
   set_race("human");
   set_alias("russo");
   set_short("Dr. Russo, assistant professor");
   set_long("This young assistant is dressed with casual clothes:  he\n"+
	    "stands approximately 5'8\" and has short brown hair.  He\n"+
            "is hard working and well-acquainted with the term 'publish\n"+
            "or perish'.  Right now he is doing his best to write good\n"+
            "papers and advance his academic career through innovative\n"+
            "research.\n");

   set_level(19);
   set_hp(475);
   set_al(0);
   set_wc(28);
   set_ac(16);
   set_chat_chance(10);
   load_chat("Dr. Russo says:  I cant get this experiment to give good results!  blah.\n");
   load_chat("Dr. Russo says:  Maybe i should use a faster oscylloscope.\n");
   set_chance(16);
   set_spell_mess2("Dr. Russo tells you:  Fix your experiment first, \n"+
                   "then come back here with the correct results.");
   set_spell_mess1("Dr. Russo says:  Fix your experiment first, \n"+
                   "then come back here with the correct results.");;
   set_spell_dam(15);
 gold = clone_object("obj/money");
 gold->set_money(random(280)+460);
 move_object(gold,this_object());
 cert = clone_object("/players/francesco/univ/items/certificate4.c");
 move_object(cert,this_object());

}
