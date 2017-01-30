 inherit "/obj/monster";
  reset(arg) {
    ::reset(arg);
    if (!arg) {
  object ob,ob2;
    ob2 = clone_object("/players/arrina/weapons/longknif.c");
 move_object(ob2,this_object());
  ob = clone_object("/players/arrina/armor/bonering.c");
 move_object(ob,this_object());
       set_name("sentry");
      set_short("A Sentry");
      set_race( "human");
      set_long("An powerful looking sentry.  He has a haunted look \n"+
        "in his eyes and appears unhappy with you.\n");
      set_level(13);
      set_ac(8);
      set_wc(17);
      set_hp(220);
      set_al(-900);
      set_aggressive(0);
      set_chat_chance(20);
      set_a_chat_chance(25);
       load_chat("Sentry says: You come to a place of death.\n");
      load_chat("Sentry says: Consider your fate and go back.\n");
      load_chat("Sentry says: This place harbors evil, go back.\n");
      load_chat("Sentry says: Only death lurks here.\n");
       load_a_chat("Sentry says: I tried to warn you, you did not heed.\n");
      load_a_chat("Sentry says: No good can come of my defeat.\n");
    }
 }
