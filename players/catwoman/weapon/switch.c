inherit "obj/weapon";

int turn;

reset(x) {
  ::reset(x);
  if (!x) {
    turn = 1;
    set_name("knife");
    set_alias("switchblade");
    set_short("A switchblade");
    set_class(11);
    set_value(800);
    set_weight(3);
/*    set_hit_func(this_object()); */
  }
}
/*
weapon_hit(attacker) {
  object ob;
  if (!turn) return 0;
  ob = environment(this_object());
  turn = 0;
  call_other(ob,"attack");
  turn = 0;
  if (attacker)
    call_other(ob,"attack");
  turn = 1;
  if (attacker)
    return 0;
  else return "miss";
}

*/
