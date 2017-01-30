inherit "/obj/weapon.c";
reset(arg) {
  if(arg) return;
  set_id("sword");
  set_alias("sword");
  set_short("Black Razor");
  set_long("Grimm's kickass sword.\n");
  set_class(15);
  set_weight(0);
  set_value(0);
set_hit_func(this_object());
}
weapon_hit(attacker) {
  return attacker->query_hp()-1;
}
