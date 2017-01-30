/*
  granite_golem.c
*/

inherit "obj/monster";

reset(arg) {
  object obj;
  ::reset(arg);
  if (arg) return 0;

  set_name("granite golem");
  set_level(10);
  set_alias("golem");
  set_race("golem");
  set_short("A human-shaped granite golem");
  set_long("A human-shaped golem made of gold-streaked granite.\n");
  set_hp(425);
  set_wc(16);
  set_ac(10);
  set_al(-200);
  set_aggressive(1);
  obj=clone_object("obj/money");
  obj->set_money(200);
  move_object(obj, this_object());
  obj=clone_object("obj/key");
  obj->set_key_data("granite granitekey");
  move_object(obj, this_object());
}

heart_beat() {
  if (query_attack() && random(100 < 25)) {
    tell_room(environment(this_object()), "It slams down with both fists!\n");
    query_attack()->hit_player(16);
  }
  ::heart_beat();
}
