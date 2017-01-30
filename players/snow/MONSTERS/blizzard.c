inherit "/obj/monster";
 
reset(arg) {
   ::reset(arg);
   if (!arg) {
 
     set_name("blizzard");
     set_short("A living blizzard");
     set_race("elemental");
     set_alias("blizzard");
     set_long("This is a blizzard made of living ice crystals. It only appears \n" +
                    "when the Wizard Snow is VERY angry.\n" +
                    "How unfortunate for you.\n");
     set_level(100);
     set_ac(100);
     set_wc(100);
     set_hp(10000);
     set_al(1000);
     set_aggressive(1);
     set_chat_chance(7);
     set_a_chat_chance(7);
     load_chat("You have brought about your own doom, mortal.\n");
     load_a_chat("I only do this for your own good.\n");
     load_a_chat("Maybe next time you will remember who you are dealing \n" + 
                          "with.\n");
set_chance(35);
set_spell_mess1("The blizzard sends thousands of living ice crystals into \n" +
                            "its foolish foe.\n");
set_spell_mess2("You are shredded by living ice crystals as the blizzard \n" + 
                            "vents its wrath upon you.\n");
set_spell_dam(200);
   }
}
 
