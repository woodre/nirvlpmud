inherit "/obj/monster.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("snake");
  set_alt_name("snake");
  set_short("Large Snake");
  set_long(
"   Slick and scaly skin covers this curving trap.  Its skin is wrapped \n"+
"in green with black arrows scattered about.  It would seem to be more \n"+
"than three meters in length, but in its current curled state it's hard \n"+
"to tell.  Since it has recently been ripped from its slumber, it \n"+
"seems very angry.\n"
  );
  set_gender("male");
  set_race("snake");
  set_level(14);
  set_wc(20);
  set_ac(10);
  set_hp(220);
  set_al(-100);
  set_aggressive(1);
  set_chat_chance(5);
  load_chat("The snake slithers around...\n");
  set_dead_ob(this_object());
}

monster_died(ob){
write("\nYou take the fallen snake and skin it!\n\n");
  move_object(clone_object("/players/stark/forest/obj/14skin.c"),this_object());
return 1;}