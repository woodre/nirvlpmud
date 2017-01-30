inherit "/obj/monster.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("sheeh");
  set_alt_name("snake");
  set_short("Sheeh Sithos");
  set_long(
"   Sheeh is a young member of the Tribe of Sithos, her womanly form \n"+
"still dormant in what seems to be her early teens.  Slick ruby eyes \n"+
"dart curiously about the room.  Shiny black fabric has been fitted \n"+
"into a long dress.\n"
  );
  set_gender("female");
  set_race("snake");
  set_level(15);
  set_wc(20);
  set_ac(12);
  set_hp(230);
  set_al(200);
  set_chat_chance(3);
  load_chat("Sheeh stares off into the fire.\n");
  load_chat("Sheeh fixes her dress.\n");
  load_chat("Sheeh sighs and says: When are they going to take me training?!\n");
  set_dead_ob(this_object());
}

monster_died(ob){
  move_object(clone_object("/players/stark/forest/obj/dress.c"),this_object());
return 1;}
