inherit "/obj/monster.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("hidz");
  set_alt_name("snake");
  set_short("Hidz Sithos");
  set_long(
"   Hidz is a worker in the Tribe of Sithos.  He has a thin build for \n"+
"his race, like that of a normal snake.  His red eyes seem less proud \n"+
"and more tired than the rest.  Tattered black fabric has been spun \n"+
"around his chest down to his waist."
  );
  set_gender("male");
  set_race("snake");
  set_level(16);
  set_wc(20);
  set_ac(14);
  set_hp(400);
  set_al(-100);
  set_chat_chance(3);
  load_chat("Hidz sighs and slumps against a wall.\n");
  load_chat("Hidz mumbles to himself.\n");
  load_chat("Hidz stretches his arms and rubs his muscles.\n");
  set_dead_ob(this_object());
}

monster_died(ob){
write("\nThe tattered fabric falls apart onto the floor.\n\n");
  move_object(clone_object("/players/stark/forest/obj/16tattered.c"),this_object());
return 1;}
