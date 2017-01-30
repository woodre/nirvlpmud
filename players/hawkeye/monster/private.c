inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
     set_name( "private" );
     set_alias("private");
     set_short("A Private");
    set_long("This is a measly private...looks pretty weak.\n");
     set_level(1);
/* with 0 ac and 0 wc level changed from 5 to 0 -Bp */
/* because the level 0 thing was causing bugs i changed the stats to level 1 - mythos <11-7-97> */
     set_ac(5);
     set_wc(7);
     set_hp(40);
     set_al(-45);
     money = (30);
     set_aggressive(0);
     set_chat_chance(1);
     set_a_chat_chance(20);
    load_chat("One of the Privates says 'Go away..we're busy.\n");
       load_chat("The privates shoot at snipers.\n");
    load_chat("One of the Privates hides behind a tree.\n");
    load_chat("The privates says, 'You're a putz'\n");
    load_a_chat("Private says 'Hey Buddy!'\n");
    load_a_chat("The Private taunts you.\n");
    load_a_chat("A Private pokes you in the ribs..\n");
    load_a_chat("A private points at you and laughs!\n");
   }
}

