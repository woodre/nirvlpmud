inherit "/obj/monster";

reset(arg) {
   object gold;
   ::reset(arg);
   if (!arg) {
     set_name("undead serpent");
     set_alt_name("serpent");
     set_short("Undead Swamp Serpent");
     set_race("undead");
     set_gender("creature");
     set_long("The smell of decay assaults your sense of smell as you\n"+
              "gaze upon the huge serpent. The snake rises about 10 feet into\n"+
              "the air to tower over you. Its flesh hangs loosly about its\n"+
              "gaunt frame. Large, white fangs drip with a venom that cannot\n"+
              "be very good for you.\n");
     set_level(19);
     set_ac(15+ random(4));
     set_wc(27 + random(4));
     set_hp(500 + random(100));
     set_al(-850);
     set_aggressive(0);
     set_chat_chance(10);
     set_a_chat_chance(20);
     load_chat("The death serpent rises from the water to tower over you.\n");
     load_a_chat("The serpent strikes at you with its fangs.\n");
     load_a_chat("The serpent strikes at you with its boney tail.\n");
     load_a_chat("The serpent hisses: Bother ssssomeone elsssse.....\n");
     load_a_chat("The undead thirst for the taste of the living.\n");
     load_a_chat("The chill of the afterlife has never been more real.\n");

     gold = clone_object("obj/money");
     gold->set_money(random(2000)+ 1000);
     move_object(gold,this_object());

   }
}
