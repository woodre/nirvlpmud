inherit "/obj/monster.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("trasz");
  set_alt_name("snake");
  set_short("Trasz Sithos");
  set_long(
"   Trasz is a warrior of the Tribe of Sithos.  Slick scaly skin covers \n"+
"his frame.  His head is like that of a snake, with eyes of fiery red.  \n"+
"He boasts a dark platemail with the etchings of a snake.  Loose black \n"+
"fabric winds it's way down towards his ankles, met by wooden sandals.\n"
  );
  set_gender("male");
  set_race("snake");
  set_level(17);
  set_wc(24);
  set_ac(14);
  set_hp(425);
  set_al(-100);
  set_chat_chance(3);
  load_chat("Trasz buffs his hand against his platemail.\n");
  load_chat("Trasz asks: What are you doing down here?\n");
  load_chat("Trasz adjusts his sandles.\n");
  set_dead_ob(this_object());
}

monster_died(ob){
  move_object(clone_object("/players/stark/forest/obj/17plate.c"),this_object());
return 1;}
