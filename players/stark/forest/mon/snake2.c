inherit "/obj/monster.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("snake");
  set_alt_name("snake");
  set_short("Snake");
  set_long(
"   Brown lines circle down the mostly green covering of this snake.  \n"+
"The fangs of this vine like creature seem tiny and harmless.  Its \n"+
"powerful and long body seems quite the opposite.  It may look for \n"+
"something to wrap around since the tree branch is no longer an option.\n"
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