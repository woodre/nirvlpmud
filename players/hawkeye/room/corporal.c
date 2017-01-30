inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
     set_name( "corporal" );
     set_alias("corporal");
     set_short("A Corporal");
       set_long("This is a corporal in the army..might be a challenge.\n");
     set_level(9);
     set_ac(6);
     set_wc(13);
     set_hp(100);
     set_al(99);
     set_aggressive(0);
     set_chat_chance(1);
     set_a_chat_chance(20);
    load_chat("One of the Corporals says 'Go away..we're busy.\n");
       load_chat("The corporals shoot at snipers.\n");
    load_chat("One of the Corporals hides behind a tree.\n");
    load_chat("The corporals says, 'Your a putz'\n");
    load_a_chat("Corporal says 'Hey Buddy!'\n");
    load_a_chat("The Corporal taunts you.\n");
    load_a_chat("A Corporal pokes you in the ribs..\n");
    load_a_chat("A corporal points at you and laughs!\n");
     money = (275);
   }
}

