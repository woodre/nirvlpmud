inherit "obj/food";

reset(arg) {
  if(arg) return;
  set_name("birthday cake");
  set_alias("cake");
  set_alt_name("b-day cake");
  set_weight(2);
  set_value(150);
  set_strength(20);
  set_short("A birthday cake");
  set_long("A colorful b-day cake with Happy b-day Wtknight written on it.\n");
  set_eater_mess("You eat the cake, and it makes you smile.\n");
  set_eating_mess(" eats a b-day cake.\n");
}

