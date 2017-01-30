inherit "obj/monster";
   object gold;
reset(arg){
   object cert;
   object paper;
   ::reset(arg);
   set_name("fran");
   set_race("human");
   set_alias("prof");
   set_short("Fran, associate professor");
   set_long("Fran was invited to join the Faculty of Engineering 11 months ago.\n"+
            "He accepted this new appointment very happily and proudly.  His areas\n"+
            "of specialization are manufacturing and machining and he works hard\n"+
            "in the teaching and in the research activities.  His students like him\n"+
            "because he is always willing to help and to give advice.  Unfortunately,\n"+
            "the laboratories arent very modern and he has some troubles finding new\n"+
            "research funds due to budget cuts made at higher levels by both The \n"+
            "Government and by The National Research Council.  Yet,  he is likely \n"+
            "going to get good grants from the industries that might give him new \n"+
            "and strong opportunities for preparing and publishing good scientific\n"+
            "papers.  He is 5'11\", a little overweight, close to completely bald.\n"+
            "He is wearing glasses, jeans, shirt and a tie.\n");
   set_level(19);
   set_hp(475);
   set_al(0);
   set_wc(30);
   set_ac(15);
   set_chat_chance(10);
   load_chat("Fran mumbles:  Eh, this government keeps cutting our research funds.\n");
   load_chat("Fran says:  They must approve this article, it is a very innovative one!\n");
   load_chat("Fran says:  I like to play mastermind games when i am not that busy with experiments.\n");
   load_chat("Fran mumbles: The mastermind is a nice tool to let my students train their brains.\n");
   load_chat("Fran ponders:  I hope nobody but my students will find how to get the userid and the password to my new computer.\n");
   set_chance(15);
   set_spell_mess2("Fran tells you:  How come you are not in the machining lab, doing your thesis?");
   set_spell_mess1("Fran tells you:  How come you are not in the machining lab, doing your thesis?");;
   set_spell_dam(20);
 gold = clone_object("obj/money");
 gold->set_money(random(300)+300);
 move_object(gold,this_object());
 cert = clone_object("/players/francesco/univ/items/certificate3.c");
 move_object(cert,this_object());
 paper = clone_object("/players/francesco/masterquest/paper.c");
 move_object(paper,this_object()); 

}
