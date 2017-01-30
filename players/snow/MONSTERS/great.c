inherit "/obj/monster";
 
reset(arg) {
   ::reset(arg);
   if (!arg) {
 
object gold;
  gold = clone_object("obj/money");
  gold->set_money(random(15000) + 10000);
  move_object(gold,this_object());
 
     set_name("icingdeath");
     set_short("An elder frost dragon");
     set_race( "dragon");
     set_alias("frost dragon");
     set_long("An elder dragon. He still possesses a gleam in his eye \n" +
                    "and his claws look extremely dangerous. \n");
     set_level(500);
     set_ac(7500+ random(15));
     set_wc(8000 + random(25));
     set_hp(400000 + random(2000));
     set_heal(2000,1);
     set_al(1000);
     set_aggressive(0);
     set_chat_chance(7);
     set_a_chat_chance(7);
     load_chat("The dragon looks at you with judging eyes.\n");
     load_chat("The dragon nods off to sleep.\n");
     load_a_chat("Icingdeath wheezes: 2000 years ago you would already \n" +
                         "have been my lunch!\n");
     load_a_chat("Icingdeath rips his claws through your intestines.\n");
  set_chance(25);
  set_spell_mess1("Icingdeath breaths a whirling storm of ice onto his foes! \n");
  set_spell_mess2("Icingdeath breaths a cloud of ice crystals ripping \n" +
                              "through your body! \n");
     set_spell_dam(5000);
   }
}
