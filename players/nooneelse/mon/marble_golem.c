/*
  marble_golem.c
*/

inherit "obj/monster";

reset(arg) {
  object obj;
  if (arg) return 0;
  ::reset();

  set_name("marble golem");
  set_level(10);
  set_alias("golem");
  set_race("golem");
  set_short("A human-shaped marble golem");
  set_long("A human-shaped golem made of gold-streaked marble.\n");
  set_hp(425);
  set_wc(16);
  set_ac(10);
  set_al(-200);
  set_aggressive(1);
  obj=clone_object("obj/money");
  obj->set_money(800);
  move_object(obj, this_object());
  obj=clone_object("obj/key");
  obj->set_key_data("marble marblekey");
  move_object(obj, this_object());
}

heart_beat() {
  if (query_attack() && random(100 < 25)) {
    tell_room(environment(this_object()), "It slams down with both fists!\n");
    query_attack()->hit_player(16);
    return 0;
  }
  ::heart_beat();
}
