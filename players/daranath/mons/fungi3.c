inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

     set_name("myconid");
     set_short("Myconid Commoner");
     set_race("fungus");
     set_alias("commoner");
     set_gender("creature");
     set_long("The Myconid resembles a walking toadstool in human form.\n"+
              "Its flesh is bloated and spongy, and it varies in splotchy\n"+
              "colors ranging from purple to gray. Its wide feet has\n"+
              "vestigal toes and its pudgy hands have two stubby fingers\n"+
              "and a thumb on either side.\n");
     set_level(7);
     set_ac(6);
     set_wc(11);
     set_hp(100 + random(40));
     set_al(-100);
     set_aggressive(0);
     set_chat_chance(15);
     set_a_chat_chance(30);
     load_chat("The fungus man stares at you with an empty glare.\n");
     load_chat("The fungus man speaks in a clicking, chittery toungue.\n");
     load_a_chat("Spores emit from the fungal commoner.\n");
     load_a_chat("The fungus man retracts from your visicous attack.\n");

   }
}
