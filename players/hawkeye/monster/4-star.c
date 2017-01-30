inherit "/obj/monster";
object ob;

reset(arg) {
   ::reset(arg);
   if (!arg) {
     set_name( "general" );
     set_alias("general");
     set_short("A General");
set_long("Noticing 4 stars on this particular general you\n"+
         "start to get weak in the knees and feel the need\n"+
         "to salute.\n");
     set_level(19);
     set_ac(17);
     set_wc(30);
     set_hp(400);
     set_al(0);
  ob = clone_object("/players/hawkeye/items/stars.c");
move_object(ob, this_object());
     set_aggressive(0);
     set_whimpy();
     set_chat_chance(1);
     set_a_chat_chance(20);
     load_chat("The General says 'Don't touch me!'\n");
     load_chat("The General says 'Do i see a salute?'\n");
    load_a_chat("General says 'Hey Buddy! Drop and give me 20.'\n");
    load_a_chat("The General knows he is superior.\n");
    load_a_chat("The General points at you and laughs!\n");
/* Changed from 4800 to 1500 to reflect level  -Snow */
     money = (1500 + random(500));
   }
}

