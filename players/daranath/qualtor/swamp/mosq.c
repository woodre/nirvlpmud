inherit "/obj/monster";

reset(arg){
  ::reset(arg);
  if (!arg){
          
     set_name("mosquito");
     set_short("A mosquito buzzies noisily overhead");
     set_alias("mosq");
     set_alt_name("critter");
     set_race("insect");
     set_gender("creature");
     set_long("An ugly insect that likes to land on warm bodied creatures and\n"+
              "suck thier blood for food, the mosquito is a common creature\n"+
              "all about Nirvana.\n");
     set_level(2);
     set_ac(3);
     set_wc(8);
     set_hp(50);
     set_al(-250);
     set_aggressive(0);
     set_chat_chance(10);
     load_chat("The mosquito buzzes annoyingly overhead.\n");
     load_chat("The swamp mosquito buzzes about you.\n");

     }
    }
