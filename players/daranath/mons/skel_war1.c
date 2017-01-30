inherit "/obj/monster";

reset(arg) {
  object gold;
   ::reset(arg);
   if (!arg) {
     set_name("skeleton");
     set_alias("secret secret alias thingy");
     set_short("Skeleton Warrior");
     set_race("undead");
     set_gender("creature");
     set_long("The darkness follows the skeleton wherever it goes, a sense\n"+
              "of death and decay about the area. The skeleton is that of\n"+
              "a human with a tattered cloak clinging to its frame.\n");
     set_level(15);
     set_ac(12);
     set_wc(16 + random(9));
     set_hp(250 + random(30));
     set_al(-1000);
     set_aggressive(1);
     set_a_chat_chance(25);
     load_a_chat("The undead thirst for the taste of the living.\n");
     load_a_chat("The chill of the afterlife has never been more real.\n");
     load_a_chat("The skeleton howls: Protect the Warlord.\n");

     gold = clone_object("obj/money");
     gold->set_money(random(400) + 800);
/* average coins of 1000 per monster guide */
     move_object(gold,this_object());
   }
}
