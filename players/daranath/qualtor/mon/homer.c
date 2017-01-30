inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

move_object(clone_object("/players/daranath/qualtor/obj/homer_smock.c"),this_object());
move_object(clone_object("/players/daranath/qualtor/wep/dirty_rag.c"),this_object());

     set_name("Homer Homestead");
     set_short("A man wipes down the bar");
     set_alias("man");
     set_alt_name("homer");
     set_race("human");
     set_gender("male");
     set_long("Homer Homestead is a golly fat man who has helped to\n"+
              "rebuild the Black Rose Tavern within Qual'tor. he belives\n"+
              "that the city can be rebuilt, with both a lot of hard\n"+
              "work, and your golden coin spent here.\n");
     set_level(12);

     init_command("wield rag");
     init_command("wear smock");

     set_ac(9);
     set_wc(15 + random(4));
     set_hp(180 + random(20));
     set_al(700);
     set_aggressive(0);
     set_chat_chance(4);
     set_a_chat_chance(25);
     load_chat("Homer whistles a soft tune as he cleans another glass.\n");
     load_chat("Homer chuckles as he remembers customers from long ago.\n");
     load_chat("Homer says: Good day adventurers!!!  What could I get for you!.\n");
     load_chat("Homer sneaks a sly look at one of the barmaids.\n");
     load_chat("Homer says: Try the draft, it fabulous today.\n");
     load_chat("Homer says: Open Faced Sandwich..... MmmMmMMmmm...\n");
     load_chat("Homer whistles a merry little tune while he works.\n");
     load_a_chat("Homer Homestead grabs a bottle and breaks it over your head.\n");
     load_a_chat("Homer pleads: Why are you doing this?\n");

   }
}
