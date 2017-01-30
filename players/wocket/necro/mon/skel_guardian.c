inherit "/obj/monster";

reset(arg) {
   ::reset(arg);
   if (!arg) {
     set_name("Skeletal Guardian");
     set_short("Skeleton guardian");
     set_alt_name("guardian");
     set_race("undead");
     set_gender("creature");
     set_long("The darkness follows the skeleton wherever it goes, a sense\n"+
              "of death and decay about the area. The skeleton is that of\n"+
              "a human with a tattered cloak clinging to its frame.\n");
     set_level(15);
     set_ac(12);
     set_wc(18 + random(9));
     set_hp(250 + random(30));
     set_al(-1000);
     set_aggressive(1);
     set_a_chat_chance(25);
     load_a_chat("The undead thirst for the taste of the living.\n");
     load_a_chat("The chill of the afterlife has never been more real.\n");

   }
}
