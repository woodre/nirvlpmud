inherit "/obj/monster";
 
reset(arg) {
   ::reset(arg);
   if (!arg) {
 
object gold;
  gold = clone_object("obj/money");
  gold->set_money(random(2000) + 1000);
  move_object(gold,this_object());
 
     set_name("guardian");
     set_short("A demon of the icy wastes");
     set_race( "spirit");
     set_alias("demon");
     set_long("This demon stands a good 18 feet tall with eight-inch, razor-\n" + 
                    "sharp claws protruding from each of its twelve fingers per hand.\n" + 
                    "The opaque crystal scales covering this demon reveal what \n" + 
                    "look to be fiery-blue organs inside. The demon moves with the \n" + 
                    "quiet grace of an experienced killer. As it gazes deep into your \n" + 
                    "soul you start to shake with fear you have never known before. \n");
     set_level(18);
     set_ac(15 + random(15));
     set_wc(20 + random(15));
     set_hp(400 + random(200));
     set_heal(15,7);
     set_al(-1000);
     set_aggressive(0);
     set_chat_chance(7);
     set_a_chat_chance(7);
     load_chat("The demon looks at you with baleful eyes.\n");
     load_chat("A blue fire glows on the demon's claws.\n");
     load_a_chat("The demon rips at your soul.\n");
     load_a_chat("The demon seems to grow stronger.\n");
set_chance(20);
set_spell_mess1("The demon rips deep into the flesh of its victim. The \n" + 
                            "demon licks the dripping blood from its claws.\n");
set_spell_mess2("The demon rips deep into your flesh. The demon licks \n" + 
                            "your dripping blood from its claws.\n");
set_spell_dam(20);
   }
}
 
