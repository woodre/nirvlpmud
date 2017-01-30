inherit "/obj/monster";
 
reset(arg) {
   ::reset(arg);
   if (!arg) {

     set_name("cave bear");
     set_short("A huge brown bear");
     set_race( "bear");
     set_alias("bear");
     set_long("This is a huge cave bear. Unfortunately for you,\n" +
                  "you have entered its lair. It looks hungry... \n");
     set_level(20);
     set_ac(10+ random(10));
     set_wc(25 + random(20));
     set_hp(600+random(300));
     set_al(-500);
     set_aggressive(1);
     set_chat_chance(7);
     set_a_chat_chance(7);
     load_chat(".The cave bear growls threateningly.\n");
     load_chat("The cave bear walks toward you, sniffing your scent.\n");
     load_a_chat("The cave bear's eyes glow bright red.\n");
     load_a_chat("The cave bear goes into a killing frenzy.\n");
   }
}
