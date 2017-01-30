inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {

object gold;
  gold = clone_object("/players/saber/food/eggs.c");
  move_object(gold,this_object());

     set_name("viper");
     set_short("A black viper");
     set_race( "snake");
     set_gender("creature");
     set_long("A lightning quick black viper.\n"+
          "It's fangs drip with poison.\n");
     set_level(4);
     set_ac(4);
     set_wc(8);
     set_hp(60);
     set_al(-71);
     set_aggressive(1);
     set_chat_chance(15);
     set_a_chat_chance(15);
     load_chat("The viper looks up at you.\n");
     load_chat("The viper coils menacingly at you.\n");
     load_chat("The viper slithers across the room.\n");
     load_a_chat("The viper lunges in your direction.\n");
     set_spell_mess1("The viper strikes like lightning at its foe.");
     set_spell_mess2("The viper strikes like lightning, biting you!");
     set_chance(15);
     set_spell_dam(10);
   }
}

