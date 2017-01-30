inherit "/players/catwoman/weapon/weapon";

int turn;

reset(x) {
  ::reset(x);
  if (!x) {
    turn = 1;
    set_name("Excalibur");
    set_alias("sword");
    set_short("Excalibur");
    set_class(10);
    set_value(10000);
    set_weight(3);
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
attacker->death();

  turn = 1;
  if (attacker)
    return 0;
  else return "miss";
}


