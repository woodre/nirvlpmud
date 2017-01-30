inherit "/obj/monster";

reset(arg){
  ::reset(arg);
  if (!arg){
          
     set_name("Ghost of Ariel");
     set_short("Ghostly form of Ariel");
     set_alias("ariel");
     set_alt_name("ghost");
     set_race("undead");
     set_gender("female");
     set_long("The ghost of a beautiful woman, Ariel once lived here within\n"+
              "the crystal tower. She was killed during the severe fighting\n"+
              "all about the city, beaten badly by several necromancers\n"+
              "Now Ariel haunts this area, unwilling to leave the\n"+
              "mortal realm, for she believes her life purpose has\n"+
              "not been fulfilled.\n");
     set_level(18);
     set_ac(15);
     set_wc(29);
     set_hp(450);
     set_al(1000);
     set_aggressive(0);
     set_chat_chance(10);
     set_a_chat_chance(10);
     load_chat("A chilling breeze fills the small chamber.\n");
     load_chat("The ghost seems to try to speak to you....\n");
     load_a_chat("The Ghost howls in pain.\n");

     }
    }
