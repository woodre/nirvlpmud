inherit "/obj/monster.c";

reset(arg) {
  ::reset(arg);
  if(arg) return;
  set_name("skir");
  set_alt_name("snake");
  set_short("Skir Sithos");
  set_long(
"   Skir is a guardian of Sithos.  She stands proudly and silently ever \n"+
"vigilant against an attack upon her God.  Bright eyes shine forth from \n"+
"a helm that darkens and conceals her face.  Impressive muscular and \n"+
"womanly features are detailed by a tight wrap of dark fabric.\n"
  );
  set_gender("female");
  set_race("snake");
  set_level(19);
  set_wc(28);
  set_ac(16);
  set_hp(475);
  set_al(-200);
  set_chat_chance(3);
  load_chat("Skir says: None shall touch our Lord Sithos.\n");
  load_chat("Skir's eyes flicker in the light.\n");
  load_chat("Skir shifts between feet, keeping ready for battle.\n");
  set_dead_ob(this_object());
}

init() {
  ::init();
  add_action("pray","pray");
}
pray() {
  write("Skir doesn't allow you to Pray.\n");
  return 1;
}

monster_died(ob){
  move_object(clone_object("/players/stark/forest/obj/snakehelm.c"),this_object());
return 1;}
