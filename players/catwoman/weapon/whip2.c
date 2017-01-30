inherit "/players/catwoman/weapon/weapon";

int turn;

reset(x) {
  ::reset(x);
  if (!x) {
    turn = 1;
    set_name("Leather whip");
    set_alias("whip");
    set_short("whip");
    set_class(999);
    set_value(10);
    set_weight(1);
    set_hit_func(this_object());
  }
}
query_save_flag() {return 1; }

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


