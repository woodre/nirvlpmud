inherit "/obj/monster";

reset(arg) {
   object gold;
   ::reset(arg);
   if (!arg) {

     set_name("ogre");
     set_short("Large Ogre");
     set_race( "ogre");
     set_gender("creature");
     set_long("A gnarly, angry ogre.  He stands about eight feet tall\n"+
        "and looks like he can lift tons.\n");
     set_level(14);

     init_command("wear armor");
     init_command("wield weapon");

     set_ac(12);
     set_wc(16 + random(4));
     set_hp(200 + random(30));
     set_al(-400);
     set_aggressive(1);
     set_a_chat_chance(10);
     load_a_chat("Ogre growls at you.\n");

     gold = clone_object("/obj/money");
     gold->set_money(random(500)+ 500);
     move_object(gold,this_object());
   }
}
