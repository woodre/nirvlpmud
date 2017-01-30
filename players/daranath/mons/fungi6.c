inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

   move_object(clone_object("/players/daranath/weps/king_blade.c"),this_object());


     set_name("myconid");
     set_short("Myconid King");
     set_race("fungus");
     set_alias("king");
     set_gender("creature");
     set_long("The Myconid resembles a walking toadstool in human form.\n"+
              "Its flesh is bloated and spongy, and it varies in splotchy\n"+
              "colors ranging from purple to gray. Its wide feet has\n"+
              "vestigal toes and its pudgy hands have two stubby fingers\n"+
              "and a thumb on either side. The Myconid King stands\n"+
              "several feet taller then the rest of the warriors here. He\n"+
              "wields a pair of bastard swords, one in each stubby hand.\n");
     set_level(15);

     init_command("wield weapon");
     init_command("wear armor");

     set_ac(18);
     set_wc(25);
     set_hp(450 + random(100));
     set_al(-750);
     set_aggressive(0);
     set_chat_chance(20);
     set_a_chat_chance(45);
     load_chat("The fungal king stares at you with an empty glare.\n");
     load_chat("The fungal king speaks in a loud, commanding voice.\n");
     load_a_chat("The fungal king rises above you to attack.\n");
     load_a_chat("The Myconid clubs you with its powerful, stubby arms.\n");
     load_a_chat("The fungal king attacks with his powerful, slashing swords.\n");
     load_a_chat("The swords of the king shine in the glow of the flame.\n");
     load_a_chat("The fungal king cuts deeply with his blades.\n");
     load_a_chat("The hut itself seems to anticipate the outcome of the fight.\n");

   }
}
