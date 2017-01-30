inherit "/obj/monster.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("snake");
  set_alt_name("snake");
  set_short("Small Snake");
  set_long(
"   The snake is only a meter in length and an inch wide.  The snake is \n"+
"nearly harmless for its variety.  Its scaly structure is green with \n"+
"dotted black arrows.  It seems rather agitated at it's current state \n"+
"in life.\n"
  );
  set_gender("male");
  set_race("snake");
  set_level(14);
  set_wc(20);
  set_ac(10);
  set_hp(210);
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