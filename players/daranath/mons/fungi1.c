inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

     set_name("violet");
     set_short("Violet Fungal Growth");
     set_race("fungus");
     set_gender("creature");
     set_long("The Violet Fungus resemble a large toadstool, with an\n"+
              "overgrown foot at its base. It crawls about everywhere using\n"+
              "this 'foot' and seems to follow you as you move about.\n"+
              "Four branches extend from its trunk, lashing about in a\n"+
              "random fashion.\n");
     set_level(5);
     set_ac(5);
     set_wc(9);
     set_hp(90 + random(40));
     set_al(-50);
     set_aggressive(0);
     set_chat_chance(5);
     set_a_chat_chance(30);
     load_chat("The violet fungus moves a bit torwards you.\n");
     load_a_chat("The fungus lashes out with its branches.\n");
     load_a_chat("The fungus unleashes a violet spore cloud at you.\n");

   }
}
