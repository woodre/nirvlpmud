inherit "obj/weapon";
object owner;

reset(arg) {
  if (arg) return;
        set_name("vampire blade");
        set_alt_name("blade");
        set_short("Vampire Blade");
        set_long("This is a very unique weapon.  It seems feed on blood.\n");
        set_class(18);
        set_weight(5);
        set_value(9000);
        set_hit_func(this_object());
}
weapon_hit(attacker) {
  int ex_hit;
  ex_hit = 0;
  if((environment(this_object())->query_level()>10)) {
    write("Your blood charges the blade!\n");
    ex_hit += 5;
  }
  if(attacker->query_npc()) {
    write("The blade drains the blood of your opponent!\n");
    ex_hit += 5;
  }
  return ex_hit;
}

query_save_flag() { return 0; }
