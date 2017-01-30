inherit "obj/monster";
   object gold;
reset(arg){
   object cert;
   ::reset(arg);
   set_name("student");
   set_race("human");
   set_alias("student");
      set_short("A master student");
     set_long("This student is payed for his work.  He also helps with little tutoring\n"+
              "of the bachelor students.  His goal is to get a degree and then be\n"+
              "employed in a mechanical working firm as a production manager.  Tall\n"+
              "and slim, he trained his body with athletics and attained a good\n"+
              "strenght even though his muscles dont look very visible under his\n"+
              "cheap and wide suits.\n")
             ;

   set_level(18);
   set_hp(450);
   set_al(0);
   set_wc(26);
   set_ac(15);
 gold = clone_object("obj/money");
 gold->set_money(random(1500)+1400);
 move_object(gold,this_object());
 cert = clone_object("/players/francesco/univ/items/certificate2.c");
 move_object(cert,this_object());
   set_spell_dam(25);
   set_chance(18);
   set_spell_mess2("The master student throws you a book!");
   set_spell_mess1("The master student throws you a book!");

}
