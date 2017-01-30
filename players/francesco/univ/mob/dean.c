inherit "obj/monster";
   object gold;
   object cert;

reset(arg){
   ::reset(arg);
   set_name("head");
   set_race("human");
   set_alias("prof");
   set_short("Prof. Tsi-Ho-Cheng, the Head of the Department");
   set_long("Professor Tsi-Ho-Cheng came to this University in 1980 in order to\n"+
            "escape prosecution in his native country.  He is very nice to anyone\n"+
            "and very willing to improve the departmental activities.  Despite his\n"+
            "many responsabilities managing the Department he is also very active in \n"+
            "research.  His minute frame and permanent smile hide strong will and\n"+
            "personality.\n");
   set_level(20);
   set_hp(600);
   set_al(0);
   set_wc(33);
   set_ac(16);
   set_chance(25);
   set_spell_mess2("Prof. Tsi-Ho-Cheng quotes:  no room here for people like you,  drop it.");
   set_spell_mess1("Prof. Tsi-Ho-Cheng quotes:  no room here for people like you,  drop it.");
   set_spell_dam(40);
 gold = clone_object("obj/money");
 gold->set_money(random(99)+800);
 move_object(gold,this_object());
 cert = clone_object("/players/francesco/univ/items/certificate.c");
 move_object(cert,this_object());

}
