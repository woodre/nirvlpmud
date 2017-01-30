inherit "/obj/monster.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("par");
  set_alt_name("snake");
  set_short("Par Sithos");
  set_long(
"   Par is a warrior of the Tribe of Sithos.  He proudly thrusts his \n"+
"platemail of Sithos whichever direction he faces.  Fiery red eyes are \n"+
"outstaged by a wide scar leading to his fangs.  Loose fabric drops \n"+
"down from his waist to wrap around his feet.\n"
  );
  set_gender("male");
  set_race("snake");
  set_level(18);
  set_wc(26);
  set_ac(15);
  set_hp(450);
  set_al(-200);
  set_chat_chance(3);
  load_chat("Par buffs his hand against his platemail.\n");
  load_chat("Par asks: What are you doing down here?\n");
  load_chat("Par traces the path of his large scar with his finger.\n");
  set_dead_ob(this_object());
}

monster_died(ob){
  move_object(clone_object("/players/stark/forest/obj/18plate.c"),this_object());
return 1;}
