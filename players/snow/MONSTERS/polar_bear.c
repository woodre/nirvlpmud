inherit "/obj/monster";
 
reset(arg) {
   ::reset(arg);
   if (!arg) {

     set_name("Polar Bear");
     set_short("A huge white bear");
     set_race( "bear");
     set_alias("polar bear");
    set_long(
"This is a huge bear, perhaps the largest you have ever seen. Its paws look\n"+
"like they could tear you apart in a friendly game. This bear does not look\n"+
"friendly...\n");
     set_level(20);
     set_ac(5+ random(5));
     set_wc(20 + random(15));
     set_hp(600 + random(200));
     set_heal(5,1);
     set_al(0);
     set_aggressive(1);
      set_chat_chance(7);
     set_a_chat_chance(7);
     load_chat(
"The huge bear advances toward you, bones crunching under its huge bulk.\n");
     load_chat(
"The polar bear growls, saliva running down its jowls.\n");
     load_a_chat(
"The bear shrugs off your feeble blows.\n");
     load_a_chat(
"You watch in horror as the bear's minor wounds begin to close.\n");
set_chance(40);
set_spell_mess1("The polar bear swats its victim with a mighty paw.\n");
set_spell_mess2(
"The bear crushes your chest with a swat from its huge paw.\n");
set_spell_dam(25);
  set_dead_ob(this_object());
   }
}

monster_died() {
  object hide;
  hide = clone_object("/players/snow/closed/q/polar_hide.c");
  move_object(hide, this_object());
  return 0;
}
