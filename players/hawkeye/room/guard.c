inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
     set_name( "guard" );
     set_alias("guard");
     set_short("Captain's Guard");
    set_long("This is one of the Captain's Guard...he looks pretty tough.\n");
     set_level(15);
     set_ac(5);
     set_wc(20);
     set_hp(300);
     set_al(-50);
     set_aggressive(0);
     set_chat_chance(1);
     set_a_chat_chance(20);
    load_chat("One of the Guards says 'You aren't allowed in here!.\n");
    load_chat("The Guards play poker(and all of them are cheating).\n");
    load_chat("One of the Guards pokes you with his sword.\n");
    load_chat("The guards says, 'You will perish here!'\n");
    load_a_chat("Guard says 'Hey Buddy!'\n");
    load_a_chat("The Guard taunts you.\n");
    load_a_chat("A Guard yells 'You can't go up there!.\n");
    load_a_chat("A guard points at you and laughs!\n");
     money = (850);
   }
}

