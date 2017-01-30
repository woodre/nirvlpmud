inherit "/obj/monster";

reset(arg) {
  object gold;
   ::reset(arg);
   if (!arg) {

     set_name("Sand Viper");
     set_short("Sand Viper");
     set_alias("viper");
     set_alt_name("sand viper");
     set_race("serpent");
     set_gender("creature");
     set_long("A large snake, the Sand Viper has alternating light and\n"+
              "dark colored bands running the length of its serpentine\n"+
              "body. An extremely poisonous monster.\n");
     set_level(15);
     set_ac(12);
     set_wc(19 + random(4));
     set_hp(200 + random(50));
     set_al(-1000);
     set_aggressive(0);
     set_chat_chance(5);
     load_chat("The sand viper slithers across the sandy ground.\n");

     set_spell_mess2("Sand Viper strikes swiftly at you.\n");
     set_spell_mess1("Sand Viper strikes with its deadly bite.\n");
     set_chance(10);
     set_spell_dam(60);

     gold = clone_object("obj/money");
     gold->set_money(random(100)+825);
     move_object(gold,this_object());
   }
  }

