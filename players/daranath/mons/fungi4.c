inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

   move_object(clone_object("/players/daranath/weps/fungi_club.c"),this_object());

     set_name("myconid");
     set_short("Myconid Shaman");
     set_race("fungus");
     set_alias("shaman");
     set_gender("creature");
     set_long("The Myconid resembles a walking toadstool in human form.\n"+
              "Its flesh is bloated and spongy, and it varies in splotchy\n"+
              "colors ranging from purple to gray. Its wide feet has\n"+
              "vestigal toes and its pudgy hands have two stubby fingers\n"+
              "and a thumb on either side.\n");
     set_level(10);

     init_command("wear armor");
     init_command("wield weapon");

     set_ac(8);
     set_wc(14);
     set_hp(150 + random(40));
     set_al(-270);
     set_aggressive(0);
     set_chat_chance(12);
     set_a_chat_chance(30);
     load_chat("The fungal priest chants in a strange clicking toungue.\n");
     load_chat("The fungal priest speaks in a clicking, chittery toungue.\n");
     load_a_chat("Spores emit from the fungal priest.\n");
     load_a_chat("The priest swings a bone club at you.\n");

   }
}
