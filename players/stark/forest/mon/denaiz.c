inherit "/obj/monster.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("denaiz");
  set_alt_name("snake");
  set_short("Denaiz Sithos");
  set_long(
"   Denaiz is a young member of the Tribe of Sithos.  The Sithos are a \n"+
"race of snake people.  Their bodies are much like that of a human.  Their \n"+
"skin however are the same slick scales of a snake.  Their eyes seem to \n"+
"contain actual fire as they flicker red.  They have no pupils but more \n"+
"of a concentration of the fire.  Denaiz's absence of strong muscles is \n"+
"made up for in his determination.  A long shirt of black fabric droops \n"+
"down to his feet.\n"
  );
  set_gender("male");
  set_race("snake");
  set_level(15);
  set_wc(20);
  set_ac(12);
  set_hp(235);
  set_al(200);
  set_chat_chance(3);
  load_chat("Denaiz says:  None shall pass.\n");
  load_chat("Denaiz leans against a wall.\n");
  load_chat("Denaiz paces back and forth at the enterance.\n");
  set_dead_ob(this_object());
}

monster_died(ob){
write("\nYou rip the skin off of the young boy!\n\n");
  move_object(clone_object("/players/stark/forest/obj/15skin.c"),this_object());
return 1;}
