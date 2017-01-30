inherit "obj/monster";
   object gold;
reset(arg){
   object cert;   
   ::reset(arg);
   if (arg) return;
   set_name("professor");
   set_race("human");
   set_alias("prof");
   set_short("Prof. Sashangicatsanga Bhranopaardiamontry, full professor");
   set_long("Professor Sashangicatsanga Bhranopaardiamontry is from India.\n"+
            "After being involved in nuclear research activities, he turned\n"+
            "to mechanical engineering and got an outstanding paper award\n"+
            "at the Sixteenth World Conference on Machines and Machining,\n"+
            "held in Toronto, Ontario, 1991.  Then he was appointed a\n"+
            "full professor in this University where he is MOST Chair of\n"+
            "Manufacturing Engineering.  He is wearing a casual suit.\n");
   set_level(20);
   set_hp(650);
   set_al(-100);
   set_wc(33);
   set_ac(16);
   set_chance(20);
   set_spell_mess2("Professor tells you:  ahh!  you are not studying, are you?");
   set_spell_mess1("Professor says:  ahh!  you are not studying, are you?");
   set_spell_dam(60);
 gold = clone_object("obj/money");
 gold->set_money(240+random(700));
 move_object(gold,this_object());
 cert = clone_object("/players/francesco/univ/items/certificate.c");
 move_object(cert,this_object());

}
