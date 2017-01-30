inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
   object ob, ob2;
  ob = clone_object("/players/saber/weapons/demonwhip.c");
move_object(ob,this_object());
 ob2 = clone_object("/players/saber/gems/pearl.c");
move_object(ob2,this_object());
     set_name( "trazzik" );
     set_short("Trazzik, Keeper of Manes");
     set_race( "demon");
     set_long("A large, wicked looking winged demon wielding an evil looking whip.\n"+
        "Trazzik looks considerably more viscious than the manes it is tormenting.\n"+
        "You get the feeling that you should not attack it lightly.\n");
     set_level(14);
     set_ac(12);
     set_wc(17);
     set_hp(210);
     set_al(-600);
     set_frog(1);
     set_aggressive(0);
     set_chat_chance(20);
     set_a_chat_chance(30);
      load_chat("Trazzik says: You will be mine.\n");
      load_chat("Trazzik cracks its whip with a loud snap.\n");
      load_chat("Trazzik leers at you.\n");
      load_chat("Trazzik looks around for a Manes to torture.\n");
      load_chat("Trazzik points at you.\n");
      load_a_chat("Trazzik yells: I will feast upon your bones!\n");
      load_a_chat("Trazzik punches you across the face.\n");
      load_a_chat("Trazzik hisses at you.\n");
      load_a_chat("Trazzik says: You shall remain here in hades forever!\n");
      load_a_chat("Trazzik says: You are doomed.\n");

/* Updated to add_spell by Illarion Dec 2004
set_spell_mess1("Trazzik engulfs its foe in a column of raging fire.");
set_spell_mess2("Trazzik engulfs you in a column of raging fire.");
     set_chance(20);
     set_spell_dam(10);
*/
      add_spell("column of fire",
"#MN# engulfs you in a column of raging $HR$fire$N$!\n",
"#MN# engulfs #TN# in a column of raging $HR$fire$N$!\n",
20,10,"other|fire");
   }
}
