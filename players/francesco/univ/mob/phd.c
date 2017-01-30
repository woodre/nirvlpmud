inherit "obj/monster";
   object gold;
reset(arg){
   object cert;
   ::reset(arg);
   set_name("student");
   set_race("human");
   set_alias("student");
      set_short("A PhD student");
     set_long("Also this student is payed for his work about research, tutoring\n"+
              "and lectures.  He is working hard and has good hopes to enter the\n"+
              "academic career.  If he will not be lucky with this last, then he\n"+
              "will be glad to join a firm as a research scientist.\n")
             ;

   set_level(19);
   set_hp(455);
   set_al(0);
   set_wc(28);
   set_ac(17);
 gold = clone_object("obj/money");
 gold->set_money(random(2000)+1400);
 move_object(gold,this_object());
 cert = clone_object("/players/francesco/univ/items/certificate2.c");
 move_object(cert,this_object());
   set_spell_mess1("The phd students throws you a book!");
   set_spell_mess2("The phd students throws you a book!");
   set_chance(20);
   set_spell_dam(25);

}
