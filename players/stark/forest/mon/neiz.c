inherit "/obj/monster.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("neiz");
  set_alt_name("snake");
  set_short("Neiz Sithos");
  set_long(
"   Neiz is a worker in the Tribe of Sithos.  Wide arms and legs set \n"+
"him far apart from the rest of his Tribe.  Wide red eyes are placed \n"+
"closer together atop his snake like head.  His strength is shown in \n"+
"each and every movement.  Draped fabric creates a long black tunic \n"+
"down his body.\n"
  );
  set_gender("male");
  set_race("snake");
  set_level(16);
  set_wc(23);
  set_ac(13);
  set_hp(400);
  set_al(-100);
  set_chat_chance(3);
  load_chat("Neiz checks the wall for where to dig next.\n");
  load_chat("Neiz remarks:  I can put my entire body into digging for Lord Sithos.\n");
  load_chat("Neiz stretches briefly and smiles as he looks at his work.\n");
  set_dead_ob(this_object());
}

monster_died(ob){
write("\nYou brutally rip a layer of skin off of the falling body!\n\n");
  move_object(clone_object("/players/stark/forest/obj/16skin.c"),this_object());
return 1;}
