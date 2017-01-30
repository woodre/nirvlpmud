inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
     set_name( "alchemist" );
     set_alias("alch");
     set_short("A whimpering Alchemist");
  set_long("A fierce looking alchemist - remember loks can be decieveing!\n");
     set_level(2);
     set_ac(3);
     set_wc(6);
     set_hp(300);
     set_al(-80);
     set_aggressive(0);
     set_chat_chance(1);
     set_a_chat_chance(20);
  load_chat("An Alch cusses at You!\n");
  load_chat("Alch threatens You!\n");
  load_chat("Alch says 'Set your PK you little wimp!'\n");
  load_chat("Alch says 'I'll kill you and your three best friends!'\n");
   load_a_chat("Alch says'Dont hurt me! I'll do anything you want!'\n");
   load_a_chat("Alch starts balling and tries to run away!\n");
    load_a_chat("Alch says 'this isnt fair! I wasnt ready yet!'\n");
     money = (60);
   }
}

