inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
object ob, ob2, gold;
gold = clone_object("obj/money");
gold->set_money(750);
move_object(gold,this_object());
  ob = clone_object("/players/saber/weapons/tree.c");
move_object(ob,this_object());
 ob2 = clone_object("/players/saber/armor/fuzjacket.c");
move_object(ob2,this_object());
init_command("wield tree");
     set_name( "ogre" );
   set_short("A large Ogre");
     set_race( "ogre");
   set_long("A large, ugly humaniod standing ten feet tall with dead yellow skin and long,\n"+
       "greasy hair.  It has purple eyes with white pupils.  The ogre is covered with\n"+
        "dark brown warts, and has dark black teeth.\n");
     set_level(19);
     set_ac(14);
     set_wc(28);
     set_hp(500);
     set_al(-600);
     set_aggressive(1);
     set_a_chat_chance(18);
     load_a_chat("Ogre bellows: Kill small critter fast, before SHE return...\n");
     load_a_chat("Ogre bellows: Small critter die!\n");

     set_spell_mess2("Ogre slams you with a huge fist.");
     set_spell_mess1("Ogre slams his foe with a huge fist.");
     set_chance(15);
     set_spell_dam(10);
   }
}
