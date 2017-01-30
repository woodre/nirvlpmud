inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
     set_name("iron beetle");
     set_alt_name("beetle");
     set_short("Iron Beetle");
     set_race( "insect");
     set_gender("creature");
     set_long("The beetle has a hardened shell made of scrap pieces of\n"+
              "iron that were scavenged from kills and corpses about. A\n"+
              "pair of nasty looking horns stick out from the front of\n"+
              "the critter, making it look very mean.\n");
     set_level(11);
     set_ac(26);
     set_wc(10 + random(4));
     set_hp(125 + random(30));
     set_al(-500);
     set_aggressive(0);
     set_a_chat_chance(25);
     load_a_chat("Iron Beetle makes a loud scratching noise as it brushes the wall.\n");
     load_a_chat("Iron Beetle charges with its horns.\n");
     load_a_chat("Iron Beetle spears you with a horn.\n");

   }
}
