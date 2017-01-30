/*
  doppleganger.c
*/

inherit "obj/monster";

reset(arg) {
  object obj;
  if (arg) return 0;
  ::reset();

  set_name("doppleganger");
  set_level(13);
  set_alias("nooneelsedoppleganger");
  set_race("doppleganger");
  set_hp(325);
  set_al(-350);
  set_wc(17);
  set_ac(9);
  set_aggressive(0);
  obj=clone_object("obj/money");
  obj->set_money(1000);
  move_object(obj, this_object());
}

heart_beat() {
  if (query_attack() && random(100) <= 20) {
    tell_room(environment(this_object()),
              capitalize(query_attack()->query_name())+
              " seems to cast a magic missile at you.\n");
    query_attack()->hit_player(15);
  }
  ::heart_beat();
}

short() { return this_player()->short(); }

long() { this_player()->long(); }

id(str) { return str==name || str==this_player()->query_name(); }
