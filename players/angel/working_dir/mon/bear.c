/*
  bear.c
*/

inherit "obj/monster";

reset(arg) {
  object obj;

  if (arg) return 0;
  ::reset();

  set_name("bear");
  set_level(17);
  set_alias("nooneelsebear");
  set_race("bear");
  set_hp(400);
  set_al(0);
  set_short("A bear");
  set_long("A HUGE female grizzly bear!\n");
  set_wc(19);
  set_ac(7);
  set_aggressive(1);
  set_gender("female");
  obj=clone_object("obj/money");
  obj->set_money(2000);
  move_object(obj, this_object());
  obj=clone_object("players/nooneelse/obj/bear_skin");
  move_object(obj, this_object());
}

heart_beat() {
  if (query_attack() && random(100) < 25) {
    tell_room(environment(this_object()),
              "She slams down with both massive paws!\n");
    query_attack()->hit_player(15);
    return 0;
  }
  ::heart_beat();
}
