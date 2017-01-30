inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
     set_name( "large golem" );
     set_alias("golem");
      set_short("A large black golem");
     set_race( "golem");
     set_long("A huge black golem with features of stone.\n"+
        "It appears to have something to say.\n");
     set_level(15);
     set_ac(14);
     set_wc(17);
     set_hp(400);
     set_al(150);
     set_heal(3,25);
     set_aggressive(0);
     set_chat_chance(25);
     set_a_chat_chance(35);
     load_chat("Golem says: Go west to the Tower of Portals.\n");
     load_chat("Golem says: Ryllian is the City of Eternal Night.\n");
     load_chat("Golem says: Ryllian is the City of 1001 Pleasures.\n");
     load_chat("Golem says: Orin's Inn can be found in Ryllian.\n");
     load_chat("Golem says: Go west to the Tower of Portals.\n");
     load_chat("Golem watches the area for hostile monsters.\n");
     load_chat("The breeze tugs gently at your hair.\n");
     load_chat("The breeze tugs gently at your hair.\n");
     load_a_chat("Golem yells: You scum!\n"+
         "Now you will die!\n");
     load_a_chat("Golem yells: Help!  Call the city guards!\n");
     load_a_chat("Golem glares at you.\n");

     set_spell_mess2("The golem punches you in the face.\n");
     set_spell_mess1("The golem punches its opponent in the face.\n");
     set_chance(25);
     set_spell_dam(15);
   }
}
