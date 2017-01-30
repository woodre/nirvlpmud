inherit "/obj/monster";
 
reset(arg) {
   ::reset(arg);
   if (!arg) {
 
     set_name("guardian");
     set_short("A small white bear");
     set_race( "bear");
     set_alias("runt");
     set_long(
"This is a polar bear runt. It is weak for its kind but nothing to be taken\n"+
"lightly. If you can defeat this easily, you have a good chance to live in\n"+
"the tundra...\n");
     set_level(16);
     set_ac(5+ random(5));
     set_wc(15 + random(10));
     set_hp(300 + random(100));
     set_heal(2,1);
     set_al(0);
     set_aggressive(0);
     set_chat_chance(3);
     set_a_chat_chance(3);
     load_chat(".The bear raises his bloodsoaked claws.\n");
     load_chat("The Polar Bear bares its teeth, saliva running down its jowls.\n");
     load_a_chat("The bear cringes and whines.\n");
set_chance(10);
set_spell_mess1("The polar bear swats its victim with a mighty paw.\n");
set_spell_mess2("The polar bear crunches your chest with a swing of its \n" + 
                            "mighty paw.\n");
set_spell_dam(15);
   }
}
 
