
inherit "/obj/monster";
 
reset(arg) {
   ::reset(arg);
   if (!arg) {
 
     set_name("troglodyte guard");
     set_short("Troglodyte Guard");
     set_race( "troglodyte");
     set_alias("guard");
    set_long(
"\tYou gaze upon a hideous, slimy, green creature.\n"+
"Its arms writh erratically while its long claws drip green venom.\n"+
"Despite its ferocious armament, the troglodyte guard looks\n"+
"rather fragile in constitution.\n");
     set_level(16);
     set_ac(random(5) + 5);
     set_wc(55 + random(20));
     set_hp(65+random(50));
     set_heal(1,5);
     set_al(-1000);
     set_aggressive(1);
     set_a_chat_chance(7);
     load_a_chat("The Troglodyte Guard screams violently!\n");
     load_a_chat("The Troglodyte Guard lunges at you!\n");
   }
}

heart_beat() {
  object def, meat;
  ::heart_beat();
  def = present("king", environment(this_object()));
  if(def) meat = def->query_attack();
  if(meat && query_attack() != meat) attack_object(meat);
  if(!random(5)) { already_fight=0; attack(); }
}
