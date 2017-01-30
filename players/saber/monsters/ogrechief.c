inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
object ob,ob2,ob3,gold;
gold = clone_object("obj/money");
gold->set_money(2500);
move_object(gold,this_object());
  ob = clone_object("/players/saber/weapons/tree.c");
move_object(ob,this_object());
 ob2 = clone_object("/players/saber/armor/fuzjacket.c");
move_object(ob2,this_object());
 ob3 = clone_object("/players/saber/armor/amuletpro.c");
move_object(ob3,this_object());
init_command("wield tree");
     set_name( "ogre chieftan" );
   set_short("An Ogre Chieftan");
     set_race( "ogre");
     set_long("A huge, ugly humaniod standing twelve feet tall with dead yellow skin and long,\n"+
 "greasy hair.  It has deep purple eyes with white pupils.  The oger is covered\n"+
 "with dark brown warts, and has dark black teeth.\n");
     set_level(20);
     set_ac(16);
     set_wc(30);
     set_hp(530);
     set_al(-750);
     set_aggressive(0);
     set_chat_chance(20);
     set_a_chat_chance(20);
     load_chat("Ogre Chieftan bellows: Go way.  Got no time for you.\n");
     load_chat("Ogre Chieftan looks around nervously.\n");
     load_a_chat("Ogre Chieftan bites you.\n");
     load_a_chat("Ogre Chieftan bellows: Stoopid small critter.\n");

     set_spell_mess2("Ogre Chieftan slams you a crushing blow.");
     set_spell_mess1("Ogre Chieftan slams his foe a crushing blow.");
     set_chance(15);
     set_spell_dam(10);
   }
}
