/*
 * A big-ass, bad-ass crab. High ac and heal rate. Spell damage large and often.
 */

inherit "/obj/monster";
reset(arg) {
   ::reset(arg);
   if (!arg) {
 
     set_name("giant crab");
     set_short("A giant crab");
     set_race("chaoscreature");
     set_alias("crab");
     set_long(
"This is quite possibly the largest crab you have ever seen.\n"+
"Its huge reddish-black shell looks like it could withstand\n"+
"your mightiest blows while the deadly claws crush you to\n"+
"bloody fragments. This may not be an easy battle but the\n"+
"meat of giant crabs is rumored to be fabulously healthy...\n");
     set_level(20);
     set_ac(25);
     set_wc(25);
     set_hp(500);
     set_heal(3,15);
     set_al(0);
     set_aggressive(1);
     set_dead_ob(this_object());
     set_chat_chance(7);
     set_a_chat_chance(7);
 
     load_chat("The crab scuttles toward you.\n");
     load_a_chat("The crab's shell resists your blows.\n");
set_chance(40);
  set_spell_mess1(
"The Giant Crab attacks in a scuttling flurry!\n");
  set_spell_mess2(
"The Giant Crab attacks in a scuttling flurry!\n");
set_spell_dam(25);
   }
}

monster_died() {
  object crabmeat;
  crabmeat = clone_object("/players/snow/chaos/objects/crabmeat.c");
  tell_room(environment(this_object()),
            "The crab's mighty shell cracks open with a mighty\n\n"+
      "                   **SNAP**\n\n");
  move_object(crabmeat,this_object());
  return 0;
}
